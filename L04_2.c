#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r"); /* OTVARAM ODGOVARAJUCI FAJL U ODGOVARAJUCEM MODU ZA CITANJE TJ READ */

    if ( fp == NULL ) { printf("Error"); return 0; } /* AKO NEMA FAJLA ILI NE MOZE SE OTVORIT PRIKAZI ODG. PORUKU */

    double x1,y1,r1, pov1; /* PROMJENLJIVE U KOJIMA SMJESTAM VRIJEDNOSTI */
    double x2, y2, r2, pov2; /* PROMJENLJIVE KOJE SKLADISTE VRIJEDNOSTI ONE KOORDINATE KOJI IMAJU NAJVISU OPVRSINU */

    while ( fscanf(fp, "(%lf,%lf,%lf)\n", &x1, &y1, &r1) == 3 ) /* FORMATIRAN UPIS */
    {
        pov1 = r1 * r1 * 3.14159;

        if ( pov1 > pov2 ) /* DA LI NOVE PROMJELJIVE OBRAZUJU VECU POVRSINU */
        {
            pov2 = pov1;
            x2 = x1;
            y2 = y1;
            r2 = r1;
        }
    }

    fclose(fp); /* ZATVARAM FAJL */

    printf("Najvecu povrsinu (P=%lf) ima krug:\n", pov2);
    printf("(%lf,%lf,%lf)", x2,y2,r2);
    return 0;
}
