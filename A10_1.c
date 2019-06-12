#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct stek{
    char str[100];
    struct stek *next;
    struct stek *prev;
}STEK;

void add(STEK **head, char str[100])
{
    STEK *new = (STEK*)malloc(sizeof(STEK));
    strcpy(new->str, str);
    new->next = 0;
    new->prev = 0;

    if ( *head == 0 ) *head = new;
    else
    {
        new->prev = *head;
        (*head)->next = new;
        *head = new;
    }
}

void add_read(STEK **head, FILE *fp)
{
    char str[100];
    while ( fscanf(fp, "%s", str) != EOF ) add(head, str);
    fclose(fp);
}

void ispis(STEK *head, FILE *fp)
{
    while ( head )
    {
        fprintf(fp, "%s\n", head->str);
        head = head->prev;
    }
    fclose(fp);
}

int main(int argc, char *argb[])
{
    STEK *head = 0;
    FILE *fp = fopen(argb[1], "r");
    add_read(&head, fp);
    fp = fopen(argb[1], "w");
    ispis(head, fp);
    return 0;
}
