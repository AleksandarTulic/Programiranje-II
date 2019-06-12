#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor{
    char srp[100];
    char eng[100];
    struct cvor *left;
    struct cvor *right;
}CVOR;

void delete(CVOR *root)
{
    if ( root == 0 ) return;
        delete(root->left);
        delete(root->right);
        free(root);
}

CVOR *new_cvor(char srp[100], char eng[100])
{
    CVOR *new = (CVOR*)malloc(sizeof(CVOR));
    new->left = new->right = 0;
    strcpy(new->srp, srp);
    strcpy(new->eng, eng);
    return new;
}

CVOR *add(CVOR *root, char srp[100], char eng[100])
{
    if ( root == 0 ) return new_cvor(srp, eng);
    else if ( strcmp(root->srp, srp) < 0 ) root->right = add(root->right, srp, eng);
    else if ( strcmp(root->srp, srp) > 0 ) root->left = add(root->left, srp, eng);
    return root;
}

CVOR *find(CVOR *root, char srp[100])
{
    if ( root == 0 || strcmp(root->srp, srp) == 0 ) return root;
    else if ( strcmp(root->srp, srp) < 0 ) return find(root->right, srp);
    else return find(root->left, srp);
}

void inorder(CVOR *root)
{
    if ( root == 0 ) return;

    inorder(root->left);
    printf("%s\n", root->eng);
    inorder(root->right);
}

int main(int argc, char *argb[])
{
    char s[100];
    scanf("%s", s);

    CVOR *root = 0;
    root = add(root, "auto", "car");
    add(root, "kompjuter", "computer");
    add(root, "skakanje", "jumping");
    add(root, "kuhinja", "kitchen");
    add(root, "pas", "dog");

    CVOR *buff = find(root, s);
    if ( buff != 0 ) printf("ENG. %s\n", buff->eng);
    return 0;
}
