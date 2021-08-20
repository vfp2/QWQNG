/************** SAW.C -- test program for QNG ********************/
/* link with sawa.asm whether or not driver is being used */
/* uses project file saw.prj */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dos.h"
#include <graphics.h>

/* options and modes */
#define DRVER 1 							/* 1= version that runs with driver */
int showdist =0;
int tailsonly =0;						/* 1=do tails only on norm */

/* functions that don't return int */
char get_data(void);
float nprob(float x);

#define WORD unsigned int               
#define BYTE unsigned char 

extern WORD far intcnt;
extern WORD far wordflag;
extern WORD far lastval;
extern WORD far last4b;
extern unsigned int far last16b;

/* setup parameters */
long nbitsu =100000;

/* variables for graphics */
int g_driver=0, g_mode=0;
float b2max =4000.;						/* display range for B2 */
int lastdot[640];						/* saved dots for erasing */
int vdiv =1;						    /* vert division factor */
int midy =240;							/* Y mid screen */
unsigned long distrib[640];

/* misc. variables */
FILE *f;
int fhandle;
int nnin =0;							/* no of nibbles in */
char ss[81];
char *ep;
int devopen =0;							/* 1= driver dev is open */

/* variables for stats routines */
struct statdat {
	int t0, t1, t2, t3;					/* original +1 / -1 values */
	int lastt0, lastt1, lastt2, lastt3;
	int llt0, llt1, llt2, llt3;
	double count;						/* n samples */
	long b2, b23, b24, b25, b27;		/* sum of 1's - sum of 0's */
	long cor1, cor2, cor3, cor4;		/* serial correlations -- accums */
	long cor5, cor6, cor7, cor8;
	}

main()
{
init();									/* set up & init */
menu();         						/* ask for command, act on it */

#if (DRVER==0)
outp(0x37A,0);  /* disable interrupt on parallel port */
unsetint();		/* before exiting, restore interrupt vector */
#else
fclose(f);
#endif
}


/****************** INIT -- initialize device ***********************/
init()
{
#if (DRVER==0)     						/* if not using driver */
outp(0x378,255); /* power on */
setint();
outp(0x37A,16);  /* enable interrupt on parallel port */
#else
f = fopen("QNG","r+b");					/* if using driver */
if (f == NULL) {
	perror("QNG driver");
	exit(1);  }
fhandle = fileno(f);
devopen =1;
#endif
}

/******************* MENU -- present menu, get response **************/
menu()
{
char c;

while(1) {
	cls();  curset(0,0);
	/*printf("\ndriver %i mode %i",g_driver, g_mode);*/
	printf("\n[0] set up parameters");
	printf("        version %i",DRVER);
	printf("\n[1] bittest");
	printf("\n[2] bitstat2");
	printf("\n[3] serial2");
	printf("\n[4] stats");
	printf("\n[5] plot");
	printf("\n[6] chi-sq");
	printf("\n[7] generate norm numbers");
	printf("\n[8] stats 2");
	printf("\n[9] show driver distrib");
	c = getch();
	if (c == '0') setup();
	if(c == '1') bittest();
	if(c == '2') bitstat2();
	if(c == '3') serial2();
	if(c == '4') stats(0);
	if(c == '5') plot();
	if(c == '6') chisq();
	if (c == '7') gennorm();
	if (c == '8') stats2(0);
	if (c == '9') sdistrib();
	/*if (c == '8') setports();*/
	if(c == 27) return(0);
	}
}

setports()
{
int v=0;
while (v < 0x100) {
	printf("value: ");
	scanf("%X",&v);
	outportb(0x378,v);
	}
}

/**************** SETUP -- allow parameter setup from keyboard *********/
setup()
{
int pno;
char c;
char ss[51];
long nn;
float x =1234567890.;

printf("\n\n PARAMETER SETTING");
printf("\n0 Send mode setting to driver");
printf("\n1 N data bits per update in stats (100,000)");
printf("\n2 Plot normal distribution (0=no)");
printf("\n3 vertical division factor for plot (1..93)");
printf("\nWhich parameter no do you want to change: ");
scanf("%i",&pno);
printf("Enter value: ");
if (pno == 0) {
	scanf("%s",ss);						/* get command str (no spaces) */
	/*if (devopen)*/
		fprintf(f,"%s",ss);				/* send out to qng */
	}
if (pno == 1)
	scanf("%li", &nbitsu);
if (pno == 2)
	scanf("%i",&showdist);
if (pno == 3)
	scanf("%i",&vdiv);
for (nn=1; nn<200000; nn++)
	x = x *.98765;
}

