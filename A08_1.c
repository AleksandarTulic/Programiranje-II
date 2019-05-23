#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct cvor{
    int data;
    struct cvor *next;
}CVOR;

void dodaj(CVOR **top, CVOR **begin, int data)
{
    CVOR *node = (CVOR*)malloc(sizeof(CVOR));

    if ( *top != 0 ) (*top)->next = node;
    else *begin = node;

    node->data = data;
    *top = node;
    node->next = 0;
}

void pop(CVOR **top, CVOR *begin)
{
    if ( *top == 0 ) return;
    while ( begin->next != *top ) begin = begin->next;

    free(*top);
    *top = begin;
    (*top)->next = 0;
}

void pisi(CVOR *begin)
{
    while ( begin )
    {
        printf("%d\n", begin->data);
        begin = begin->next;
    }
}

void brisi(CVOR **begin)
{
    while ( *begin )
    {
        CVOR *buff = *begin;
        *begin = (*begin)->next;
        free(buff);
    }
}

int main()
{
    CVOR *top, *begin;
    top = 0;
    begin = 0;

    dodaj(&top, &begin, 12);
    dodaj(&top, &begin, -5);
    dodaj(&top, &begin, 45);
    dodaj(&top, &begin, 999);
    dodaj(&top, &begin, -1142);

    pisi(begin);printf("\n");

    pop(&top, begin);
    pop(&top, begin);

    pisi(begin);printf("\n");

    brisi(&begin);

    pisi(begin);
    return 0;
}
