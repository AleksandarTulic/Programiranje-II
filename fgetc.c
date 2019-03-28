#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("AAA.txt", "r");

    char s;
    s = fgetc(fp);
    while ( s != EOF )
    {
        printf("%c\n", s);
        s = fgetc(fp);
    }
    fclose(fp);
    return 0;
}