/*************** STATS -- collect stats on all 4 bits ***************/
/* correlations use lastt0-lastt1-lastt2-lastt3-t0-t1-t2-t3 */
/* input bits 3 4 5 7, 7 is the latest */
stats(mode)
int mode;								/* 0=print, 1=plot */
{
int i,j, limit;
unsigned u;
unsigned xorlast=0;
unsigned int itemp, oldcnt;
int sum;
struct statdat raw; 					/* raw data */
struct statdat xord;					/* 'xor' and re-use data */
struct statdat xor2;					/* 'xor' and don't re-use data */
struct statdat xorb;					/* 'xor' bit by bit, no re-use */

int state =0;
/*long cor75, cor54, cor43, cor3p;*/		/* components of cor1 */
int xpos, ypos;							/* for plotting */
long reprate;
int count1k = 1000;
float ivalue, ff;

intcnt=0;
oldcnt=0;
limit=0;
statinit(&raw);							/* init the 3 data structures */
statinit(&xorb);
/*statinit(&xord);
statinit(&xor2);*/
reprate = nbitsu/4;						/* reprate is no. of interrupts */
if (mode == 1) reprate = reprate /10L;

while(1) {
#if (DRVER == 0)
	while (intcnt==oldcnt) {}			/* wait till data ready */
	itemp = last4b >> 12;				/* get nibble from intrr routine */
#else
	/*printf("*");*/
	if (nnin == 0) {					/* if no data in, get a 16b value */
		ep = fgets(ss,81,f);			/* get 8 chars from driver */
		if (ep == NULL) {
			perror("read QNG");
			exit(1);  }
		/*if (strlen(ss) != 8) {
			printf("\nDriver str length %i %s\n",strlen(ss), ss);
			  }*/
		ff = atof(ss) ;
		itemp = ff *65536.;
		u = 0;
		/*if (u != itemp)
			printf("\nHex doesn't match %X %.7f %X\n",u, ff, itemp);*/
		nnin =4;						/* now have 4 nibbles in */
		}
	else
		itemp = itemp >> 4;				/* if data in, get next 4 bits */
	nnin--;
#endif

	statacum(&raw, itemp);				/* acum raw data */
	/*u = itemp ^ xorlast;*/
	u = (xorlast & 1) ^ ((xorlast & 6) >> 1) ^ ((xorlast & 8) >> 2);
	u = u | (itemp & 8) ^ ((itemp & 6) << 1) ^ ((itemp & 1) << 2);
	/*statacum(&xord, u);*/					/* acum xor/re-use data */
	if ((state &1) == 1)
		statacum(&xorb, u);
	xorlast = itemp;
	state++;

	limit++;

	if(limit >= reprate)
		{
		limit=0;
		if (mode == 0) {				/* if printing */
			statprint(&raw);
			statprint(&xorb);
			/*statprint(&xord);
			statprint(&xor2);*/
			printf("\n");
			}							/* end of "if printing" */
		else {							/* if plotting */
			if (raw.b2 >= b2max) ypos = 0;
			else if (raw.b2 <= -b2max) ypos = 479;
			else ypos = -(raw.b2 / b2max) * midy +midy;
			putpixel(xpos, lastdot[xpos], 0);	/* erase last */
			putpixel(xpos, ypos, YELLOW);
			lastdot[xpos] = ypos;	   	/* remember for erasing */
			if ((xpos & 3) == 0)		/* renew the center line */
				putpixel(xpos, midy, LIGHTGRAY);
			else putpixel(xpos, midy, 0);
			xpos++;
			if (xpos >= 640)
				xpos = 0;
			}							/* end of "if plotting" */
		}								/* end of "if limit >= reprate" */

	oldcnt=intcnt;

	count1k--;						/* count 1000 loops */
	if (count1k <= 0) {				/* then do low priority jobs */
		count1k = 1000;				/* check for exit */
		if(check()==27) break;
		}

	} /* end while loop */
}

/************* STATINIT -- init the data structure for 'stats' **********/
statinit(p)
struct statdat *p;
{
p->count=0.0;
p->lastt0 = p->lastt1 = p->lastt2 = p->lastt3 =0;
p->llt0 = p->llt1 = p->llt2 = p->llt3 =0;
p->b2= p->b23 = p->b24 = p->b25 = p->b27 = 0L;
p->cor1 = p->cor2 = p->cor3 = p->cor4 = 0L;
p->cor5 = p->cor6 = p->cor7 = p->cor8 = 0L;
}

