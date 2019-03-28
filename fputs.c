#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("AAA.txt", "w");
    if ( fp == NULL ) return 0; /*INT(BR USPJESNO UPISANIH ZNAKOVA) FPUTS(CONST CHAR*S, FILE *FP) */

    fputs("Alo\n", fp);
    fputs("sta ima\n",fp);
    fclose(fp);

    return 0;
}
