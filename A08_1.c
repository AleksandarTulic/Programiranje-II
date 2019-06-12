#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct stek{
    int broj;
    struct stek *next;
    struct stek *pre;
}STEK;

STEK *add(STEK **head, int broj)
{
    STEK *new = (STEK*)malloc(sizeof(STEK));
    new->broj = broj;
    new->next = 0;
    new->pre = 0;

    if ( *head == 0 ) *head = new;
    else
    {
        (*head)->next = new;
        new->pre = *head;
        *head = new;
    }

    return new;
}

int delete_top(STEK **head)
{
    STEK *buff = (*head)->pre;
    free(*head);
    *head = buff;
    return 1;
}

void ispis(STEK *head)
{
    if ( head )
    {
        printf("%d ", head->broj);
        ispis(head->pre);
    }
}

int delete(STEK **head)
{
    if ( *head == 0 ) return 0;

    while ( *head )
    {
        STEK *buff = (*head)->pre;
        free(*head);
        *head = buff;
    }

    return 1;
}

int main()
{
    STEK *head = 0;
    add(&head, 5);
    add(&head, 12);
    add(&head, -1);
    add(&head, 0);
    add(&head, 1221);
    add(&head, -49);
    add(&head, 55991);

    ispis(head);
    printf("\n");

    delete_top(&head);
    delete_top(&head);

    ispis(head);
    printf("\n");

    delete(&head);
    ispis(head);
    return 0;
}
