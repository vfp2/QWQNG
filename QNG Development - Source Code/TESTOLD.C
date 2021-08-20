/* Test program for QNG driver */

#include <stdio.h>
#include <conio.h>
#include "math.h"
#include <dos.h>
#include "graphics.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>						/* open */
#include <sys\stat.h>					/* open */
#include <io.h>

/* options and modes */
int showdist =0;
#define HANDLEIO 0

#define WORD unsigned int
#define BYTE unsigned char

FILE *ff;								/* old style file handle */
int f;									/* file handle */
char ss[201];
float n;
unsigned u;
unsigned long uu[3];
float x, sumx, sumx2, nn, mean=0., sd=0.;

main()
{
int i, ec, z;
char *ep;

/* open the device as a file */
#if HANDLEIO							/* if file handle IO */
f = open("QNG",O_RDONLY|O_BINARY);
if (f==-1) {
#else									/* if 'fopen' IO */
ff = fopen("QNG", "r+b");
if (ff != NULL)
	f = fileno(ff);						/* need file handle for IOCTL */
if (ff == NULL) {
#endif
	printf("Error- can't open QNG\n");
	return;  }
i = ioctl(f, 3, "M88\n", 4);			/* IOCTL test */
/*i = fputs("M80a8\n", ff);
printf("fputs %i\n", i);*/
/*rewind(ff);*/
/*fclose(ff);
ff = fopen("QNG", "r+b");*/
sumx = sumx2 = nn = 0.;					/* init stats accums */

/*printf("S ");
while(!kbhit()) {}
getch();*/
for (i=0; i<2200; i++) {
#if HANDLEIO
	ec = read(f,ss,8);
	if (ec <= 0) {
#else
	ep = fgets(ss,31,ff);
	if (ep == NULL) {
#endif
		perror(" file read error ");
		printf("%i %i ",errno,_doserrno);
		return;  }
	z = strlen(ss);
	if (ss[z-1] == '\n')
		ss[z-1] = '\0';					/* delete cr at end */
	printf("\n%2i %2i# %s",i, strlen(ss),ss);
	x = atof(ss);						/* accumulate stats */
	sumx = sumx + x;
	sumx2 = sumx2 + x*x;
	nn = nn +1.0;
	/*n = atof(ss);
	u = n * 65536.;
	printf("   %X",u);*/
	}
/*for (i=0; i<strlen(ss); i++) {
	printf("%c %i  ",ss[i],ss[i]);
	}*/
if (nn > 0.) {							/* calculate and show stats */
	mean = sumx / nn;
	sd = sqrt(sumx2 /nn - mean*mean);
	printf("\nMean %.3f  SD %.3f  N %.0f", mean, sd, nn);
	}
#if HANDLEIO
i = ioctl(f, 2, &uu[0], 10);			/* IOCTL test */
printf("\n%i %lu %lu %lu\n",i, uu[0], uu[1], uu[2]);
close(f);
#else
fclose(ff);
#endif

return;
}										/* end of main */
