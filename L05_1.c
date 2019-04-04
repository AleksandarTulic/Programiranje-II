#include <stdio.h>
#include <stdlib.h>
#pragma pack (1)

char naziv[100]; /* NAZIV U FAJLA IZ KOGA CITAM I U KOJI UPISUJEM PODATKE */
typedef struct naz{ char ime[21], prezime[21], broj[21]; } NAZIV; /* NEKAKVA STRUKTURA */

void unos_podataka()
{

    FILE *fp = fopen(naziv, "ab");

    if ( fp == NULL ) { printf("Greska!!!\n"); return;  }

    int koliko; /* NISAM BAS NAJBOLJE RAZUMIO UPIS (MOZDA SE TREBA KORISTIT ONAJ V_ARG TAKO NESTO) */
    printf("Koliko osoba unosite u datoteku: \n");
    scanf("%d", &koliko);

    while (koliko--) /* UNOSIMO koliko OSOBA */
    {
        NAZIV podatak;
        scanf("%s %s %s", podatak.ime, podatak.prezime, podatak.broj); /* USNOSIMO PODATKE O SVAKOJ OSOBI */

        fwrite(&podatak, sizeof(NAZIV), 1, fp); /* USIDUJEMO PODATKE O SVAKOJ OSOBI U BINARNU DATOTEKU */
    }

    fclose(fp);
}

void citanje_podataka(char* str)
{
    FILE *fp;
    if (naziv[0] == '#') fp = fopen(str, "rb"); /* OTVARAM U FORMATU ab ZA APPEND DA NALIJEPIM NA KRAJ */
    else fp = fopen(naziv, "rb");

    if ( fp == NULL ) { printf("Greska!!!\n"); return; }

    NAZIV podatak;
    while ( fread(&podatak, sizeof(NAZIV), 1, fp) ) /* CITAM PODATKE IZ BINARNE DATOTEKE U FORMATU GORE DEF. STRUKTURE */
        printf("%s %s %s\n", podatak.ime, podatak.prezime, podatak.broj);

    fclose(fp);
}

int main(int argc,char *argv[])
{
    printf("Unesite naziv datoteke: ");
    scanf("%s", naziv);

    int vrsta; printf("\nUnos podataka: 1\nCitanje podataka: 2\n\n");
    scanf("%d", &vrsta);
    char *str = argv[1];
    if ( vrsta == 1 ) unos_podataka(); /* RADIM OVAJ USLOV DA BIH (NIJE BIH KAO BOSNA I HERCEGOVINA NEGO bih) ZNAO KOJU OPERACIJU DA URADIM  */
    else citanje_podataka(str);
    return 0;
}
