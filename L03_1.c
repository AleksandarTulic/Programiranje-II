#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *formiraj(int n, ...)
{
    int i;va_list v; va_start(v, n);
    char *prenos = 0;
    int duzina = 0;

    for (i=0;i<n;i++)
    {
        int broj = va_arg(v, int);

        if ( broj < 0 ) { prenos = (char*)realloc(prenos, sizeof(char) * duzina + 1 + 1); *(prenos + duzina) = '-'; duzina++; }

        char broj_c[100];
        itoa(abs(broj), broj_c, 10);

        int  j = 0;
        while (broj_c[j]) { j++; }

        prenos = (char*)realloc(prenos, sizeof(char) * duzina + j + 1);

        int k = 0;
        for (k=0;k<j;k++) *(prenos + duzina + k) = broj_c[k];
        duzina+=j;
    }

    *(prenos + duzina) = 0;

    return prenos;
}

int main()
{
    printf("%s", formiraj(3, 123, -456, -789));
    return 0;
}
