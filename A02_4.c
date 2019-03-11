#include <stdio.h>
#include <stdlib.h>

void faktoradiks(int n, int broj)
{
    if ( n  == 0 ) return;
    printf("%d\n", n % broj);
    faktoradiks(n/broj, broj+1);
}

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
    }while ( n < 1 );

    printf("REZULTAT:\n");
    faktoradiks(n, 1);
    return 0;
}