/************* STATACUM -- accum stats into a structure ***************/
statacum(p, bits)
struct statdat *p;
unsigned bits;							/* 4 bits in low 4B, B3 is latest */
{
int t0, t1, t2, t3;						/* -1 or +1 */
int sum;

t3 = ((bits & 0x8) >> 2) -1;		/* bits are now in low 4b of itemp */
t2 = ((bits & 0x4) >> 1) -1;
t1 = ((bits & 0x2) ) -1;
t0 = ((bits & 0x1) << 1) -1;


sum = t3+t2+t1+t0;				/* calc the straight sum */
p->b2 += sum;
p->b23 = p->b23 + t0;
p->b24 = p->b24 + t1;
p->b25 = p->b25 + t2;
p->b27 = p->b27 + t3;

p->count+=4.0;						/* calc the serial correlations */
sum = t3*t2 +t2*t1 +t1*t0 +t0*p->lastt3;				/* 1 order */
p->cor1 = p->cor1 + sum;
sum = t3*t1 +t2*t0 +t1*p->lastt3 +t0*p->lastt2;			/* 2 order */
p->cor2 = p->cor2 + sum;
sum = t3*t0 +t2*p->lastt3 +t1*p->lastt2 +t0*p->lastt1;		/* 3 order */
p->cor3 = p->cor3 + sum;
sum = t3*p->lastt3 +t2*p->lastt2 +t1*p->lastt1 +t0*p->lastt0;	/* 4 order */
p->cor4 = p->cor4 + sum;
sum = t3*p->lastt2 +t2*p->lastt1 +t1*p->lastt0 +t0*p->llt3;		/* 5 order */
p->cor5 = p->cor5 + sum;
sum = t3*p->lastt1 +t2*p->lastt0 +t1*p->llt3 +t0*p->llt2;		/* 6 order */
p->cor6 = p->cor6 + sum;
sum = t3*p->lastt0 +t2*p->llt3 +t1*p->llt2 +t0*p->llt1;			/* 7 order */
p->cor7 = p->cor7 + sum;
sum = t3*p->llt3 +t2*p->llt2 +t1*p->llt1 +t0*p->llt0;			/* 8 order */
p->cor8 = p->cor8 + sum;

p->llt0 = p->lastt0;					/* save the last last 4 bits */
p->llt1 = p->lastt1;
p->llt2 = p->lastt2;
p->llt3 = p->lastt3;
p->lastt0 = t0;					/* save the last 4 bits */
p->lastt1 = t1;
p->lastt2 = t2;
p->lastt3 = t3;
}


/********* STATPRINT -- stow stats from a structure ****************/
statprint(p)
struct statdat *p;
{
float sumf, chisq, corr;
printf("\n");
printcoms(p->count);
/*%9.0lf*/
printf("    B2: %-7li ",p->b2/2L);
printf(" S3: %-6li", p->b23/2L);	/* print single bit sums */
printf(" S4: %-6li", p->b24/2L);
printf(" S5: %-6li", p->b25/2L);
printf(" S7: %-6li", p->b27/2L);
/* print chi-sq for bit sums */
/* note- chi-sq is 4 * sum^2 /n */
/* for "b2", factor of 2 is built in, so you don't need x4 */
/* for "b2x", count is 4x too high, so mpy result by 4 */
sumf = p->b2;
chisq = (sumf * sumf) / p->count;
printf("\nChi-sq        %7.4f",chisq);
sumf = p->b23;
chisq = (sumf * sumf *4) / p->count;
printf("     %7.4f",chisq);
sumf = p->b24;
chisq = (sumf * sumf *4) / p->count;
printf("    %7.4f",chisq);
sumf = p->b25;
chisq = (sumf * sumf *4) / p->count;
printf("    %7.4f",chisq);
sumf = p->b27;
chisq = (sumf * sumf *4) / p->count;
printf("    %7.4f",chisq);
/* print serial correlations */
corr = p->cor1 / p->count;		/* print serial correlations */
printf("\nC1 %9.6f  ", corr);
corr = p->cor2 / p->count;
printf("C2 %9.6f  ", corr);
corr = p->cor3 / p->count;
printf("C3 %9.6f  ", corr);
corr = p->cor4 / p->count;
printf("C4 %9.6f  ", corr);
corr = p->cor5 / p->count;
printf("\nC5 %9.6f  ", corr);
corr = p->cor6 / p->count;
printf("C6 %9.6f  ", corr);
corr = p->cor7 / p->count;
printf("C7 %9.6f  ", corr);
corr = p->cor8 / p->count;
printf("C8 %9.6f  ", corr);
}

/************** PRINTCOMS -- print a double-float with commas **********/
int printcoms(x)						/* returns ncols wide */
double x;
{
int i, n;
char s[41], t[41];
sprintf(s, "%.0lf", x);
n = i = strlen(s);
while (i >= 4) {
	i = i-3;
	strcpy(t, s+i);
	s[i] = ',';
	strcpy(s+i+1, t);
	n++;
	}
printf("%s", s);
return n;
}


