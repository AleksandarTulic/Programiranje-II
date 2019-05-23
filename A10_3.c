#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#define MAX 1000

typedef struct student{
    char indeks[10];
    char ime[20];
    char prezime[20];
    double prosjek;
}STUDENT;

typedef struct red{
    STUDENT data;
    struct red *left, *right;
}RED;

int br_elemenata(RED *l)
{
    int br = 0;
    while (l)
    {
        l = l->right;
        br++;
    }

    return br;
}

void dodaj(RED **l, RED **r, STUDENT s)
{
    RED *cvor = (RED*)malloc(sizeof(RED));

    if ( *l == 0 )
    {
        *l = *r = cvor;
        cvor->left = 0;
        cvor->right = 0;
        cvor->data = s;
    }
    else
    {
        while ( (*l)->right != 0 && (*l)->data.prosjek > s.prosjek ) *l = (*l)->right;

        if ( (*l)->left == 0 )
        {
            printf("11%0.2lf\n", s.prosjek);
            cvor->right = *l;
            cvor->left = 0;
            cvor->data = s;
            (*l)->left = cvor;
        }
        else if ( (*l)->right == 0 && (*l)->data.prosjek > s.prosjek )
        {
            printf("22%0.2lf\n", s.prosjek);
            cvor->right = 0;
            cvor->left = *l;
            (*l)->right = cvor;
            cvor->data = s;
        }
        else if ( (*l)->right == 0 )
        {
            printf("33%0.2lf\n", s.prosjek);
            cvor->right = *l;
            cvor->left = (*l)->left;
            cvor->data = s;

            (*l)->left->right = cvor;
            (*l) = cvor->right;
            (*l)->left = cvor;

        }
        else
        {
            printf("44%0.2lf\n", s.prosjek);
            cvor->data = s;
            cvor->left = (*l)->left;
            cvor->right = *l;

            (*l)->left->right = cvor;
            (*l) = cvor->right;
            (*l)->left = cvor;
        }

        while ( (*l)->left != 0 ) *l = (*l)->left;
        while ( (*r)->right != 0 ) *r = (*r)->right;
    }
}

void prikaz(RED *l)
{
    printf("=== ========== ==================== ==================== ========\n");
    printf("RB. INDEKS     IME                  PREZIME              PROOSJEK\n");
    printf("=== ========== ==================== ==================== ========\n");

    int br = 1;

    while ( l )
    {
        printf("%-3d %-10s %-20s %-20s %8.2lf\n", br++,l->data.indeks, l->data.ime, l->data.prezime, l->data.prosjek);
        l = l->right;
    }

    printf("=== ========== ==================== ==================== ========\n");
}

void delete_node(RED **buff, RED **l, RED **r)
{
    if ( (*buff)->left == 0 && (*buff)->right == 0 ) {}
    else if ( (*buff)->left == 0 )
    {
        *l = (*buff)->right;
        (*buff)->right->left = 0;
    }
    else if ( (*buff)->right == 0 )
    {
        *r = (*buff)->left;
        (*buff)->left->right = 0;
    }
    else
    {
        RED *l = (*buff)->left;
        RED *r = (*buff)->right;

        l->right = r;
        r->left = l;
    }

    free(*buff);
}

void delete_all(RED **l)
{
    while ( *l )
    {
        RED *buff = *l;
        free(*l);
        *l = buff->right;
    }
}

int main()
{
    RED *l, *r;
    l = 0;
    r = 0;

    while (1)
    {
        int op;

        printf("Unesite naredbu:\n");
        printf("Dodavanje    [1]\n");
        printf("Brisanje Stu.[2]\n");
        printf("Brisanje Reda[3]\n");
        printf("Prikaz       [4]\n");
        printf("Prekid rada  [5]\n\n");

        scanf("%d", &op);

        if ( op == 1 )
        {
            STUDENT s;
            printf("Unesite podatke: \n");
            printf("Indeks : ");scanf("%s", s.indeks);
            printf("Ime    : ");scanf("%s", s.ime);
            printf("Prezime: ");scanf("%s", s.prezime);
            printf("Prosjek: ");scanf("%lf", &s.prosjek);
            printf("\n");
            dodaj(&l, &r, s);
        }
        else if ( op == 2 )
        {
            prikaz(l);

            int broj;
            printf("Unesite RB. studenta koga zelite obrisati: ");
            scanf("%d", &broj);

            RED *buff = l;
            int br = 1;

            while ( br++ < broj ) buff = buff->right;

            delete_node(&buff, &l, &r);
        }
        else if ( op == 3 ) delete_all(&l);
        else if ( op == 4 ) prikaz(l);
        else if ( op == 5 ) { printf("Dovidjenja!!!"); return 0; }
    }

    delete_all(&l);
    return 0;
}
