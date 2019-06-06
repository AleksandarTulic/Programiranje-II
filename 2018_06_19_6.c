#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor{
    char r[100];
}CVOR;

typedef struct graf{
    CVOR m[100][100];
}GRAF;

int flag[100] = {};

void dfs(GRAF *g, int node, CVOR p, char **rece, int broj)
{
    flag[node] = 1;
    int br = 0;

    while ( p.r[br] )
    {
        *((*rece)+broj) = p.r[br];
        broj++;
        br++;
    }
    if ( broj != 0 ) *((*rece)+broj++) = ' ';

    int i = 0;
    for (;i<100;i++)
        if ( !flag[i] && strcmp(g->m[node][i].r, "") != 0 )
            dfs(g, i, g->m[node][i], rece, broj);
}

void recenica(GRAF *g, int start, char **r)
{
    CVOR p; strcpy(p.r, "");
    dfs(g, 0, p, r, 0);
}

int main()
{
    char *r = (char*)calloc(500, sizeof(char));

    GRAF g;
    int i = 0;
    int j = 0;
    for (i=0;i<100;i++)
        for (int j=0;j<100;j++)
            strcpy(g.m[i][j].r, "");

    strcpy(g.m[0][2].r, "Sljiva");
    strcpy(g.m[0][4].r, "Vidim");
    strcpy(g.m[1][4].r, "Alo");
    strcpy(g.m[4][2].r, "Danas");
    strcpy(g.m[2][3].r, "Sutra");
    strcpy(g.m[3][5].r, "Veceta");
    strcpy(g.m[5][1].r, "WW@");
    strcpy(g.m[0][1].r, "R!!R");

    recenica(&g, 0, &r);

    printf("%s\n", r);
    free(r);
    return 0;
}
