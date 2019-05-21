#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

typedef struct proces{
    char naziv[50];
    int broj_s;
}PROCES;

typedef struct cvor{
    PROCES data;
    struct cvor *next;
}CVOR;

void add(CVOR **top, CVOR **bottom, PROCES podatak)
{
    CVOR *novi = (CVOR*)malloc(sizeof(CVOR));

    novi->data = podatak;
    novi->next = 0;

    if ( *top == 0 ) *top = *bottom = novi;
    else
    {
        (*bottom)->next = novi;
        *bottom = novi;
    }
}

int main()
{
    srand(time(NULL));

    int n;
    printf("Unesite broj procesa: ");
    scanf("%d", &n);

    CVOR *top = 0;
    CVOR *bottom = 0;

    int i = 0;
    for (i=1;i<=n;i++)
    {
        char naziv[50] = "proces";
        int broj = rand() % 5 + 1;
        char br[10];

        itoa(i, br, 10);
        strcat(naziv, br);

        PROCES podatak;
        strcpy(podatak.naziv, naziv);
        podatak.broj_s = broj;

        add(&top, &bottom, podatak);

        printf("naziv_procesa: %s; vrijeme: %ds\n", naziv, broj);
    }

    Sleep(3000); //NIJE DOVRSENO NE KONTAM STA TREBA URADITI
    return 0;
}
