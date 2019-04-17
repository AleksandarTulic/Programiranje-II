#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef struct rece{ char re[100];
}RECE;

char **to_array(int n,...)
{
    va_list v;
    va_start(v, n);
    int i;
    RECE r[1000];

    for (i=0;i<n;i++)
    {
        char *t = va_arg(v, char*);
        int j = 0;
        while ( t[j] ) r[i].re[j] = t[j], j++;
        r[i].re[j] = '\0';
    }

    char **array = (char**)malloc(sizeof(char*) * n);
    for (i=0;i<n;i++) array[i] = r[i].re;
    va_end(v);
    return array;
}

void str_sort(int n, char **array)
{
    int i,j;
    char tmp[100];

    for (i=1;i<n;i++)
    {
        strcpy(tmp, array[i]);
        for (j=i;j>0 && strcmp(array[j-1], tmp) > 0;j--) strcpy(array[j], array[j-1]);
        strcpy(array[j], tmp);
    }
}

int main ()
{
    char **array = to_array(3, "Jabuka", "JAbuka", "Visnja");

    int i = 0;
    printf("Nije Sortirano:\n");
    for (i=0;i<3;i++) printf("%s\n", array[i]);
    str_sort(3, array);
    printf("Sortirano: \n");
    for (i=0;i<3;i++) printf("%s\n", array[i]);
    return 0;
}
