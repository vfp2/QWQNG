/************* QNG INSTALL PROGRAM **********************************/
/* Build: link with ITEST.ASM  (use 'install.lnk') */

#include <conio.h>						/* console i/o */
#include <stdio.h>						/* file i/o */
#include <string.h>
#include <stdlib.h>
#include <alloc.h>						/* malloc, realloc */
#include <ctype.h>						/* isdigit, etc */
#include <math.h>						/* atof */
#include <dos.h>						/* getdate, int86 */
#include <dir.h>						/* findfirst, getdisk, etc */
#include <io.h>							/* getftime */
#include <fcntl.h>						/* file handle i/o */
#include <sys\stat.h>
#define TRUE 1
#define FALSE 0

/* options and modes */

/* Variables for screen geometry */
int xcor=16;							/* x, y of U.L. corner of boxes */
int ycor=6;
int xwide=48;							/* width & height of boxes */
int yhigh=13;
int xcopname=18;						/* x, y for filenames copied */
int ycopname=17;
int ncopname=43;						/* nchars wide */

/* variables for file searching & deleting */
int wkdrive;							/* working drive (A=0, etc) */
char subdir[61];						/* path to dest subdirec */
char roota[61];							/* root for source (drive & direc) */
char rootb[61];							/* root for dest */
char devb[11] ="C:";					/* device for dest */
char dname[31];							/* name of qngdrv used */
char from[61];
char to[61];
char file1[91];							/* full pathnames of compare-files */
char file2[91];
char ch;
struct ftime timdat;					/* time/date of file */
#define BUFSIZE 30000					/* for copying */
char *buff;
char tmp[301];
char tmpu[301];
FILE *cfile;							/* files for modifying CONFIG.SYS */
FILE *dfile;

/* general variables */
union REGS regs;						/* for int86 */
unsigned dosrev;						/* Rev or DOS that's running */
int cputype;							/* CPU type =0 or 3 */

/* functions */

