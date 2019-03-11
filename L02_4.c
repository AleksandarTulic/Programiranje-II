#include <stdio.h>
#include <stdlib.h>

int clan(int n)
{
    if ( n == 1 ) return 1;
    else if ( n == 2 ) return 2;
    else if ( n == 3 ) return 3;
    else return clan(n-1) + clan(n-2) + clan(n-3);
}

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
    }while (n < 1);

    printf("N-ti clan: %d", clan(n));
    return 0;
}
