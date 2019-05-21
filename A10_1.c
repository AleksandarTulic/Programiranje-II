#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#define MAX 10000

typedef struct stek{
    char niz[MAX][20];
    int tos;
}STEK;

int isFULL(STEK *s)
{
    return s->tos == MAX - 1;
}

int isEMPTY(STEK *s)
{
    return s->tos == -1;
}

void push(STEK *s, char r[])
{
    if ( isFULL(s) ) return;

    int i = 0;++s->tos;
    while ( r[i] )
    {
        s->niz[s->tos][i] = r[i];i++;
    }
}

void print(STEK *s, FILE *fp)
{
    while ( !isEMPTY(s) ) fprintf(fp, "%s\n", s->niz[s->tos--]);

    fclose(fp);
}

int main(int br, char *a[])
{
    STEK s;
    s.tos = -1;

    FILE *fp1 = fopen(a[1], "r");
    char rijec[101];

    if ( fp1 == NULL ) return 0;

    while ( fscanf(fp1, "%s\n", rijec) != EOF )
    {
        push(&s, rijec);
    }

    print(&s, fopen(a[2], "w"));

    fclose(fp1);
    return 0;
}
