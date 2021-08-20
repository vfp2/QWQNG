/* Test program for QNG driver */
/* tests the B2 and S1 error rates */

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
int ii[5];
int iilast;

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
i = ioctl(f, 3, "M08\n", 4);			/* IOCTL test */
sumx = sumx2 = nn = 0.;					/* init stats accums */

while (!kbhit()) {
	for (i=0; i<600; i++) {
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
		/*printf("\n%2i %2i# %s",i, strlen(ss),ss);*/
		}
	i = ioctl(f, 2, &ii[0], 10);			/* read b2, s1 */
	/*if (ii[0] > iilast)*/
		printf("\n%4i %4i %4i", ii[0], ii[1], ii[2]);
		printf("   %2i %2i# %s",i, strlen(ss),ss);
	iilast = ii[0];
	}
fclose(ff);
return;
}										/* end of main */
