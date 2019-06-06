#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct rij{
    char naziv[100];
}RIJ;

typedef struct cvor{
    RIJ p;
    struct cvor *left;
    struct cvor *right;
}CVOR;

CVOR *new_cvor(RIJ p)
{
    CVOR *buff = (CVOR*)malloc(sizeof(CVOR));
    strcpy(buff->p.naziv, p.naziv);
    buff->right = buff->left = 0;
    return buff;
}

CVOR *find(CVOR *root, RIJ p)
{
    if ( root == 0 || strcmp(root->p.naziv, p.naziv) == 0 ) return root;
    else if ( strcmp(root->p.naziv, p.naziv) == -1 ) return find(root->right , p);
    else if ( strcmp(root->p.naziv, p.naziv) == 1 ) return find(root->left, p);
    return 0;
}

CVOR *add(CVOR *root, RIJ p)
{
    if ( root == 0 ) return new_cvor(p);
    else if ( strcmp(root->p.naziv, p.naziv) == -1 ) root->right = add(root->right, p);
    else root->left = add(root->left, p);

    return root;
}

void inorder(CVOR *root, FILE *fp)
{
    if ( root == 0 ) return;

    inorder(root->left, fp);
    fprintf(fp, "%s\n", root->p.naziv);
    inorder(root->right, fp);
}

void delete(CVOR *root)
{
    if ( root == 0 ) return;

    delete(root->left);
    delete(root->right);
    free(root);
}

int main(int argc, char *argb[])
{
    CVOR *root = 0;

    FILE *fp = fopen(argb[1], "r");
    RIJ a;

    if ( fp == NULL ) return;

    while ( fscanf(fp, "%s", a.naziv) != EOF )
        if ( root == 0 ) root = add(root, a);
        else add(root, a);

    fclose(fp);fp = fopen(argb[2], "w");
    inorder(root, fp);
    fclose(fp);

    delete(root);
    return 0;
}
