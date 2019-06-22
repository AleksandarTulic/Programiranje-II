#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor{
    int i;
    struct cvor *s;
}CVOR;

typedef struct graf{
    int n; // broj cvorova
    char *r[10]; // inf. sadrzaj cvora
    CVOR *s[10]; // lista susjedstva
}GRAF;

void dodaj(CVOR **pglava, int i)
{
    CVOR *new = (CVOR*)malloc(sizeof(CVOR));
    new->i = i;
    new->s = 0;

    if ( *pglava == 0 ) *pglava = new;
    else
    {
        CVOR *buff = *pglava;

        while ( buff->s ) buff = buff->s;

        buff->s = new;
    }
}

GRAF *st(const GRAF *g, int c)
{
    GRAF *f = (GRAF*)malloc(sizeof(GRAF));
    f->n = g->n;

    int i;
    for (i=0;i<g->n;i++) f->r[i] = g->r[i];
    for (i=0;i<6;i++) f->s[i] = 0;

    int flag[10] = {};

    void dfs(int u)
    {
        flag[u] = 1;

        CVOR *buff = g->s[u];

        while ( buff )
        {
            if ( flag[buff->i] == 0 )
            {
                dodaj(&f->s[u], buff->i);
                dodaj(&f->s[buff->i], u);
                dfs(buff->i);
            }
            buff = buff->s;
        }
    }

    dfs(c);

    return f;
}

int main()
{
    GRAF g;
    g.n = 6;
    g.r[0] = "Banja";
    g.r[1] = "Gradiska";
    g.r[2] = "Prijedor";
    g.r[3] = "Doboj";
    g.r[4] = "Derventa";
    g.r[5] = "Prnjavor";

    int i = 0;

    for (;i<6;i++) g.s[i] = 0;

    dodaj(&g.s[0], 1);
    dodaj(&g.s[0], 3);
    dodaj(&g.s[0], 2);
    dodaj(&g.s[1], 0);
    dodaj(&g.s[1], 3);
    dodaj(&g.s[2], 0);
    dodaj(&g.s[2], 3);
    dodaj(&g.s[2], 4);
    dodaj(&g.s[3], 0);
    dodaj(&g.s[3], 1);
    dodaj(&g.s[3], 2);
    dodaj(&g.s[4], 2);
    dodaj(&g.s[4], 5);
    dodaj(&g.s[5], 4);

    for (i=0;i<6;i++)
    {
        CVOR *buff = g.s[i];

        printf("%d: ", i);
        while ( buff )
        {
            printf("%d ", buff->i);
            buff = buff->s;
        }
        printf("\n");
    }

    GRAF *f = st(&g, 0);

    for (i=0;i<6;i++)
    {
        CVOR *buff = f->s[i];

        printf("%d: ", i);
        while ( buff )
        {
            printf("%d ", buff->i);
            buff = buff->s;
        }
        printf("\n");
    }
    return 0;
}
