/* Demo program for QNG driver */
/* Written for Borland/Turbo C */

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

int i, n;
float x;
double xx;
char *ep;
FILE *ff;                               /* old style file handle */
char ss[201];                           /* string buffer */

main()
{
ff = fopen("QNG", "r+t");               /* open the device as a file */
if (ff == NULL) {                       /* note: must be in text mode */
    perror("  Error- can't open QNG  "); /* if you want to change */
    return;  }                          /* driver modes in midstream */

printf("\nNormal distribution");        /* set to normal, take 5 values */
fputs("M88\n", ff);                     /* set mode */
fseek(ff, 0L, SEEK_SET);                /* seek is needed after write */
for (n=1; n<=6; n++) {                  /* loop to get 5 numbers */
    ep = fgets(ss, 201, ff);            /* read a string */
    if (ep == NULL) {
        perror(" file read error ");
        return;  }
    x = atof(ss);                       /* convert to float */
    printf("\n%2i  %0.6f",n, x);
    }                                   /* end of loop to get values */

printf("\nUniform distribution, high precision");   /* set mode to uniform */
fseek(ff, 0L, SEEK_SET);                /* seek is needed before write */
fputs("M0C\n", ff);                     /* set mode */
fseek(ff, 0L, SEEK_SET);                /* seek is needed after write */
for (n=1; n<=6; n++) {                  /* loop to get 5 numbers */
    ep = fgets(ss, 201, ff);
    if (ep == NULL) {
        perror(" file read error ");
        return;  }
    xx = atof(ss);                      /* convert to double */
    printf("\n%2i  %0.14lf",n, xx);
    }                                   /* end of loop to get values */

printf("\nUniform binary integers");    /* set mode to xor'd integers */
fseek(ff, 0L, SEEK_SET);                /* seek is needed before write */
fputs("M10\n", ff);                     /* set mode */
fseek(ff, 0L, SEEK_SET);                /* seek is needed after write */
for (n=1; n<=6; n++) {                  /* loop to get 5 numbers */
    ep = fgets(ss, 201, ff);
    if (ep == NULL) {
        perror(" file read error ");
        return;  }
    i = atoi(ss);                       /* convert to integer */
    printf("\n%2i  %i",n, i);
    }                                   /* end of loop to get values */

fclose(ff);                             /* close the "file" */
return;
}                                       /* end of main */
