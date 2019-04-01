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
    sortiraj();
    FILE *fp = fopen(argv[1], "ab");

    int i = 0;
    for (i=0;i<br;i++)
        fwrite(&niz[i], sizeof(niz[i]), 1, fp);

    fclose(fp);
}

void prikaz()
{
    char naziv[100];
    printf("Datoteka: \n");
    scanf("%s", naziv);

    FILE *fp = fopen(naziv, "rb");

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

    unos(argv);
    prikaz();
    return 0;
}
