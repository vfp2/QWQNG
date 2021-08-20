/************** PRLST -- print assembler LST files ***********/
/* uses tab size= 8 up to col 38, then =4 thereafter */
/* prints in landscape mode at 12 pitch */
/* syntax: PRLST filename (assumes .LST) */

#include <conio.h>
#include <stdio.h>
#include <string.h>

FILE *pf;								/* print file */
FILE *rf;								/* read file */
char fname[41];
char s[501], t[501];
int ss, tt;

main(int argc, char *argv[])
{
int siz;
char *ep;
if (argc <= 1) {						/* if no parameters given */
	printf("parameter choices: (lower case)\n");
	printf("por= portrait    land= landscape\n");
	printf("10= 10 pitch     16= 16 pitch\n");
	return;
	}
strcpy(fname, argv[1]);					/* get file name, add .LST */
ep = strchr(fname, '.');
if (ep == NULL)
	strcat(fname, ".LST");
rf = fopen(fname, "rt");
if (rf == NULL) {
	printf("error opening list file\n");
	return;  }
pf = fopen("LPT1","wt");
if (pf == NULL) {
	printf("error opening print file\n");
	return;  }

fprintf(pf,"\033&l1O");					/* set landscape */
fprintf(pf,"\033(8U\033(s0p12h0s0b0T");	/* 12 pitch */
/*fprintf(pf,"\033(8U\033(s0p16.67h8.5v0s0b0T");   16 pitch */

/* main loop */
while (1==1) {
	ep = fgets(s, 501, rf);
	if (ep == NULL) break;				/* if eof mostly */
	ss = tt = 0;
	while (s[ss] != '\0') {			/* walk thru source */
		if (s[ss] != '\t') {			/* if not tab */
			t[tt] = s[ss];
			tt++;
			}
		else {						/* if it is a tab */
			t[tt] = ' ';			/* always put in 1 space */
			tt++;
			if (tt >= 999) siz = 4;
			else  siz = 8;
			while ((tt % siz) != 0) {
				t[tt] = ' ';
				tt++;
				}
			}						/* end of "if it is a tab" */
		ss++;						/* move source up 1 */
		}							/* end of "walk thru source" */
	t[tt] = '\r';
	t[tt+1] = '\0';
	tt = tt+2;
	fputs(t, pf);
	}

fprintf(pf,"\033&l0O");					/* set portrait */
fprintf(pf,"\033(8U\033(s0p10.0h12.0v0s0b3T");	/* 10 pitch */
}