main(int argc, char *argv[])
{
int ec, i, j, n, ss;
int ssi, ssj;
char *sp, *ep;

ec = argc;								/* stops compiler warning */
/* allocate space for copy buffer */
buff = malloc(BUFSIZE);
if (buff == NULL) {
	printf("Error- can't allocate RAM space\n");
	return;  }

/* what DOS revision is running? */
regs.x.ax = 0x3000;
int86(0x21, &regs, &regs);
dosrev = regs.x.ax;						/* Lo=major, Hi=minor */

/* what CPU are we using? */
cputype = findcpu();            		/* assembly module */
/*printf("%i %i %i\n",dosrev&0xFF, dosrev>>8, cputype);
return;*/

/* ask what directory they want to use for QNG software */
box(xcor, ycor, xwide, yhigh);
gotoxy(xcor+11, ycor+2);
printf("QNG software installation");
gotoxy(xcor+5, ycor+4);
printf("What subdirectory do you want to use");
gotoxy(xcor+12, ycor+5);
printf("for the QNG software?");
getresp(xcor+7, ycor+8, 31, subdir, "\\QNGDRV");
if (subdir[0] != '\\') {				/* subdir must start w \ */
	strcpy(tmp,subdir);					/* so stick one in */
	strcpy(subdir,"\\");
	strcat(subdir,tmp);
	}

/* create the destination dir if not there */
strcpy(tmp, devb);
strcat(tmp, subdir);
ec = mkdir(tmp);
if (ec < 0) {							/* if error */
	if (errno != 5) {					/* err 5 is ok (already exist) */
		printf("\nError- cannot create directory\n");
		abort();
		}
	}

/* figure out what drives to use for source & destination */
wkdrive = getdisk();					/* what is working drive (A=0) */
if (wkdrive <= 1) {						/* if working on A or B */
	strcpy(roota,"");  					/* from: working dr */
	strcpy(rootb, devb);				/* to: C: */
	strcat(rootb,subdir);
	strcat(rootb,"\\");
	}
else {									/* if working drive is HD */
	strcpy(roota, "");					/* we have to find out source dr */
	if ((dosrev & 0xFF) >= 3) {			/* if DOS >= 3, look @ command */
		strcpy(tmp, argv[0]);
		strupr(tmp);
		if (strncmp(tmp, "A:", 2) == 0)	/* is it A:install */
			strcpy(roota, "A:");
		if (strncmp(tmp, "B:", 2) == 0)	/* is it A:install */
			strcpy(roota, "B:");
		}								/* end of "if DOS >= 3" */
	if (strlen(roota) == 0) {			/* if source dev still not found */
		box(xcor, ycor, xwide, yhigh);
		gotoxy(xcor+11, ycor+2);
		printf("QNG software installation");
		gotoxy(xcor+9, ycor+4);
		printf("What source drive are you using");
		gotoxy(xcor+12, ycor+5);
		printf("for the QNG software?");
		getresp(xcor+20, ycor+8, 3, roota, "A:");
		if (strlen(roota) < 2)
			strcat(roota, ":");
		}
	strcpy(rootb, subdir);				/* "to" is "subdir" on curr drive */
	strcat(rootb, "\\");
	}									/* end of "if working dr is HD" */

/* now do the actual file copying */
ec = icopy("read.me");
if (ec != 0) abort();
ec = icopy("qngdrv0.exe");
if (ec != 0) abort();
ec = icopy("qngdrv3.exe");
if (ec != 0) abort();
ec = icopy("qngdrv0.com");
if (ec != 0) abort();
ec = icopy("install.exe");
if (ec != 0) abort();

/* figure out which version of driver to use, copy it to root */
strcpy(dname, "QNGDRV");
if ((dosrev & 0xFF) >= 5) {				/* if DOS 5, use EXE */
	if (cputype == 3)					/* which CPU type */
		strcat(dname, "3");				/* if 386 */
	else strcat(dname, "0");			/* if 86 */
	strcat(dname, ".EXE");				/* depending on DOS rev */
	}
else strcat(dname, "0.COM");			/* old DOS: always 0.COM */
strcpy(roota, rootb);					/* now working from rootb */
strcpy(rootb, devb);
strcat(rootb, "\\");					/* to root dir */
ec = icopy(dname);
if (ec != 0) abort();

/* Ask if they want the CONFIG.SYS file modified */
box(xcor, ycor, xwide, yhigh);
gotoxy(xcor+11, ycor+2);
printf("QNG software installation");
gotoxy(xcor+4, ycor+4);
printf("Do you want to have the CONFIG.SYS file");
gotoxy(xcor+12, ycor+5);
printf("modified automatically?");
getresp(xcor+20, ycor+8, 2, tmp, "Y");
strupr(tmp);

/* do the modification of CONFIG.SYS */
/* read thru the file first, looking for similar line */
/* add the new line at the end */
/* make a copy of CONFIG.SYS, then rename this to ".BAK" */
if (tmp[0] == 'Y') {
	cfile = fopen("C:\\CONFIG.SYS","rt");
	dfile = fopen("C:\\CONFIG.~-~","wt");
	if (cfile == NULL) {
		printf("\nError- Can't find C:CONFIG.SYS\n");
		abort();  }
	if (dfile == NULL) {
		printf("\nError- Can't open temporary CONFIG file\n");
		abort();  }
	while (1==1) {						/* loop to read lines */
		ep = fgets(tmp, 401, cfile);	/* read a line */
		if (ep == NULL) break;
		gotoxy(xcor+2, ycor+10);		/* clear old line */
		for (i=0; i<44; i++)
			printf(" ");
		gotoxy(xcor+2, ycor+10);
		printf("%s", tmp);
		strcpy(tmpu, tmp);				/* make a copy to fool with */
		strupr(tmpu);					/* make it upper case */
		if (strncmp(tmpu, "DEVICE=QNGDRV", 13) == 0) {
			gotoxy(xcor+2, ycor+11);	/* if this is a QNGDRV line */
			for (i=0; i<20; i++)
				printf(" ");
			gotoxy(xcor+2, ycor+11);
			printf("deleted");
			}							/* end of "if strncmp()" */
		else {							/* if not a QNGDRV line, copy it */
			fputs(tmp, dfile);
			}
		/*getch();*/					/*!!*/
		}								/* end of loop to read lines */
	strcpy(tmp, "DEVICE=");
	strcat(tmp, dname);
	strcat(tmp, "\n");
	fputs(tmp, dfile);
	fclose(cfile);
	fclose(dfile);
	unlink("C:\\CONFIG.BAK");
	rename("C:\\CONFIG.SYS", "C:\\CONFIG.BAK");
	rename("C:\\CONFIG.~-~", "C:\\CONFIG.SYS");
	}
else {									/* if they don't want to modify file */
	box(xcor, ycor, xwide, yhigh);
	gotoxy(xcor+11, ycor+2);
	printf("QNG software installation");
	gotoxy(xcor+3, ycor+4);
	printf("You must insert a line into the CONFIG.SYS");
	gotoxy(xcor+8, ycor+5);
	printf("file which loads the QNG driver");
	gotoxy(xcor+9, ycor+6);
	printf("Example: DEVICE=QNGDRV3.EXE");
	gotoxy(xcor+12, ycor+8);
	printf("Hit any key to continue");
	ch = getch();
	if (ch == 0) getch();
	}

/* All done- Show ending message */
box(xcor, ycor, xwide, yhigh);
gotoxy(xcor+11, ycor+2);
printf("QNG software installation");
gotoxy(xcor+5, ycor+4);
printf("QNG software installation is complete");
gotoxy(xcor+12, ycor+7);
printf("Hit any key to continue");
ch = getch();
if (ch == 0) getch();

clrscr();
/*printf("%s  %s  %s\n", roota, rootb, argv[0]);
printf("%X %X\n", dosrev&0xff, dosrev>>8);
printf("%i\n", cputype);*/
}										/* end of "main" */

