#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct rij{
    char srp[100];
    char eng[100];
}RIJ;

typedef struct cvor{
    RIJ p;
    struct cvor *left;
    struct cvor *right;
}CVOR;

CVOR *new_cvor(RIJ p)
{
    CVOR *buff = (CVOR*)malloc(sizeof(CVOR));
    buff->left = buff->right = 0;
    strcpy(buff->p.eng, p.eng);
    strcpy(buff->p.srp, p.srp);
    return buff;
}

CVOR *add(CVOR *root, RIJ p)
{
    if ( root == 0 ) return new_cvor(p);
    else if ( strcmp(root->p.srp, p.srp) == -1 ) root->right = add(root->right, p);
    else if ( strcmp(root->p.srp, p.srp) == 1 ) root->left = add(root->left, p);
    return root;
}

CVOR *find(CVOR *root, RIJ p)
{
    if ( root == 0 || strcmp(root->p.srp, p.srp) == 0 ) return root;
    else if ( strcmp(root->p.srp, p.srp) == -1 ) return find(root->right, p);
    else if ( strcmp(root->p.srp, p.srp) == 1 ) return find(root->left, p);
    return 0;
}

void delete(CVOR *root)
{
    if ( root == 0 ) return;

    delete(root->left);
    delete(root->right);
    free(root);
}

CVOR *load(FILE *fp)
{
    RIJ a;
    CVOR *buff = 0;
    while ( fscanf(fp, "%s %s", a.srp, a.eng) != EOF )
        if ( find(buff, a) == 0 )
            if ( buff == 0 ) buff = add(buff, a);
            else add(buff, a);

    return buff;
}

int main(int argc, char *argb[])
{
    CVOR *root = 0;
    FILE *fp = fopen(argb[1], "r");
    if ( fp == NULL ) return 0;

    root = load(fp);
    fclose(fp);

    while (1)
    {
        RIJ p;
        printf("Unesite rijec: ");scanf("%s", p.srp);

        CVOR *buff = find(root, p);

        if ( buff == 0 ) return 0;
        else printf("%s\n", buff->p.eng);
    }

    delete(root);
    return 0;
}
