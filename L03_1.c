#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *formiraj(int n, ...)
{
    int i;va_list v; va_start(v, n);
    char *prenos = 0; /* DEKLARISEM STRING KOJI CU VRATITI KAO REZ. */
    int duzina = 0; /* DUZINA TOG STRINGA */

    for (i=0;i<n;i++)
    {
        int broj = va_arg(v, int); /* UZIMAM PRVI BROJ */

        if ( broj < 0 ) { prenos = (char*)realloc(prenos, sizeof(char) * duzina + 1 + 1); *(prenos + duzina) = '-'; duzina++; }
        /* POSTO SU CIJELI BROJEVI MOGU BITI NEGATIVNI */

        char broj_c[100]; /* SKLADISTIM BROJ KONVERTOVAN U STRING */
        itoa(abs(broj), broj_c, 10);

        int  j = 0;
        while (broj_c[j]) { j++; } /* GLEDAM KOLIKO CIFARA IMA BROJ */

        prenos = (char*)realloc(prenos, sizeof(char) * duzina + j + 1); /* MIJENJM DIMENZIJE STRINGA U KOJI CU SMJESTITI BROJ(STRING) */

        int k = 0;
        for (k=0;k<j;k++) *(prenos + duzina + k) = broj_c[k]; /* DODJELJUJEM STRING ODGOVARAJUCM POZICIJAMA */
        duzina+=j;
    }

    *(prenos + duzina) = 0; /* NULA OPERATOR PREKIDA STRING */

    return prenos;
}

int main()
{
    printf("%s", formiraj(3, 123, -456, -789));
    return 0;
}
