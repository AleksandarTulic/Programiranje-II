#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma pack (1)

typedef struct point{
    int x;
    int y;
    double uda;
}POINT;

int flag = 1;

double distance(double x, double y)
{
    return sqrt(x*x + y*y);
}

void merge_sort(POINT *points, int begin, int end)
{
    if (begin < end)
    {
        int sredina = (begin + end) / 2;
        merge_sort(points, begin, sredina);
        merge_sort(points, sredina+1, end);

        POINT niz[end-begin+1];
        int i = begin,j = sredina + 1,k = 0;

        for (;i<=sredina && j<=end;k++)
            niz[k] = (points + i)->uda < (points + j)->uda ? *(points + i++) : *(points + j++);

        while (i <= sredina) niz[k++] = *(points + i++);
        while (j <= end) niz[k++] = *(points + j++);

        for (i=begin;i<=end;i++) *(points + i) = niz[i-begin];
    }
}

void sort(POINT *points, int n)
{
    merge_sort(points, 0, n-1);
}

int main(int argc,char *argv[])
{
    FILE *fp = fopen(argv[1], "r");

    if ( fp == NULL ) { printf("Greska !!!"); return 0; }

    int a,b;
    int n;
    int i = 0;
    POINT p[10001];

    if ( fscanf(fp,"%d\n", &n) == 1 )
    {
        while (fscanf(fp,"(%d,%d)\n", &a, &b) == 2)
        {
            p[i].x = a;
            p[i].y = b;
            p[i++].uda = distance(a,b);
        }
    }

    fclose(fp);

    sort(p, n);

    printf("SORTIRAN NIZ: \n");
    for (i=0;i<n;i++)
        printf("%d %d %.2lf\n", p[i].x, p[i].y, p[i].uda);
    return 0;
}
