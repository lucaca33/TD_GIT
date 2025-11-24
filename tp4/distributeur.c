#include <stdio.h>
#include "distributeur.h"

void afficherMenu()
{
    printf("===== Banque - Distributeur =====\n");
    printf("1. Faire un retrait\n");
    printf("2. Quitter\n");
}

int lireChoix()
{
    printf("Votre choix : ");
    int temp = 0;
    scanf("%d", &temp);
}

int saisir_montant()
{
    printf("Montant a retirer : ");
    int montant = 0;
    scanf("%d", montant);
    return montant;
}

int montant_valide(int montant)
{
    if (montant % 5 != 0)
    {
        printf("Erreur : montant invalide.\nLe montant doit etre en 5 et 1000 euros, divisible pas 5.");
        return 1;
    }
    return 0;
}

void calcul_distribution(int montant)
{
    int nb50, nb20, nb5 = 0;
    while (montant >= 50)
    {
        nb50++;
        montant -= 50;
    }
    while (montant >= 20)
    {
        nb20++;
        montant -= 20;
    }
    while (montant >= 5)
    {
        nb5++;
        montant -= 5;
    }
    printf("%d billets de 50 euros\n", nb50);
    printf("%d billets de 20 euros\n", nb20);
    printf("%d billets de 5 euros\n", nb5);
}

int main()
{
    int choix = -1;
    int montant;
    while (choix != 2)
    {
        afficherMenu();
        choix = lireChoix();
        printf("================\n");
        switch (choix)
        {
        case 1:
            montant = saisir_montant();
            if (montant_valide(montant))
            {
                calcul_distribution(montant);
            }
            break;
        }
    }
    return 0;
}