/************ ICOPY -- copy a file, show name on screen *************/
/* use roota, rootb; file name supplied */
int icopy(name)
char *name;
{
int ec, i;
char from[61];
char to[61];
strcpy(from, roota);
strcat(from, name);
strcpy(to, rootb);
strcat(to, name);
gotoxy(xcopname, ycopname);
for (i=0; i<ncopname; i++)				/* clear the field */
	cprintf(" ");
gotoxy(xcopname, ycopname);
cprintf("%s >> %s", from, to);
ec = fcopy(from, to);
/*getch();*/						/*!!*/
return ec;
}

/************* GETRESP -- get a response string from user ************/
getresp(xpos, ypos, width, str, defstr)
int xpos, ypos;							/* where to put the field */
int width;     							/* will get up to this many */
char *str;								/* response str */
char *defstr;							/* default str, to start out w */
{
int ch, x, nchars=0, curs=0;
int len;
int clearf;								/* if >0 clear field before repainting */
int insmode =0;							/* insert mode */
gotoxy(xpos, ypos);
textbackground(LIGHTGRAY);
textcolor(BLACK);
for (x=0; x<width; x++)
	cprintf(" ");
gotoxy(xpos, ypos);
strcpy(str, defstr);       				/* initial paint of default str */
cprintf("%s",str);
curs = strlen(str);
while (1==1) {							/* loop to get chars & edit */
	len = strlen(str);                  /* want curr str length */
	clearf =0;
	ch = getch();
	if (ch == 0)
		ch = 0x100 + getch();
	if (ch == 0x14B) {					/* left arrow */
		if (curs > 0)
			curs--;
		}
	if (ch == 0x14D) {					/* right arrow */
		if (curs < len)
			curs++;
		}
	if (ch == 0x147) {					/* Home */
		curs = 0;  }
	if (ch == 0x14F) {
		curs = len;  }
	if (ch == 0x152) { 					/* insert */
		insmode = !insmode;
		if (insmode)
			_setcursortype(_SOLIDCURSOR);
		else _setcursortype(_NORMALCURSOR);
		}
	if (ch == 8) {						/* backspace */
		if (curs > 0) {
			curs--;
			for (x=curs; x < len; x++)
				str[x] = str[x+1];		/* shuffle back */
			clearf++;					/* clear field (shortening it) */
			}
		}
	if (ch ==0x153) {					/* delete */
		if (curs < len) {
			for (x=curs; x < len; x++)
				str[x] = str[x+1];		/* shuffle back */
			clearf++;					/* clear field (shortening it) */
			}
		}
	if ((ch > ' ') && (ch <= '~')) {	/* if printing char */
		if (nchars == 0) {				/* if first char */
			str[0] = '\0';				/* clear entire string */
			curs = 0;
			clearf++;
			}
		if ((insmode) || (curs >= strlen(str))) {	/* if adding at end */
			if (strlen(str) < width) {				/* is there room */
				for (x=strlen(str); x>=curs; x--)		/* or if ins mode */
					str[x+1] = str[x];		/* shuffle up to make space */
				str[curs] = ch;
				curs++;
				}
			}
		else {							/* if typeover mode */
			str[curs] = ch;
			curs++;
			}
		}
	if ((ch == '\r') || (ch == '\n')) {	/* enter- quit */
		break;  }
	gotoxy(xpos, ypos);					/* repaint after every op */
	if (clearf > 0) {					/* may want to clear first */
		for (x=0; x<len; x++)			/* if str got shorter */
			cprintf(" ");
		gotoxy(xpos, ypos);
		}
	cprintf("%s",str);
	gotoxy(xpos+curs, ypos);
	nchars++;							/* count n chars hit */
	}
textbackground(BLACK);
textcolor(LIGHTGRAY);
}

