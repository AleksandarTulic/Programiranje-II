#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct cvor{
    int data;
    struct cvor *next;
}CVOR;

void dodaj(CVOR **begin, CVOR **top, int data)
{
    CVOR *node = (CVOR*)malloc(sizeof(CVOR));
    node->data = data;
    node->next = 0;

    if ( *begin == 0 ) { *begin = *top = node; return; }

    (*top)->next = node;
    *top = node;
}

void pop(CVOR **begin)
{
    if ( *begin == 0 ) return;

    CVOR *buff = (*begin)->next;
    free(*begin);
    *begin = buff;
}

void brisi(CVOR **begin)
{
    while ( *begin )
    {
        CVOR *buff = (*begin)->next;
        free(*begin);
        *begin = buff;
    }
}

void pisi(CVOR *begin)
{
    while ( begin )
    {
        printf("%d\n", begin->data);
        begin = begin->next;
    }

    printf("\n");
}

int main()
{
    CVOR *top = 0;
    CVOR *begin = 0;

    dodaj(&begin, &top, 12);
    dodaj(&begin, &top, -5);
    dodaj(&begin, &top, 0);
    dodaj(&begin, &top, 9767);
    dodaj(&begin, &top, -121);

    pisi(begin);

    pop(&begin);
    pop(&begin);

    pisi(begin);
    return 0;
}
