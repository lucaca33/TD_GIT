#include <stdio.h>
#include <math.h>

int main()
{

    float pret;
    printf("Le montant du pret : ");
    scanf("%f", &pret);
    float taux;
    printf("Le taux anuel : ");
    scanf("%d", &taux);
    int duree;
    printf("La duree du pret en annees : ");
    scanf("%f", &pret);

    float mensualite = (pret * (taux / 12)) / (1 - pow(1 + (taux / 12), -duree * 12));

    printf("La mensualite du pret est de : %.2f\n", mensualite);
    return 0;
}