#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    void *data;
    struct node *next;
}NODE;

typedef struct sll{
    NODE *head, *tail;
}SLL;

void add(SLL *list, void *data)
{
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->data = data;
    new->next = 0;

    if ( list->head == 0 ) list->head = list->tail = new;
    else
    {
        list->tail->next = new;
        list->tail = new;
    }
}

int cmp(const void *a, const void *b)
{
    int c = (int*)a;
    int d = (int*)b;

    if ( c == d ) return 0;
    else if ( c > d ) return 1;
    else return -1;
}

int equals(const SLL *l1, const SLL *l2, int (*cmp)(const void *, const void *))
{
    NODE *cvor1 = l1->head;
    NODE *cvor2 = l2->head;

    int br1, br2;
    br1 = br2 = 0;

    while ( cvor1->next )
    {
        cvor1 = cvor1->next;
        br1++;
    }

    while ( cvor2->next )
    {
        cvor2 = cvor2->next;
        br2++;
    }

    if ( br1 == br2 )
    {
        cvor1 = l1->head;
        cvor2 = l2->head;

        while ( cvor1 )
        {
            if ( (*cmp)(cvor1->data, cvor2->data) != 0 ) return -1;

            cvor1 = cvor1->next;
            cvor2 = cvor2->next;
        }
    }
    else return -1;

    return 1;
}

int main()
{
    int a[5] = {1,2,3,5,4};
    int b[5] = {1,2,3,5,4};

    SLL l1;
    SLL l2;
    l1.head = l1.tail = l2.head = l2.tail = 0;

    int i = 0;
    for (i=0;i<5;i++)
    {
        add(&l1, (void*)a[i]);
        add(&l2, (void*)b[i]);
    }

    printf("%d\n", equals(&l1, &l2, &cmp));
    return 0;
}
