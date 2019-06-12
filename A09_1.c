#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct artikal{
    int sifra;
    char naziv[20];
    double cijena;
    double kolicina;
}ARTIKAL;

typedef struct cvor{
    ARTIKAL data;
    struct cvor *next;
    struct cvor *prev;
}CVOR;

void add(CVOR **head, ARTIKAL data)
{
    CVOR *new = (CVOR*)malloc(sizeof(CVOR));
    new->next = new->prev = 0;
    new->data = data;

    if ( *head == 0 ) *head = new;
    else
    {
        CVOR *buff = *head;
        while ( buff->next && data.sifra > buff->data.sifra ) buff = buff->next;

        new->prev = buff;
        new->next = buff->next;
        buff->next = new;
    }
}

CVOR *find(CVOR *head, int sifra)
{
    while ( head )
        if ( head->data.sifra == sifra ) return head;

    return NULL;
}

void print(CVOR *head)
{
    printf("===== ==================== ======== ======\n");
    printf("SIFRA NAZIV                KOLICINA CIJENA\n");

    while ( head )
    {
        printf("%05d %-20s %-.6lf %-.6lf\n", head->data.sifra, head->data.naziv, head->data.kolicina, head->data.cijena);
        head = head->next;
    }

    printf("===== ==================== ======== ======\n");
}

int delete_node(CVOR *head, int sifra)
{
    if ( find(head, sifra) == 0 ) return 0;

    CVOR *buff = find(head, sifra);
    if ( buff->next == 0 && buff->prev == 0 ) free(buff);
    else if ( buff->prev == 0 )
    {
        head = buff;
        buff = buff->next;
        buff->prev = 0;
        free(head);
    }
    else if ( buff->next == 0 )
    {
        head = buff;
        buff = buff->prev;
        buff->next = 0;
        free(head);
    }
    else
    {
        CVOR *buff1 = buff->prev;
        CVOR *buff2 = buff->next;
        buff1->next = buff2;
        buff2->prev = buff1;
        free(buff);
    }

    return 1;
}

void delete(CVOR **head)
{
    if ( *head == 0 ) return;

    while ( *head )
    {
        CVOR *buff = (*head)->next;
        free(*head);
        *head = buff;
    }
}

void add_art(CVOR **head)
{
    ARTIKAL data;
    printf("SIFRA   : ");scanf("%d", &data.sifra);
    printf("NAZIV   : ");scanf("%s", data.naziv);
    printf("KOLICINA: ");scanf("%lf", &data.kolicina);
    printf("CIJENA  : ");scanf("%lf", &data.cijena);
    add(head, data);
}

int main()
{
    CVOR *head = 0;

    int flag = 0;
    do
    {
        printf("ADD    [1]\n");
        printf("DELETE [2]\n");
        printf("PRINT  [3]\n");
        printf("SEARCH [4]\n");
        printf("OUT    [0]\n");
        scanf("%d", &flag);

        if ( flag == 1 ) add_art(&head);
        else if ( flag == 2 )
        {
            int broj;
            printf("INSERT THE PASSWORD YOU WANT TO DELETE: ");scanf("%d", &broj);
            if ( delete_node(head, broj) ) printf("IT IS DELETED\n");
            else printf("IT IS NOT DELETED\n");
        }
        else if ( flag == 3 ) print(head);
        else if ( flag == 4 )
        {
            int broj;
            printf("ENTER THE ARTICAL(password) YOU ARE SEARCHING: ");scanf("%d", &broj);

            CVOR *buff = find(head, broj);
            print(buff);
        }
    }while ( flag );

    delete(&head);
    return 0;
}
