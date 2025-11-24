#include <stdio.h>

void afficherMenu()
{
    printf("===== Banque - Distributeur =====\n");
    printf("1. Faire un retrait\n");
    printf("2. Quitter\n");
}

int lireChoix(){
    printf("Votre choix : ");
    int temp = 0;
    scanf("%d", &temp);
}

int saisir_montant(){
    printf("Montant a retirer : ");
    int montant = 0;
    scanf("%d", montant);
    return montant;
}

int montant_valide(){
    if (saisir_montant() % 5 != 0)
    {
        printf("Erreur : montant invalide.\nLe montant doit etre en 5 et 1000 euros, divisible pas 5.");
        return 1;
    }
    return 0;
}


int main()
{
    int choix = -1;
    while (choix != 0)
    {
        afficherMenu();
        choix = lireChoix();
        printf("================\n");
        switch (choix)
        {
        case 1:
            break;
        case 2:
            break;
        }
    }
    return 0;
}