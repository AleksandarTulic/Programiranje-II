#include <stdio.h>
#include <stdlib.h>

int suma_cifara(int b)
{
    if ( b == 0 ) return 0;
    return (b%10)+suma_cifara(b/10);
}

int main()
{
    int b;

    do
    {
        scanf("%d", &b);
    }while ( b < 1 );

    printf("Suma cifara broj %d je: %d", b, suma_cifara(b));
    return 0;
}
