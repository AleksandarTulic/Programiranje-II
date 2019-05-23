#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

typedef struct proces{
    char naziv[20];
    int broj;
}PROCES;

typedef struct cvor{
    PROCES p;
    struct cvor *next;
}CVOR;

void dodaj(CVOR **pf, CVOR **pr, PROCES *p)
{
    CVOR *novi = (CVOR*)malloc(sizeof(CVOR));

    novi->p = *p;
    novi->next = 0;

    if ( *pf == 0 ) *pf = *pr = novi;
    else
    {
        (*pr)->next = novi;
        *pr = novi;
    }
}

int brisi(CVOR **pf, CVOR **pr, PROCES *p)
{
    if ( *pf == 0 ) return 0;

    CVOR *buff = *pf;
    *p = buff->p;

    if ( *pf == *pr ) *pf = *pr = 0;
    else *pf = buff->next;

    free(buff);
    return 1;
}

int main()
{
    srand(time(NULL));

    int n;
    printf("Unesite broj procesa: ");
    scanf("%d", &n);

    CVOR *pf = 0;
    CVOR *pr = 0;

    int i = 1;
    for (;i<=n;i++)
    {
        char naziv[50] = "proces";
        int broj = rand() % 5 + 1;
        char br[10];

        itoa(i, br, 10);
        strcat(naziv, br);

        PROCES p;
        strcpy(p.naziv, naziv);
        p.broj = broj;

        dodaj(&pf, &pr, &p);

        printf("naziv_procesa: %s; vrijeme: %ds\n", naziv, broj);
    }

    char ins[100];
    printf("Unesite naredbu: ");
    scanf("%s", ins);

    if ( !strcmp(ins, "START") )
    {
        PROCES p;
        while ( pf )
        {
            Sleep(pf->p.broj*1000);

            printf("naziv_procesa: %s; vrijeme: %ds\n", pf->p.naziv, pf->p.broj);

            brisi(&pf, &pr, &p);

            printf("Izbrisan proce: %s; vrijeme: %ds\n\n", p.naziv, p.broj);
        }
    }
    return 0;
}