/*************** STATS2 -- collect stats on all 4 bits ***************/
/* correlations use lastt0-lastt1-lastt2-lastt3-t0-t1-t2-t3 */
/* input bits 3 4 5 7, 7 is the latest */
stats2(mode)
int mode;								/* 0=print, 1=plot */
{
double count, countsngl;
long b2, b23, b24, b25, b27;
int i,limit;
unsigned int itemp,oldcnt;
int t0, t1, t2, t3, sum;
int lastt0, lastt1, lastt2, lastt3;
int llt0, llt1, llt2, llt3;
long cor1, cor2, cor3, cor4;			/* serial correlations -- accums */
long cor5, cor6, cor7, cor8;
long cor75, cor54, cor43, cor3p;		/* components of cor1 */
float corr, sumf, chisq;				/* temporary */
int xpos=0, ypos;						/* for plotting */
long reprate;
int count1k = 1000;

intcnt=0;
oldcnt=0;
limit=0;
count= countsngl =0.0;
cor1 = cor2 = cor3 = cor4 = 0L;
/*cor5 = cor6 = cor7 = cor8 = 0L;*/
cor75 = cor54 = cor43 = cor3p = 0L;
lastt0 = lastt1 = lastt2 = lastt3 =0;
/*llt0 = llt1 = llt2 = llt3 =0;*/
b2= b23 = b24 = b25 = b27 = 0L;
reprate = nbitsu/4;						/* reprate is no. of interrupts */
if (mode == 1) reprate = reprate /10L;

while(1) {
	if(intcnt!=oldcnt)
		{
		itemp = lastval;

		t3 = ((itemp & 0x80) >> 6) -1;
		t2 = ((itemp & 0x20) >> 4) -1;
		t1 = ((itemp & 0x10) >> 3) -1;
		t0 = ((itemp & 0x08) >> 2) -1;

		count+=4.0;						/* calc the serial correlations */
		sum = t3*t2 +t2*t1 +t1*t0 +t0*lastt3;				/* 1 order */
		cor1 = cor1 + sum;
		sum = t3*t1 +t2*t0 +t1*lastt3 +t0*lastt2;			/* 2 order */
		cor2 = cor2 + sum;
		sum = t3*t0 +t2*lastt3 +t1*lastt2 +t0*lastt1;		/* 3 order */
		cor3 = cor3 + sum;
		sum = t3*lastt3 +t2*lastt2 +t1*lastt1 +t0*lastt0;	/* 4 order */
		cor4 = cor4 + sum;
		cor75 = cor75 + t3*t2;				/* accum components */
		cor54 = cor54 + t2*t1;
		cor43 = cor43 + t1*t0;
		cor3p = cor3p + t0*lastt3;
		countsngl= countsngl+1;				/* count for components */
#if 0
		sum = t3*lastt2 +t2*lastt1 +t1*lastt0 +t0*llt3;		/* 5 order */
		cor5 = cor5 + sum;
		sum = t3*lastt1 +t2*lastt0 +t1*llt3 +t0*llt2;		/* 6 order */
		cor6 = cor6 + sum;
		sum = t3*lastt0 +t2*llt3 +t1*llt2 +t0*llt1;			/* 7 order */
		cor7 = cor7 + sum;
		sum = t3*llt3 +t2*llt2 +t1*llt1 +t0*llt0;			/* 8 order */
		cor8 = cor8 + sum;
#endif

		sum = t3+t2+t1+t0;				/* calc the straight sum */
		b2 += sum;
		b23 = b23 + t0;
		b24 = b24 + t1;
		b25 = b25 + t2;
		b27 = b27 + t3;

#if 0
		llt0 = lastt0;					/* save the last last 4 bits */
		llt1 = lastt1;
		llt2 = lastt2;
		llt3 = lastt3;
#endif
		lastt0 = t0;					/* save the last 4 bits */
		lastt1 = t1;
		lastt2 = t2;
		lastt3 = t3;

		limit++;

		if(limit >= reprate)
			{
			limit=0;
			if (mode == 0) {				/* if printing */
				printf("\n%9.0lf  B2:%7li ",count,b2/2L);
				printf(" S3:%6li", b23/2L);	/* print single bit sums */
				printf(" S4:%6li", b24/2L);
				printf(" S5:%6li", b25/2L);
				printf(" S7:%6li", b27/2L);
				/* print chi-sq for bit sums */
				/* note- chi-sq is 4 * sum^2 /n */
				/* for "b2", factor of 2 is built in, so you don't need x4 */
				/* for "b2x", count is 4x too high, so mpy result by 4 */
				sumf = b2;
				chisq = (sumf * sumf) / count;
				printf("\nChi-sq        %7.4f",chisq);
				sumf = b23;
				chisq = (sumf * sumf *4) / count;
				printf("    %7.4f",chisq);
				sumf = b24;
				chisq = (sumf * sumf *4) / count;
				printf("   %7.4f",chisq);
				sumf = b25;
				chisq = (sumf * sumf *4) / count;
				printf("   %7.4f",chisq);
				sumf = b27;
				chisq = (sumf * sumf *4) / count;
				printf("   %7.4f",chisq);
				/* print serial correlations */
				corr = cor1 / count;		/* print serial correlations */
				printf("\nC1 %f  ", corr);
				corr = cor2 / count;
				printf("C2 %f  ", corr);
				corr = cor3 / count;
				printf("C3 %f  ", corr);
				corr = cor4 / count;
				printf("C4 %f  ", corr);
				corr = cor75 / countsngl;
				printf("\nC75 %f  ", corr);
				corr = cor54 / countsngl;
				printf("C54 %f  ", corr);
				corr = cor43 / countsngl;
				printf("C43 %f  ", corr);
				corr = cor3p / countsngl;
				printf("C3P %f  ", corr);
				printf("\n");
				}							/* end of "if printing" */
			else {							/* if plotting */
				if (b2 >= b2max) ypos = 0;
				else if (b2 <= -b2max) ypos = 348;
				else ypos = -(b2 / b2max) * 175 +175;
				putpixel(xpos, lastdot[xpos], 0);	/* erase last */
				putpixel(xpos, ypos, 1);
				lastdot[xpos] = ypos;	   	/* remember for erasing */
				if ((xpos & 3) == 0)		/* renew the center line */
					putpixel(xpos, 175, 1);
				else putpixel(xpos, 175, 0);
				xpos++;
				if (xpos >= 640)
					xpos = 0;
				}							/* end of "if plotting" */
			}

		oldcnt=intcnt;

		count1k--;						/* count 1000 loops */
		if (count1k <= 0) {				/* then do low priority jobs */
			count1k = 1000;				/* check for exit */
			if(check()==27) break;
			}
		} /* endif */

	} /* end while loop */

}

