#include <stdio.h>
#include <stdlib.h>

void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n)
{
    if ( n == -1 ) return;

    *(vektor_rez + n) = *(vektor_a + n) + *(vektor_b + n);
    saberi(vektor_a, vektor_b, vektor_rez, n-1);
}

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
    }while ( n < 1 );

    double *niz1;
    double *niz2;
    double *niz3;

    niz1 = (double*)malloc(sizeof(double) * n);
    niz2 = (double*)malloc(sizeof(double) * n);
    niz3 = (double*)malloc(sizeof(double) * n);

    int i;
    for (i=0;i<n;i++) scanf("%lf", (niz1 + i));
    for (i=0;i<n;i++) scanf("%lf", (niz2 + i));


    saberi(niz1, niz2, niz3, n-1);

    printf("REZULTAT:\n");
    for (i=0;i<n;i++) printf("%lf\n", *(niz3 + i));

    free(niz1);
    free(niz2);
    free(niz3);
    return 0;
}
