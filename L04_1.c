#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp1 = fopen(argv[1], "r");

    if ( fp1 == NULL ) { printf("Error"); return 0; }

    char rijec[100];
    char naj[100] = "";

    while ( fscanf(fp1, "%s", rijec) != EOF ) /* UCITAVAM PODATKE TJ RIJECI BILO BI DOBRO DA LJUDI NEKAD RADE NESTO NORMALNO */
    {
        int i;
        char rj[100];int br = 0;

        for (i=0;i<strlen(rijec);i++)
        {
            if ( rijec[i] > 'z' || rijec[i] < 'a' ) /* PROVJERAVAM DA LI TO NIJE BILO KAKVO SLOVO (OVAJ I SLJEDECI USLOV) */
            {
                if ( rijec[i] > 'Z' || rijec[i] < 'A' )
                {
                    rj[br] = '\0'; /* KASNIJE CU NEKAD NAPRAVIT LJEPSE MISLIM NA KOD */
                    printf("%s\n", rj);
                    FILE *fp2 = fopen(argv[2], "a");
                    if ( br != 0 ) fprintf(fp2, "%s\n", rj);
                    if ( strlen(rj) > strlen(naj) ) strcpy(naj, rj);
                    br = 0;
                    fclose(fp2);
                }
                else rj[br++] = rijec[i];
            }
            else rj[br++] = rijec[i];
        }

        if ( br != 0 )
        {
            rj[br] = '\0';
            FILE *fp2 = fopen(argv[2], "a");
            if ( rj != "" ) fprintf(fp2, "%s\n", rj);
            if ( strlen(rj) > strlen(naj) ) strcpy(naj, rj);
            br = 0;
            fclose(fp2);
        }
    }

    fclose(fp1);

    printf("Najduza rijec je: %s\n", naj);
    return 0;
}