/************ PLOT -- show time-axis plot of stats values **************/
/* note- display is now EGAMONO, type 5, 640 x 350 */
plot()
{
int x;
g_driver = 0;							/* autodetect */
g_mode = 0;
for (x=0; x<640; x++)					/* clear lastdot array */
	lastdot[x] = 0;
initgraph(&g_driver, &g_mode, "c:\\tc\\bgi\\");
if (g_driver < 0) {
	printf("Initgraph error %i\n",g_driver);
	  }
/*printf("graphics %i %i",g_driver,g_mode);
getche();*/
/*setcolor(LIGHTGRAY);*/
for (x=0; x<640; x=x+4)
	putpixel(x, midy, LIGHTGRAY);		/* draws the center line */
stats(1);
/*while (!kbhit()) {}
getch();*/
closegraph();
}

/* graphics */

curset(x,y) 
int x,y;
{
	union REGS r;
	r.h.ah=2; /* cursor addressing function */
	r.h.dl=y; /* column coordinate */
	r.h.dh=x; /* row coordinate */
	r.h.bh=0; /* video page */
	int86(0x10, &r, &r);
}

cls() /* graphics: */
{
	union REGS r;
	
	r.h.ah=6;/* screen scroll code */
	r.h.al=0;/* clear screen code */
	r.h.ch=0;/* start row */
	r.h.cl=0;/* start column */
	r.h.dh=24;/* end row */
	r.h.dl=79; /* end col */
	r.h.bh=7; /* blank line is black */
	int86(0x10, &r, &r);
};

check() 
{
   char cc;
   int result;
   int kbhit(void);

   result = kbhit();

   if(result!=0) {cc = getch();return(cc);}
   else return(0); 
}

#if 0
graph_test()
{
int i;
	_setvideomode(_ERESCOLOR);
	_setcolor(2);
	_moveto(0,0);
	for(i=0;i<100;i++) _lineto(i,i);
	getch();
	_setvideomode(_DEFAULTMODE);
}
#endif

/*************** CHISQ -- chi square test **************************/
chisq()
{
#define INTVL 4096
int i, b4;
int count2k = INTVL;
long diff;
unsigned itemp, oldcnt;
unsigned long hist[16], sum, np, accum, accum2;
float v;
double v2;

for (i=0; i<16; i++)
	hist[i] = 0UL;
cls();

/* main loop to get samples */
while(1) {
#if (DRVER == 0)
	while (intcnt==oldcnt) {}			/* wait till data ready */
	itemp = lastval;					/* get nibble from intrr routine */
	b4 = (((itemp & 0x80) >> 1) | (itemp & 0x38)) >> 3;
#else
	if (nnin == 0) {					/* if no data in, get a 16b value */
		ep = fgets(ss,81,f);			/* get 8 chars from driver */
		if (ep == NULL) {
			perror("read QNG");
			exit(1);  }
		if (strlen(ss) != 8) {
			printf("Driver str length %i\n",strlen(ss));
			exit(1);  }
		itemp = atof(ss) *65536. +.5;
		nnin =4;						/* now have 4 nibbles in */
		}
	b4 = itemp & 0xF;
	itemp = itemp >> 4;
	nnin--;
#endif

	hist[b4]++;						/* update histogram */
	oldcnt=intcnt;					/* clear "ready" flag */

	count2k--;						/* count 1000 loops */
	if (count2k <= 0) {				/* then do low priority jobs */
		count2k = INTVL;				/* check for exit */
		if(check()==27) break;

		gotoxy(1,1);				/* repaint all values */
		sum = 0L;
		for (i=0; i<16; i++)
			sum = sum + hist[i];
		np = sum / 16UL;			/* calculate chi-sq sum */
		for (i=0; i<16; i++) {
			diff = hist[i];
			diff = diff -np;
			printf("%2i  %10lu  %li    \n", i, hist[i], diff);
			}
		printf("\nTOTAL %10lu",sum);
		accum = accum2 = 0UL;
		for (i=0; i<16; i++) {		/* accum loop */
			accum = accum + (hist[i] - np) * (hist[i] - np);
			accum2 = accum2 + hist[i] * hist[i];
			}						/* end of accum loop */
		v = accum;
		v = v / np;
		printf("\nV     %10.3f", v);
		}							/* end of "if count2k==0" */
	}									/* end of "while" loop */
}


