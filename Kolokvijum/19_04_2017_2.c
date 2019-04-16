#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#pragma pack{1}
int comp(void *a, void *b)
{
    if ( *(int*)a > *(int*)b ) return 1;
    return 0;
}

int bin_search(void *a, int size, int begin, int end, void *key, int (*cmp)(void *, void *))
{
    if ( begin <= end )
    {
        int sredina = (begin + end) / 2;
        if ( *(int*)(a + sredina * size) == *(int*)key ) return sredina;
        else if ( (*cmp)((a + sredina * size), key) ) return bin_search(a, size, begin, sredina - 1, key, cmp);
        else return bin_search(a, size, sredina + 1, end, key, cmp);
    }
    else return -1;
}

int main ()
{
    int niz[6] = {12, -34, 2, 56, 2555, -2556};
    qsort(niz, 6, sizeof(int), comp);

    printf("%d", bin_search(niz, sizeof(int), 0, 5, &niz[3], &comp));
    return 0;
}
