#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#define MAX 5
#define MAXX 1000

typedef struct red{
    int niz[MAX];
    int left, right;
}RED;

typedef struct stek{
    int niz[MAXX];
    int tos;
}STEK;

/*=============== STACK =================*/

int isFull(STEK *s)
{
    return s->tos == MAXX - 1;
}

int isEmpty(STEK *s)
{
    return s->tos == -1;
}

int push(STEK *s, int data)
{
    if ( isFull(s) ) return 0;

    s->niz[++s->tos] = data;
    return 1;
}

int stek_pop(STEK *s)
{
    if ( isEmpty(s) ) return 0;

    int i=0;
    int *niz = (int*)malloc((s->tos+1)*sizeof(int));
    while ( !isEmpty(s) ) niz[i++] = s->niz[s->tos--];
    return niz;
}

/*=============== BUFFER ================*/

int isFULL(RED *buffer)
{
    return (buffer->right + 1) % MAX == buffer->left;
}

int isEMPTY(RED *buffer)
{
    return buffer->left == -1;
}

int add(RED *buffer, int data)
{
    if ( isFULL(buffer) ) return 0;
    if ( buffer->left == -1 ) buffer->left = 0;

    buffer->right = (buffer->right+1)%MAX;
    buffer->niz[buffer->right] = data;
    return 1;
}

int delete_ele(RED *buffer, int *data)
{
    if ( isEMPTY(buffer) ) return 0;

    *data = buffer->niz[buffer->left];

    if ( buffer->left == buffer->right ) buffer->left = buffer->right = -1;
    else buffer->left =(buffer->left + 1)%MAX;
    return 1;
}

int write_all(RED *buffer)
{
    if ( isEMPTY(buffer) ) return 0;

    int i = buffer->left;

    if ( buffer->left <= buffer->right )
        while ( i <= buffer->right )
            printf("%d ", buffer->niz[i++]);
    else
    {
        while ( i <= MAX - 1 ) printf("%d ", buffer->niz[i++]); i=0;
        while ( i <= buffer->right ) printf("%d ", buffer->niz[i++]);
    }

    printf("\n");
    return 1;
}

int main()
{
    RED buffer;
    buffer.left = buffer.right = -1;
    int broj;

    STEK s;
    s.tos = -1;
    int *rez;

    while (1)
    {
        int op;
        printf("Meni:\n");
        printf("Novi element       [1]\n");
        printf("Uklanjanje elementa[2]\n");
        printf("ispis              [3]\n");
        printf("Prekid rada        [0]\n");
        printf("Naredba: ");
        scanf("%d", &op);

        if ( !op ) { printf("\nDOVIDJENJA"); break; }
        else if ( op == 1 )
        {
            printf("\nUnesite broj: ");
            scanf("%d", &broj);

            push(&s, broj);

            if ( !add(&buffer, broj) ) printf("\nBuffer je pun!!!\n");
        }
        else if ( op == 2 )
        {
            if ( delete_ele(&buffer, &broj) ) printf("\nObrisan je element %d\n", broj);
            else printf("Buffer je prazan\n");
        }
        else if ( op == 3 )
        {
            printf("\nSadrzaj buffera:\n");

            if ( write_all(&buffer) == 0 ) printf("Buffer je prazan!!!\n");
        }
        else printf("\nNISTE IZABRALI NI JEDNU OD PONUDJENIH OPCIJA. POKUSAJTE PONOVO!!!\n\n");
    }

    int br = s.tos + 1;
    rez = stek_pop(&s);
    int i = 0;
    printf("\nSvi koristeni brojevi su:\n");
    for (;i<br;i++) printf("%d\n", rez[i]);

    free(rez);
    return 0;
}