/********** GENNORM -- generate normalized number stream **************/
gennorm()
{
int count1k =1000;
int countmm =100;
int oldcnt;
long z;									/* uniform dist. number */
float u1, u2;							/* uniform number, 0..1 */
float x0, x1, x2;						/* results */
double nn;
double mean1, mean2, sd1, sd2;
double sumx1, sumx2;
double sumsq1, sumsq2;
int ix, iy;

oldcnt = wordflag =0;
cls();
sumx1 = sumx2 = nn = 0.;
sumsq1 = sumsq2 = 0.;
if (showdist != 0)
	gsetup();
/* main loop to get samples (in pairs) */
while(1) {
	while (wordflag == oldcnt) {}	/* get word 1 */
	oldcnt = wordflag;
	z = last16b;					/* convert to long */
	z = (z << 1) + 1;				/* add 1/2 lsb bias */
	u1 = (float)z / 131072.0;		/* convert to float, 0..1 */

	while (wordflag == oldcnt) {}	/* get word 2 */
	oldcnt = wordflag;
	z = last16b;					/* convert to long */
	z = (z << 1) + 1;				/* add 1/2 lsb bias */
	u2 = (float)z / 131072.0;		/* convert to float, 0..1 */
	/*printf("\n%f %f",u1, u2);*/

/* compute normalized values */
	x0 = sqrt(-2.0 * log(u1));
	x1 = x0 * cos(6.283185307 * u2);
	x2 = x0 * sin(6.283185307 * u2);
	/*printf("\n%f %f",x1, x2);*/
	sumx1 = sumx1 + x1;
	sumx2 = sumx2 + x2;
	sumsq1 = sumsq1 + (double)x1 * (double)x1;
	sumsq2 = sumsq2 + (double)x2 * (double)x2;
	nn = nn +1.0;

/* if graphing, plot the point */
	if (showdist != 0) {
		ix = x1 * 50. + 320;
		if (ix <0) ix = 0;
		if (ix >= 640) ix = 639;
		lastdot[ix]++;
		iy = 348 - lastdot[ix] /vdiv;
		putpixel(ix, iy, 1);
		}

/* every 1 sec, show means & var's */
	countmm--;
	if ((countmm <= 0) && (showdist == 0)) {
		countmm = 1000;
		mean1 = sumx1 / nn;
		mean2 = sumx2 / nn;
		sd1 = sumsq1 /nn - mean1 * mean1;
		sd2 = sumsq2 /nn - mean2 * mean2;
		printf("\nmean1=%8lf  var=%8lf",mean1, sd1);
		printf("    mean2=%8lf  var=%8lf",mean2, sd2);
		printf("   n= %.0lf",nn);
		}

/* see if it's time to test for exit */
	count1k--;						/* count 1000 loops */
	if (count1k <= 0) {				/* then do low priority jobs */
		count1k = 100;				/* check for exit */
		if(check()==27) break;
		}
	}									/* end of main loop */
if (showdist != 0)
	closegraph();
}

/************* GSETUP -- set up for graphics **********************/
gsetup()
{
int x;
g_driver = 0;							/* autodetect */
g_mode = 0;
for (x=0; x<640; x++) {					/* clear lastdot array */
	lastdot[x] = 0;
	distrib[x] = 0L;  }
initgraph(&g_driver, &g_mode, "c:\\tc\\bgi\\");
if (g_driver < 0) {
	printf("Initgraph error %i\n",g_driver);
	}
}

/*************** BITTEST -- show actual bits **************************/
bittest()
{
unsigned int itemp,oldcnt;
unsigned char n,m,p,q,ctemp[8];

	intcnt=0;
	oldcnt=0;

	while(1)
	{
		if(intcnt!=oldcnt)
		{
			if(check()==27) break;
/*                      itemp = ((inp(0x379
) >> 3) & 0x0f); */
			itemp = inp(0x379);

			ctemp[0]='0';
			ctemp[1]='0';
			ctemp[2]='0';
			ctemp[3]='0';
			ctemp[4]=0;

			n = (itemp & 0x80) >> 7;
			m = (itemp & 0x20) >> 5;
	 p = (itemp & 0x10) >> 4;
			q = (itemp & 0x08) >> 3;

			if(n) ctemp[0]='1';
			if(m) ctemp[1]='1';
			if(p) ctemp[2]='1';
			if(q) ctemp[3]='1';

			printf("\n%s",ctemp);

			oldcnt=intcnt;
		}
	}
}

/*********************** BITSTAT2 *********************************/
bitstat2()
{
double count,b1;
int i,limit,sum;
unsigned int itemp,oldcnt;
unsigned int n,m,p,q;

intcnt=0;
oldcnt=0;
limit=0;
count=0.0;
b1=0.0;

while(1)
{
	if(intcnt!=oldcnt)
	{
			if(check()==27) goto ex1;
			/*itemp = inp(0x379);*/
			itemp = lastval;

			n = (itemp & 0x80) >> 7;
			m = (itemp & 0x20) >> 5;
	 p = (itemp & 0x10) >> 4;
			q = (itemp & 0x08) >> 3;

			count+=4.0;
			b1 += (double) (n+m+p+q);

			limit++;

			if(limit>=5000) 
			{
				limit=0;
				printf("\nCOUNT:%8.0f  VAL:%8.0f  ",count,b1-(count/2.0));
			}

			oldcnt=intcnt;

	} /* endif */

} /* end while loop */

ex1:;
}


