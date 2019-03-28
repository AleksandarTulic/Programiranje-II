#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("AAA.txt", "w");
    if ( fp == NULL ) return 0;

    int b = 65;

    while (b <= 200)
    {
        if ( b % 10 == 0 ) fputc('\n', fp); /* ISPISUJE VRIJEDNOST BROJA I KAO ZNAKA FPUTC(INT ZNAK, FILE *FP) */
        fputc(b,fp);
        b++;
    }
    fclose(fp);
    return 0;
}
