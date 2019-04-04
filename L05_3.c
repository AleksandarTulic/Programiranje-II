#include <stdio.h>
#include <stdlib.h>
#pragma pack (1)

int br, niz[10000];

void sortiraj() /* COUNTING SORT */
{
    int ele[10001] = {0}, i = 0, j = 0, brr = 0;

    for (i=0;i<br;i++)
        ele[niz[i]]++;
    for (i=10000;i>=0;i--)
        for (j=0;j<ele[i];j++)
            niz[brr++] = i;
}

void unos(char *argv[])
{
    FILE *fp = fopen(argv[1], "ab");

    int i = 0;
    for (i=0;i<br;i++)
        fwrite(&niz[i], sizeof(niz[i]), 1, fp);

    fclose(fp);
}

void prikaz(char *argv[])
{
    char naziv[100];
    printf("Datoteka: \n");
    scanf("%s", naziv);


    FILE *fp;
    if(naziv[0] == '#') fp= fopen(argv[1], "rb");
    else fp= fopen(naziv, "rb");


    int broj;

    printf("Sortirani brojevi:\n");
    while ( fread(&broj, sizeof(int), 1, fp) )
        printf("%d\n", broj);

    fclose(fp);
}

int main(int argc, char *argv[])
{
    printf("Unesite broj elemenata: ");
    scanf("%d", &br);

    printf("Unesite elemente:\n"); int i = 0;
    for (;i<br;i++) scanf("%d", &niz[i]);
    sortiraj();
    unos(argv);
    prikaz(argv);
    return 0;
}

/*

PRIKAZ - sluzi za prikazivanje elemenata
    - receno je ako je prvi argument komandne linije # onda koristiti prvi argument komandne linije za datoteku za citanje
    - ukoliko nije citati iz datoteke koju ste vi naveli
SORTIRAJ - vrsi sortiranje opadajuce 
UNOS - sluzi za unos podataka
    - upisuje se u onu datoteku koja je prvi argument komandne linije 
PRAGMA PACK (1) - ukoliko imamo strukturu onda ce sizeof(struktura) biti bukvalna velicina 
    - nece biti padding-a

*/