/************* BOX -- draw a box in center of screen, clear inside *****/
box(xcor, ycor, xwide, yhigh)
int xcor, ycor, xwide, yhigh;
{
int x, y;
unsigned char bord=219;
clrscr();								/* clear screen first */
gotoxy(xcor, ycor);						/* do top row */
for (x=0; x<xwide; x++)
	fputc(bord, stdout);
for (y=1; y<(yhigh-1); y++) {			/* do intermed rows */
	gotoxy(xcor, ycor+y);
	fputc(bord, stdout);
	gotoxy(xcor+xwide-1, ycor+y);
	fputc(bord, stdout);
	}
gotoxy(xcor, ycor+yhigh-1);				/* do bottom row */
for (x=0; x<xwide; x++)
	fputc(bord, stdout);
}

/*********** DATESTR -- make a string out of a date *********************/
datestr(date, ss)
int date;
char *ss;       						/* pointer to result string */
{
sprintf(ss,"%i/%i/%2i",(date >> 5) & 0xF, date & 0x1F, \
	((date >> 9) & 0x7F) + 80);
while (strlen(ss) < 8)
	strcat(ss, " ");
}

/********* FCR -- file compare routine ************************************/
/* call this only if you already know the files are the same length */
/* provide complete pathnames for files (with device if nec.) */
/* returns 0 if not= (or if some problem), 1 if = */
int fcr(file1, file2)
char *file1, *file2;
{
int r =0;								/* return value */
char c1, c2;
FILE *f1;
FILE *f2;
f1 = fopen(file1, "rb");
f2 = fopen(file2, "rb");
if ((f1 == NULL) || (f2 == NULL)) {
	printf("error- can't open file\n");
	return 0;  }
while (!feof(f1)) {						/* loop to compare files */
	c1 = fgetc(f1);
	c2 = fgetc(f2);
	if (c1 != c2) break;
	}
if (feof(f1))  r = 1;					/* if you made it thru */
fclose(f1);
fclose(f2);
return r;
}

/********* FCOPY -- file copy routine ************************************/
/* provide complete pathnames for files (with device if nec.) */
/* sets date of destination file to date of source file */
/* returns 0 if ok, nonzero if some problem (message printed) */
int fcopy(file1, file2)
char *file1, *file2;
{
int f1, f2, i;
unsigned n;
long sz;
f1 = open(file1, O_RDONLY | O_BINARY);
if (f1 < 0) {
	printf("\nerror opening source file %s\n", file1);
	return 1;  }
f2 = open(file2, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC,0x180);
if (f2 < 0) {
	printf("\nerror opening destination file %s\n", file2);
	close(f1);
	return 1;  }
sz = filelength(f1);
while (sz > 0L) {						/* loop to transfer 1 buffer full */
	n = BUFSIZE;
	if (sz < n) n = sz;
	i = read(f1, buff, n);
	if (i <= 0) {
		printf("\nread error\n");
		return 2;  }
	i = write(f2, buff,n);
	if ((i == -1) || (i < n)) {
		printf("\nwrite error\n");
		return 2;  }
	sz = sz - n;
	}
getftime(f1,&timdat);					/* make date/time of dest file */
/*printf("%u %u\n",timdat.ft_month,timdat.ft_day);*/
i = setftime(f2,&timdat);				/* the same as source file */
/*printf("%i\n",i);*/
close(f1);
close(f2);
return 0;
}
