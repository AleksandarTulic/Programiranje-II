#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *formiraj(int n, ...)
{
    int i;int vr;
    va_list v;
    va_start(v, n);

    char **m;
    m = (char**)malloc(sizeof(char*) * n);
    for (i=0;i<n;i++)
        *(m + i) = (char*)malloc(20);

    int *broji;
    broji = (int*)malloc(sizeof(int) * n);

    int br1 = 0;
    int br2 = 0;
    int br = 0;

    for (i=0;i<n;i++)
    {
        vr = va_arg(v, int);

        while (vr)
        {
            *(*(m + br1) + br2) = (char)((vr % 10)+'0');
            br2++;
            br++;
            vr/=10;
        }
        *(broji + br1) = br2;
        br1++;
        br2=0;
    }
    va_end(v);

    char *vrati;
    vrati = (char*)malloc(br + 1);
    br = 0;
    br1 = br;
    for (i=0;i<n;i++)
    {
        int broj = *(broji + i);int j;

        for (j = broj-1;j>=0;j--)
        {
            *(vrati + br) = *(*(m + i) + j);
            br++;
        }
    }

    *(vrati + br) = 0;

    return vrati;
}

int main()
{
    char *p = formiraj(3, 123, 456, 789);

    while (*p)
    {
        printf("%c", *p);
        p++;
    }
    return 0;
}
/* NADAM SE  I JA SAM DA NECU CITATI KOD */
