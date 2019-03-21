#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rj = "";
int suma = 0;
int red1 = -1;
int red2 = -1;

char *dodaj(char *a, char *b)
{
    char *rijec;

    rijec = (char*)malloc(strlen(a) + strlen(b) + 1);

    strcpy(rijec, a);
    strcat(rijec, b);

    char *prenos;
    prenos = rijec;
    return prenos;
}

int saberi(int a, int b)
{
    return a + b;
}

void spoji_saberi(int argc, char *argv[], char* (*dodaj)(char*, char*), int (*saberi)(int, int))
{
    int i;int flag = -1;int pazi = -1;
    for (i=1;i<argc;i++)
    {
        if ( argv[i][0] == '-' && argv[i][1] == 's' ) { flag = 1; pazi = 1; if (red1==-1) red1=i; } /* FLAG KORISTIM DA ZNAM KOJA OPERACIJA */
        else if ( argv[i][0] == '-' && argv[i][1] == 'b' ) { flag = 2; pazi = 2; if (red2==-1) red2=i; } /* RED KORISTIM KOJI SE PRVI POJAVLJUJE */
  
        /* PAZI KORISTIM DA VIDIM DA LI JE NA TOM MJESTU PRONADJEN ZNAK ZA NAREDBU -B ILI -S */
        
        if ( flag == 1 )
        {
            if ( pazi != 1 ) rj = (*dodaj)(rj, argv[i]);
            pazi = -1;
        }
        else if ( flag == 2)
        {
            if ( pazi != 2 ) suma=(*saberi)(suma, atoi(argv[i]));
            pazi = -1;
        }
    }
}

int main(int argc, char *argv[])
{
    spoji_saberi(argc, argv, &dodaj, &saberi);

    char ispis_suma[] = "Suma brojeva je %d.";
    char ispis_rijec[] = "String je '%s'.";

    if ( red1 > red2 ) /* PAZIM KOJA SE PRVO NAREDBA POJAVLJUJE (REDOSLIJED ISPISA) */
    {
        if ( suma != 0 ) { printf(ispis_suma, suma);printf(" "); }
        if ( rj != "" ) printf(ispis_rijec, rj);
    }
    else
    {
        if ( rj != "" ) { printf(ispis_rijec, rj);printf(" "); }
        if ( suma != 0 ) printf(ispis_suma, suma);
    }
    return 0;
}

/*

char *substring(char *str, int a, int b) // pronalazi substring od stringa str poceci od karaktera koji se nalazi na a do b
{
    int duzina = str ? strlen(str) : 0;

    if ( !duzina ) return "";

    char *stri = (char*)malloc(sizeof(char) * duzina + 1); stri = str;

    char *strin = (char*)malloc(sizeof(char) * (duzina - b + a) + 1);
    int i = 0;int j = 0;
    for (i=a;i<=b;i++) *(strin + j++) = *(stri + i); *(strin + ++j) = '\0';

    char *vrati = strin;
    return vrati;
}

*/
