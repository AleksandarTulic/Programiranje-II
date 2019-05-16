#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *left, *right;
}NODE;

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)(b));
}

void write_one(const char *a)
{
    printf("%s\n", (char*)a);
}

NODE *search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *))
{
    if ( head == 0 ) return 0;

    while ( (*cmp)( head->data, data ) < 0 && (*cmp)( tail->data, data ) > 0 )
    {
        head = head->right;
        tail = tail->left;
    }

    return (*cmp)( head->data, data ) == 0 ? head : ( (*cmp)( tail->data, data ) == 0 ? tail : 0 );
}

void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    if ( search(*phead, *ptail, data, cmp) ) return;

    NODE *p, *q, *novi = (NODE*)malloc(sizeof(NODE));

    novi->data = data;novi->left = 0;novi->right = 0;

    if ( *phead == 0 ) *phead = *ptail = novi;
    else if ( (*cmp)( (*phead)->data, data ) > 0 )
    {
        novi->right = *phead;
        (*phead)->left = novi;
        *phead = novi;
    }
    else if ( (*cmp)( (*phead)->data, data ) < 0 )
    {
        novi->left = *ptail;
        (*ptail)->right = novi;
        *ptail = novi;
    }
    else
    {
        for (p = *phead, q = (*ptail)->left; (*cmp)( p->right->data, data ) < 0 && (*cmp)( q->data, data ) > 0; p = p->right, q = q->left )
            if ( (*cmp)( q->data, data ) < 0 ) p = q;

        novi->right = p->right;
        novi->left = q;
        p->right->left = novi;
        p->right = novi;
    }
}

void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
}

void write(NODE *head, void (*write_one)(const void *))
{
    while ( head )
    {
        (*write_one)(head->data);
        head = head->right;
    }
}

void delete_list(NODE **phead, NODE **ptail)
{
    while ( *phead )
    {
        NODE *p = (*phead)->right;
        free(*phead);
        *phead = p;
        *ptail = 0;
    }
}

int main()
{
    return 0;
}
