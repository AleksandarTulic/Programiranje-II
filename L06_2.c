#include <stdio.h>
#include <stdlib.h>
#pragma pack (1)

typedef struct item{
    char sifra[5];
    char naziv[20];
    double cijena;
}ITEM;

void sort(ITEM **items, int n)
{
    ITEM *pok[n];
    int i;

    for (i=0;i<n;i++) pok[i] = (*(items)+i);

    int h, j;

    for (h=n/2;h>0;h/=2)
    {
        for (i=h;i<n;i++)
        {
            ITEM *tmp = pok[i];

            for (j=i;j>=h && pok[j-h]->cijena > tmp->cijena ;j-=h) pok[j] = pok[j-h];

            pok[j] = tmp;
        }
    }

    FILE *fp = fopen("Artikli.txt", "a");

    fprintf(fp,"===== ==================== =========\n");
    fprintf(fp,"Sifra Naziv                Cijena   \n");
    fprintf(fp,"===== ==================== =========\n");

    for (i=0;i<n;i++)
    {
        fprintf(fp, "%-5s %-20s %9.2lf\n", pok[i]->sifra, pok[i]->naziv, pok[i]->cijena);
    }

    fprintf(fp,"===== ==================== =========\n");
}

int main(int argc,char *argv[])
{
    int n;
    printf("Broj artikala je: ");
    scanf("%d", &n);

    printf("Unesite podatke: \n");
    int i = 0;

    ITEM *niz = (ITEM*)malloc(sizeof(ITEM) * n);

    for (i=0;i<n;i++) scanf("%s %s %lf", (niz + i)->sifra, (niz + i)->naziv, &(niz + i)->cijena);

    sort(&niz, n);
    return 0;
}

/*
- unosim broj artikala
- unesem podatke o artiklima u dinamicki alociran niz
- posaljem adresu tog niza 
- pravim niz pokazivaca da bih sacuvao adresu svakog podatka (na odgvorajucoj poziciji) jer trebamo raditi indirektno 
- tako da mjenjam samo pozicije adresa
- i na kraju ispis
*/