/************************** SERIAL2 ********************************/
serial2()
{
double count,b1;
int i,limit;
unsigned int itemp,oldcnt;
int n,m,p,q,lastn,sum;

intcnt=0;
oldcnt=0;
limit=0;
count=0.0;
b1=0.0;
lastn=0;

while(1)
{
	if(intcnt!=oldcnt)
	{
			if(check()==27) goto ex1;
			itemp = inp(0x379);

			n = (itemp & 0x80) >> 6; n-=1;
			m = (itemp & 0x20) >> 4; m-=1;
	 p = (itemp & 0x10) >> 3; p-=1;
			q = (itemp & 0x08) >> 2; q-=1;

			count+=4.0;
			sum = n*m+m*p+p*q+lastn*q;
			b1 += (double) sum;
			lastn=n;

			limit++;

			if(limit>=5000) 
			{
				limit=0;
				printf("\nCOUNT:%8.0f  VAL:%f  ",count,b1/count);
			}

			oldcnt=intcnt;

	} /* endif */

} /* end while loop */

ex1:;


}

/*********** Unused code *************/
#if 0
/* calculate the chi-sq for 13 groups of 1/2 SD, 0..6.5 */
		ff = 0.;
		ix = 639;
		for (nb=0; nb<13; nb++) {		/* loop to do 1 group of 0.5 */
			printf("\n%6.1f ", ff);
			bin_n[nb] = 0;
			dtemp = 0.;
			fy = (nprob(ff) - nprob(ff-.5)) *2;
			for (t=0; t<5; t++) {		/* loop to do 1 subgroup of 0.1 */
				ltemp = 0;				/* sum the counts in the subgroup */
				for (i=0; i<9; i++) {		/* loop to do 1 bin */
					ltemp = ltemp + distrib[ix];
					ix--;
					}
				fx = (nprob(ff) - nprob(ff-.1)) *2;
				ff = ff - 0.1;
				dtemp = dtemp + (double)ltemp * (double)ltemp *fy/fx;
				bin_n[nb] = bin_n[nb] + ltemp;
				}						/* end of loop to do 1 subgroup */
			if (bin_n[nb] > 0)
				dtemp = dtemp / bin_n[nb] - bin_n[nb];
			printf(" %8.4lf", dtemp);
			printf(" n=%lu", bin_n[nb]);	/* show count */
			}							/* end of loop to do 1 group */
#endif

