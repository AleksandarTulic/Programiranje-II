#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#define MAX 5
#define MAXX 1000

typedef struct node{
    char str[100];
    struct node *left, *right;
}NODE;

NODE *add(char str[])
{
    NODE *new = (NODE*)malloc(sizeof(NODE));
    strcpy(new->str, str);
    new->right = new->left = 0;
    return new;
}

NODE *add_left(char str[], NODE *root)
{
    NODE *new = add(str);

    if ( root->left ) new->left = root->left;
    root->left = new;

    return new;
}

NODE *add_right(char str[], NODE *root)
{
    NODE *new = add(str);

    if ( root->right ) new->right = root->right;
    root->right = new;

    return new;
}

void preorder(NODE *root)
{
    if ( root != 0 )
    {
        printf("%s ", root->str);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE *root)
{
    if ( root != 0 )
    {
        inorder(root->left);
        printf("%s ", root->str);
        inorder(root->right);
    }
}

void postorder(NODE *root)
{
    if ( root != 0 )
    {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->str);
    }
}

void delete_stable(NODE *root)
{
    if ( root )
    {
        delete_stable(root->left);
        delete_stable(root->right);
        free(root);
    }
}

int main()
{
    NODE *root, *c1, *c2, *c3, *c4, *c5;
    root = add("Danas");
    c1 = add_right("Sutra", root);
    c2 = add_left("Nikada", root);
    c3 = add_left("Sjura", c1);
    c4 = add_left("Vecera", c2);
    c5 = add_right("Vjetar", c2);
    add_right("Livada", c5);

    printf("PREORDER ISPIS:\n");
    preorder(root);
    printf("\n\n");

    printf("INORDER ISPIS:\n");
    inorder(root);
    printf("\n\n");

    printf("POSTORDER ISPIS:\n");
    postorder(root);
    printf("\n\n");

    delete_stable(root);
    return 0;
}
