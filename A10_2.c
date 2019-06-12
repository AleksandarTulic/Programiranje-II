#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct stek{
    char niz[100];
    int vis;
}STEK;

void add(STEK *s, char i)
{
    s->niz[++s->vis] = i;
}

int palindrome(STEK *s1, STEK *s2)
{
    int i = 0;
    for (i=0;i<s1->vis;i++)
        if ( s1->niz[i] != s2->niz[i] ) return 0;
    return 1;
}

int main(int argc, char *argb[])
{
    char str[100];
    scanf("%s", str);

    STEK s1;
    s1.vis = -1;
    STEK s2;
    s2.vis = -1;

    int i;
    for (i=0;i<strlen(str);i++)
    {
        add(&s1, str[i]);
        add(&s2, str[strlen(str)-i-1]);
    }

    if ( palindrome(&s1, &s2) ) printf("YES\n");
    else printf("NO\n");
    return 0;
}
