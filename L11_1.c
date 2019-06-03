#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film{
    char naziv[64];
    char zanr[16];
    char reziser[32];
    char glumci[512];
    int godina;
}FILM;

typedef struct cvor{
    FILM data;
    struct cvor *left, *right, *roditelj;
}CVOR;

int flag = 0;

FILM *find(CVOR *root, FILM *data)
{
    if ( root == 0 ) return NULL;
    if ( strcmp(root->data.naziv, data->naziv) == 0 ) return &root->data;

    return find(root->right, data) == NULL ? find(root->left, data) : find(root->right, data);
}

void dodaj(CVOR **root, CVOR *rod, FILM *f)
{
    if ( *root == 0 )
    {
        CVOR *new = (CVOR*)malloc(sizeof(CVOR));
        strcpy(new->data.glumci, f->glumci);
        strcpy(new->data.zanr, f->zanr);
        strcpy(new->data.reziser, f->reziser);
        strcpy(new->data.naziv, f->naziv);
        new->data.godina = f->godina;
        new->roditelj = new->left = new->right = 0;
        *root = new;
        return;
    }

    if ( strcmp((*root)->data.naziv, f->naziv) == 0 )
    {
        strcpy((*root)->data.glumci, f->glumci);
        strcpy((*root)->data.zanr, f->zanr);
        strcpy((*root)->data.reziser, f->reziser);
        strcpy((*root)->data.naziv, f->naziv);
        (*root)->data.godina = f->godina;
        return;
    }
    else if ( strcmp((*root)->data.naziv, f->naziv) == -1 ) dodaj(&(*root)->right, (*root)->roditelj, f);
    else dodaj(&(*root)->left, (*root)->roditelj, f);
}

void print(CVOR *root) //KLD
{
    if ( root == 0 ) return;

    printf("%s\n", root->data.naziv);
    print(root->left);
    print(root->right);
}

void brisi(CVOR *root)
{
    if ( root )
    {
        brisi(root->left);
        brisi(root->right);

        free(root);
    }
}

void print_for(CVOR *root) //LKD
{
    if ( root )
    {
        print_for(root->left);
        printf("%s\n", root->data.naziv);
        print_for(root->right);
    }
}

int brisi_cvor(CVOR *root, FILM f)
{
    if ( root->right == 0 && root->left == 0 && strcmp(f.naziv, root->data.naziv) == 0 )
    {
        CVOR *buff = root->roditelj;
        buff->left == root ? (buff->left = 0) : (buff->right = 0);
        free(root);
        return 1;
    }
    else if ( root->right == 0 && strcmp(f.naziv, root->data.naziv) == 0 )
    {
        CVOR *buff = root->roditelj;
        buff->left == root ? (buff->left = root->left) : (buff->right = root->left);
        buff = root->left;
        buff->roditelj = root->roditelj;
        free(root);
        return 1;
    }
    else if ( root->left == 0 && strcmp(f.naziv, root->data.naziv) == 0 )
    {
        CVOR *buff = root->roditelj;
        buff->left == root ? (buff->left = root->right) : (buff->right = root->right);
        buff = root->right;
        buff->roditelj = root->roditelj;
        free(root);
        return 1;
    }
    else
    {
    }
}

int main()
{
    CVOR *root = 0;
    FILM f;
    strcpy(f.glumci, "Nicolas Cage");
    strcpy(f.naziv, "the");
    strcpy(f.zanr, "Komedija");
    strcpy(f.reziser, "Johny");
    f.godina = 2018;

    dodaj(&root, 0, &f);

    strcpy(f.glumci, "Vjeverica");
    strcpy(f.naziv, "five");
    strcpy(f.zanr, "Akcija");
    strcpy(f.reziser, "Webeer");
    f.godina = 1992;

    dodaj(&root, 0, &f);

    strcpy(f.glumci, "Vjeverica");
    strcpy(f.naziv, "wizards");
    strcpy(f.zanr, "Akcija");
    strcpy(f.reziser, "Webeer");
    f.godina = 1992;

    dodaj(&root, 0, &f);

    strcpy(f.glumci, "Vjeverica");
    strcpy(f.naziv, "jump");
    strcpy(f.zanr, "Akcija");
    strcpy(f.reziser, "Webeer");
    f.godina = 1992;

    dodaj(&root, 0, &f);

    strcpy(f.glumci, "Vjeverica");
    strcpy(f.naziv, "boxing");
    strcpy(f.zanr, "Akcija");
    strcpy(f.reziser, "Webeer");
    f.godina = 1992;

    dodaj(&root, 0, &f);

    strcpy(f.glumci, "Vjeverica");
    strcpy(f.naziv, "quickly!");
    strcpy(f.zanr, "Akcija");
    strcpy(f.reziser, "Webeer");
    f.godina = 1992;

    dodaj(&root, 0, &f);

    print(root);

    printf("\n\n");

    print_for(root);
    return 0;
}
