#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma pack (1)

typedef struct rijeci{ char slova[100]; }RIJECI;

char **scan(FILE *fin, int *n)
{
    char rijec[100];
    int brr = 0;
    RIJECI niz[10001];
    int i = 0;

    while ( fscanf(fin, "%s", rijec) != EOF )
    {
        char rj[100];int br = 0;

        for (i=0;i<strlen(rijec);i++)
        {
            if ( rijec[i] > 'z' || rijec[i] < 'a' )
                if ( rijec[i] > 'Z' || rijec[i] < 'A' )
                {
                    rj[br] = '\0';
                    if ( br != 0 ) strcpy(niz[brr++].slova, rj);
                    br = 0;
                }
                else rj[br++] = rijec[i];
            else rj[br++] = rijec[i];
        }

        if ( br != 0 )
        {
            rj[br] = '\0';
            strcpy(niz[brr++].slova, rj);
        }
    }

    fclose(fin); *n = brr;

    char **vrati = (char**)malloc(sizeof(char*) * brr);
    for (i=0;i<brr;i++) vrati[i] = niz[i].slova;

    return vrati;
}

void print(FILE *fout, char **array, int n)
{
    int i = 0;
    for (i=0;i<n;i++)
        fprintf(fout, "%s\n", array[i]);
    fclose(fout);
}

void sort(char **array, int n)
{
    int i,j;
    char tmp[100];

    for (i=1;i<n;i++)
    {
        strcpy(tmp, array[i]);

        for (j=i;j>0 && strcmp(array[j-1], tmp)>0;j--)
            strcpy(array[j], array[j-1]);
        strcpy(array[j], tmp);
    }
}

int main(int argc,char *argv[])
{
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "w");
    int br = 0;
    char **niz = scan(fp1, &br);
    sort(niz, br);
    print(fp2, niz, br);
    return 0;
}
