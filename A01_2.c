#include <stdio.h>
#include <stdlib.h>

void cifra(int n)
{
    if ( n == 0 ) return;

    printf("%d\n", n%10);
    cifra(n/10);
}

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
    }while ( n < 1 );

    printf("REZULTAT:\n");
    cifra(n);
}
