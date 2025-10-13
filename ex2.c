#include <stdio.h>
#include <math.h>

int main()
{

    float C;
    printf("Le montant du pret : ");
    scanf("%f", &C);
    getchar();
    float t;
    printf("Le taux anuel : ");
    scanf("%f", &t);
    getchar();
    int n;
    printf("La duree du pret en annees : ");
    scanf("%d", &n);

    float mensualite = (C * (t / 12)) / (1 - (pow(1 + (t / 12), n * 12)));

    printf("La mensualite du pret est de : %f\n",mensualite);
    return 0;
}