#include <stdio.h>
#include <stdlib.h>

int suma(int *niz, int n)
{
    if ( n == -1 ) return 0;
    return *(niz + n) + suma(niz, n-1);
}

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
    }while ( n < 1 );

    int i;
    int niz[n];
    for (i=0;i<n;i++) scanf("%d", &niz[i]);

    printf("Suma niza je: %d", suma(&niz, n-1));
    return 0;
}
