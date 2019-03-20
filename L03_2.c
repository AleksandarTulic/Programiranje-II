#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int paran(int n)
{
    return !(n % 2); /* AKO JE PARAN VRATI 1 U SUPROTNOM 0 */
}

int pozitivan(int n)
{
    if ( n > 0 ) return 1; /* AKO JE BROJ POZ. */
    return 0;
}

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina)
{
    int poz = -1;
    int poc = -1; /* PAMTI POZICIJU POCETKA NAJVECEG PODNIZA */
    int br = 0;
    int maks = -2e9; /* PAMTI DUZINU NAJVECEG PODNIZA */
    int i;

    for (i=0;i<n;i++)
    {
        int clan = (*s)(*(niz + i)); /* GLEDAM USLOV ZA SVAKI BROJ NA POZICIJAMA I */

        if ( poz == -1 && clan ) /* AKO JE PONADJEN PARAN(POZITIVAN) BROJ PRVI PUT */
        {
            br++;
            poz = i;
        }
        else if ( poz != -1 && clan ) /* AKO JE PRONADJEN PARAN(POZITIVAN) BROJ */
        {
            br++;
            if ( i == n - 1 ) /* AKO JE ZADNJI ELEMENT MOZE ISPUNJAVATI PRETHODNI ZADATAK I MOZE BITI NAJVECI PODNIZ */
            {
                if ( maks < br )
                {
                    maks = br;
                    poc = poz;
                }
            }
        }
        else if ( poz != -1 && !clan ) /* AKO JE SADASNJI ELEMENT NE ISPUNJAVA USLOV PROVJERIRI KOJI JE VECI PODNIZ */
        {
            if ( maks < br )
            {
                maks = br;
                poc = poz;
            }

            br = 0; poz = -1;
        }
    }

    *duzina = maks;
    *pocetak = poc;
}

int main()
{
    int *pocetak;
    int duzina;
    int n;int i;

    do
    {
        scanf("%d", &n);
    }while (n < 1);

    int *niz = (int*)malloc(sizeof(int) * n);
    for (i=0;i<n;i++) scanf("%d", niz + i);

    serija(niz, n, &paran, &pocetak, &duzina);

    int poc = pocetak;

    printf("Najveci podniz parnih ele. je: %d\n", duzina);
    printf("ELEMENTI SU:\n");
    for (i=poc;i<poc+duzina;i++) printf("%d ", *(niz + i));printf("\n");

    serija(niz, n, &pozitivan, &pocetak, &duzina);

    poc = pocetak;

    printf("Najveci podniz pozitivnih ele. je: %d\n", duzina);
    printf("ELEMENTI SU:\n");
    for (i=poc;i<poc+duzina;i++) printf("%d ", *(niz + i));

    free(niz);
    return 0;
}