/************** SDISTRIB -- show distribution coming from driver **********/
sdistrib()
{
#if DRVER
float ndots_sd =90.;					/* Horiz: n dots per unit of SD */
int nt =8;								/* n ticks to draw */
int ftick =639;							/* loc of first tick (pixel#) */
int ptick =-90;							/* pixels between ticks */
int ulim;
int i, ix, ixx, iy, iiy, nb, t;
int refresh=0;							/* refresh counter for test info */
int scale =3;							/* n bits R shift */
char ch, ch2;
unsigned long count =0UL;
unsigned long uu[2];
unsigned long ltemp;
long tl;
float ff, fx, fs, fy;
double sumx=0., sumx2=0., sumx4=0.;
double m, sd, kurt;
double dtemp, ptotal;
float xstart=0., xstop =0.;
float bin_chisq[13];
unsigned long bin_n[13];
double zn, zsx, zsx2;
gsetup();								/* set up to graph */
if (tailsonly)
	ioctl(fhandle, 3, "MB8\n", 4);		/* set tails-only mode &unsigned */
ioctl(fhandle, 3, "M88\n", 4);		/* set lo precision mode */

paint: {}
cleardevice();
ix = ftick;
for (i=0; i<nt; i++) {					/* draw ticks */
	ixx = ix;
	if (ixx <0) ixx = 0;
	for (iy=440; iy>=0; iy--)
		putpixel(ixx, iy, LIGHTGRAY);
	ix = ix + ptick;
	}
for (ix=0; ix<640; ix++) {				/* loop to repaint the low- size bins */
	iy = (distrib[ix] /vdiv) >>scale;
	if ((iy ==0) && (distrib[ix] != 0))
		iy = 1;
	if ((iy != 0) && (iy < 60)) {		/* is it low-size */
		/*for (i=1; i<=iy; i++)*/ 			/* repaint vertical line */
			putpixel(ix, 479-iy, YELLOW);
		}								/* end of "is it low-size" */
	}									/* end of loop to repaint */

while (devopen) {
	ep = fgets(ss,81,f);			/* get 8 chars from driver */
	if (ep == NULL) {
		perror("read QNG");
		exit(1);  }
	ff = strtod(ss,&ep) ;
/* maintain statistics */
	count++;
	sumx = sumx + ff;
	m = ff * ff;
	sumx2 = sumx2 + m;
	sumx4 = sumx4 + m *m;
/* if graphing, plot the point */
	ff = fabs(ff);					/* use -7 to 0 */
	ix = ff * ndots_sd;
	ix = 639 - ix ;
	if (ix < 9)							/* bin 9 will be for any value */
		ix = 9;							/* 7.0 and farther out */
	if (ix >= 640) ix = 639;
	distrib[ix]++;
	iy = (distrib[ix] /vdiv) >>scale;
	if ((iy ==0) && (distrib[ix] != 0))
		iy = 1;
	iy = 479 - iy;
	putpixel(ix, iy, YELLOW);
/* do the refresh printing on screen */
	refresh++;							/* check the refresh counter */
	if (refresh >= 20000) {
		gotoxy(1,1);
		printcoms((double)count);
		m = sumx / (double)count;
		printf("\nMean %.6lf",m);
		sd = sqrt(sumx2 / (double)count - m*m);
		printf("\nSD %.6lf", sd);
		kurt = (double)count * sumx4 / (sumx2 * sumx2);
		printf("\nK %.5lf", kurt);
		tl = (long)vdiv << scale;
		printf("\ndiv %li", tl);
		ioctl(fhandle, 2, &uu[0], 8);	/* get ucount, ncount */
		dtemp = (double)uu[0] / (double)uu[1];
		printf("\nratio %7.4lf", dtemp);
		/*if (xstart != 0.) {
			printf("\n%.1f to %.1f", xstart, xstop);
			nb = fabs(xstop - xstart) *ndots_sd +.5;
			printf("  %i bins", nb);
			}*/
		refresh =0;
		}
	if (kbhit()) break;
	}
ch = getch();
if (ch == '\0')	{
	ch2 = getch();
	if (ch2 == 0x49) {					/* PgUp, larger pic */
		if (scale > 0)
			scale--;
		goto paint;
		}
	if (ch2 == 0x51) {					/* PgDn, smaller pic */
		if (scale < 17)
			scale++;
		goto paint;
		}
	}									/* end of "if ch==0" */
if (ch == '|') {						/* do chi sq test on normals */
	printf("\n\nRange (multiple of 1/10 SD) beginning: ");
	scanf("%f", &xstart);
	printf("End: ");
	scanf("%f", &xstop);
	if (xstop < xstart) {
		fx = xstop;
		xstop = xstart;
		xstart = fx;  }
	goto paint;
	}
if (ch == '/') {						/* show comparison curve to normal */
	cleardevice();
	fx = -7.0;							/* SD at left of group */
	zn = zsx = zsx2 =0.;
	ulim = 640;
	if (tailsonly) ulim = 280;
	iiy = 1;
	for (ix=1; ix<ulim; ix=ix+9) {		/* loop to do 1 1/10 SD group */
		putpixel(ix, 80, LIGHTGRAY);	/* note: bin 9 is catchall (>= 7.0) */
		putpixel(ix, 160, LIGHTGRAY);	/* bin 10 is first data bin (6.9-7) */
		putpixel(ix, 240, LIGHTGRAY);
		if (ix >= 10)
			putpixel(ix+2, 240, LIGHTGRAY);
		putpixel(ix, 320, LIGHTGRAY);
		putpixel(ix, 400, LIGHTGRAY);
		if (ix >= 10)
			ff = (nprob(fx+.1) - nprob(fx)) *2;	/* prob of being in group */
		else ff = nprob(fx);			/* for bin 9: prob from -inf to -7 */
		if (tailsonly)
			ff = ff *15787.19277;
		ltemp = 0L;
		for (i=0; i<9; i++) 			/* sum the counts in group */
			ltemp = ltemp + distrib[ix+i];
		ptotal = ff * (double)count;	/* expected value for this group */
		dtemp = ((double)ltemp - ptotal) / sqrt(ptotal);	/* actual Z */
		if (tailsonly && (fx >= -7.0)) {
			gotoxy(50, iiy);
			printf("%5.1f", fx);
			if (ptotal >= 100.)
				printf(" %6.0lf", ptotal);
			else if (ptotal >= 10.)
				printf(" %6.1lf", ptotal);
			else printf(" %6.2lf", ptotal);
			printf(" %6li",ltemp);
			printf(" %.2lf",dtemp);
			   iiy++;
			}
		zsx = zsx + dtemp;
		zsx2 = zsx2 + dtemp*dtemp;
		zn=zn+1.;
		dtemp = dtemp * 80.;			/* 80 dots per SD vertically */
		if (dtemp > 239.) dtemp = 239.;
		if (dtemp < -239.) dtemp = -239.;
		iy = 240 - dtemp;
		putpixel(ix, iy, YELLOW);
		if (ix >= 10)					/* for normal bins, incr fx */
			fx = fx + .1;
		}								/* end of loop to do 1/10 Sd group */
	gotoxy(50, iiy);
	zsx = zsx / zn;
	zsx2 = sqrt(zsx2 / zn - zsx*zsx);
	printf("Mean %.3lf  SD %.3lf  N %.0lf", zsx, zsx2, zn);
	/*printf("%.2f", fx);*/
	getch();
	goto paint;
	}									/* end of "show comparison curve" */
closegraph();
#endif
}

/************* NPROB -- find probability under normal curve **************/
/* measured from -infinity to X (given) */
/* arguments should always be negative */
/* to find probability of being in a range, */
/*		subtract p(farther from 0) from p(closer to 0) */
float nprob(float x)
{
float y;
y = 9.002853043E-7 *x + .00003419972886; /* c7, c6 */
y = y * x + .0005688556574;				/* c5 */
y = y * x + .00556031242;				/* c4 */
y = y * x + .03664227709;				/* c3 */
y = y * x - .3185861602;				/* c2 */
y = y * x + .7976896263;				/* c1 */
return 0.5 * exp(y * x);
}

