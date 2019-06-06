#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <ctype.h>
#include <windows.h>
#define MAX 5
#define MAXX 1000

typedef struct film{
    char naziv[64];
    char zanr[16];
    char reziser[32];
    char glumci[512];
    int godina;
}FILM;

typedef struct cvor{
    FILM p;
    struct cvor *left;
    struct cvor *right;
}CVOR;

CVOR *new_cvor(FILM p)
{
    CVOR *new = (CVOR*)malloc(sizeof(CVOR));
    new->left = new->right = 0;
    new->p = p;
    return new;
}

int cmp(char *a, char *b)
{
    char c[strlen(a)+1];strcpy(c, a);
    char d[strlen(b)+1];strcpy(d, b);
    int br = 0;
    while (c[br]) c[br]=toupper(c[br]),br++;
    br = 0;
    while (d[br]) d[br]=toupper(d[br]),br++;

    return strcmp(c, d);
}

CVOR *add_cvor(CVOR *root, FILM p)
{
    if ( root == 0 ) return new_cvor(p);
    else if ( cmp(root->p.naziv, p.naziv) == 0 )
    {
        strcpy(root->p.glumci, p.glumci);
        strcpy(root->p.zanr, p.zanr);
        strcpy(root->p.reziser, p.reziser);
        root->p.godina = p.godina;
    }
    else if ( cmp(root->p.naziv, p.naziv) < 0 ) root->right = add_cvor(root->right, p);
    else root->left = add_cvor(root->left, p);
    return root;
}

CVOR *find(CVOR *root, FILM p)
{
    if ( root == 0 || cmp(p.naziv, root->p.naziv) == 0 ) return root;
    else if ( cmp(root->p.naziv, p.naziv) < 0 ) return find(root->right, p);
    else if ( cmp(root->p.naziv, p.naziv) > 0 ) return find(root->left, p);
    else return 0;
}

CVOR *find_max(CVOR *root)
{
    while (root->right != 0) root = root->right;
    return root;
}

CVOR *delete(CVOR *root, FILM p)
{
    if ( cmp(root->p.naziv, p.naziv) < 0 ) root->right = delete(root->right, p);
    else if ( cmp(root->p.naziv, p.naziv) > 0 ) root->left = delete(root->left, p);
    else if ( root->left == 0 )
    {
        CVOR *buff = root->right;
        free(root);
        return buff;
    }
    else if ( root->right == 0 )
    {
        CVOR *buff = root->left;
        free(root);
        return buff;
    }
    else
    {
        CVOR *buff = find_max(root->left);
        root->p = buff->p;
        root->left = delete(root->left, root->p);
    }

    return root;
}

int try_delete(CVOR *root, FILM p)
{
    return find(root, p) == 0 ? 0 : (delete(root, p),1);
}

void inorder(CVOR *root)
{
    if ( root == 0 ) return;

    inorder(root->left);
    printf("NAZIV  : %s\n", root->p.naziv);
    printf("GLUMCI : %s\n", root->p.glumci);
    printf("ZANR   : %s\n", root->p.zanr);
    printf("REZISER: %s\n", root->p.reziser);
    printf("GODINA : %d\n\n", root->p.godina);
    inorder(root->right);
}

void delete_all(CVOR *root)
{
    if ( root == 0 ) return;

    delete_all(root->left);
    delete_all(root->right);
    free(root);
}

int main()
{
    int flag;
    CVOR *root = 0;
    while (1)
    {
        if ( flag != '0' )
        {
        printf("===========================================================================\n");
        printf("   Dodaj: 1 || Pretrazi: 2 || Ispisi: 3 || Obrisi film: 4 || Prekini: 0 \n");
        printf("===========================================================================\n");}
        scanf("%d", &flag);

        if ( flag == 0 ) break;
        else if ( flag == 1 )
        {
            printf("\n\n");
            printf("DODAJTE INF. ZA FILM:\n");
            FILM f;
            printf("REZISER: ");scanf("%s", f.reziser);
            printf("ZANR: ");scanf("%s", f.zanr);
            printf("NAZIV: ");scanf("%s", f.naziv);
            printf("GLUMCI: ");scanf("%s", f.glumci);
            printf("GODINA: ");scanf("%d", &f.godina);

            if ( root == 0 ) root = add_cvor(root, f);
            else add_cvor(root, f);
        }
        else if ( flag == 2 )
        {
            printf("\n\n");FILM f;
            printf("NAZIV FILMA: ");scanf("%s",f.naziv);
            CVOR *buff = find(root, f);
            if ( buff == 0 ) printf("FILM NIJE PRONADJEN!!!\n\n");
            else printf("%s %s %s %d\n\n", buff->p.zanr, buff->p.reziser, buff->p.glumci, buff->p.godina);
        }
        else if ( flag == 3 ) inorder(root);
        else if ( flag == 4 )
        {
            printf("\n\n");FILM f;
            printf("NAZIV FILMA: ");scanf("%s",f.naziv);

            if ( try_delete(root, f) == 0 ) printf("FILM NIJE PRONADJEN!!!\n\n");
            else printf("FILM JE OBRISAN!!!\n\n");
        }
        else printf("\n\nPOKUSAJTE PONOVO!!!\n\n");
    }

    delete_all(root);
    return 0;
}
