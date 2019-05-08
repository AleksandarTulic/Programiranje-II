#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct student{
    char ime[20];
    char prezime[20];
    char broj_indeksa[10];
}STUDENT;

typedef struct cvor{
    STUDENT info;
    struct cvor *next;
}CVOR;

void dodaj_pocetak(CVOR **glava, STUDENT data)
{
    CVOR *buffer = (CVOR*)malloc(sizeof(STUDENT));
    buffer->info = data;
    buffer->next = *glava;
    *glava = buffer;
}

void brisi_listu(CVOR **glava)
{
    while ( *glava )
    {
        CVOR *buffer = (*glava)->next;
        free(*glava);
        *glava = buffer;
    }
}

void ispis(CVOR *glava)
{
    while ( glava )
    {
        printf("%s %s %s\n", glava->info.broj_indeksa, glava->info.ime, glava->info.prezime);
        glava = glava->next;
    }
}

void formatiran_upis(CVOR *glava)
{
    FILE *fp = fopen("dat.txt", "a");

    fprintf(fp, "========== ==================== ====================\n");
    fprintf(fp, "Broj ind.  Ime                  Prezime             \n");

    while ( glava )
    {
        fprintf(fp,"%-10s %-20s %-20s\n", glava->info.broj_indeksa, glava->info.ime, glava->info.prezime);
        glava = glava->next;
    }

    fprintf(fp, "========== ==================== ====================\n");

    fclose(fp);
}

int main ()
{
    CVOR *glava = 0;
    STUDENT a;
    strcpy(a.broj_indeksa, "11110/18");
    strcpy(a.ime, "Petar111");
    strcpy(a.prezime, "Petar222");

    dodaj_pocetak(&glava, a);

    strcpy(a.broj_indeksa, "1230/17");
    strcpy(a.ime, "Alo123");
    strcpy(a.prezime, "Alo321");

    dodaj_pocetak(&glava, a);

    strcpy(a.broj_indeksa, "1102/16");
    strcpy(a.ime, "Sta456");
    strcpy(a.prezime, "Sta654");

    dodaj_pocetak(&glava, a);

    ispis(glava);

    formatiran_upis(glava);
    return 0;
}

/*

void dodaj_na_kraj(CVOR **glava, STUDENT data)
{
    CVOR *buffer = (CVOR*)malloc(sizeof(STUDENT));
    buffer->info = data;
    buffer->next = 0;

    if ( *glava == 0 ) *glava = buffer;
    else
    {
        while ( (*glava)->next ) *glava = (*glava)->next;
        (*glava)->next = buffer;
    }
}

void dodaj_ispred(CVOR *node, STUDENT data)
{
    CVOR *buffer = (CVOR*)malloc(sizeof(STUDENT));

    buffer->info = node->info;
    buffer->next = node->next;

    node->info = data;
    node->next = node;
}

void dodaj_iza(CVOR *node, STUDENT data)
{
    CVOR *buffer = (CVOR*)malloc(sizeof(STUDENT));

    buffer->info = data;
    buffer->next = node->next;

    node->next = buffer;
}

void brisi_iza(CVOR *node)
{
    if ( node->next == 0 ) return;

    node->next = node->next->next;
    free(node->next);
}

void brisi_cvor(CVOR *node)
{
    if ( node->next == 0 )
    {
        free(node);
    }
    else
    {
        CVOR *buffer = node->next;
        node->info = buffer->info;
        node->next = buffer->next;

        free(buffer);
    }
}

*/
