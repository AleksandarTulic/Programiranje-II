#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n;
    char sifra[6]; /* UCITAVANJE PODATAKA */
    char naziv[21];
    double cijena;

    scanf("%d", &n);

    FILE *fp = fopen(argv[1], "w"); /* OTVARANJE DATOTEKE U MODU ZA UPISIVANJE */
    fprintf(fp, "=== ===== ==================== ======\n"); /* FORMATIRAN ISPIS */
    fprintf(fp, "RB. SIFRA NAZIV                CIJENA\n");
    fprintf(fp, "=== ===== ==================== ======\n");

    int i;
    for (i=1;i<=n;i++) /* N PUTA SE UCITAVAJU PODACI I TOLIKO SE PUTA ISPISUJU U DATOTEKU */
    {
        printf("%d. artikal: ",i);
        scanf("%s %s %lf", sifra, naziv, &cijena);

        fprintf(fp, "%2d. %-5s %-20s %6.2lf\n", i, sifra, naziv, cijena); /* FORMATIRAN ISPIS U DATOTEKU */
    }

    fprintf(fp, "=== ===== ==================== ======\n");
    return 0;
}
