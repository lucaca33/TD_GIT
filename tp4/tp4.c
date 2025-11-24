#include <stdio.h>

void afficherMenu()
{
    printf("===== GESTION DES NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher le moyenne d'un eleve\n");
    printf("5. Afficher le moyenne generale\n");
    printf("6. Afficher le meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}

int lireChoix()
{
    printf("Votre choix : ");
    int temp;
    scanf("%d", &temp);
    return temp;
}

int saisirNombreEleves()
{
    printf("Entrez le nombre d'eleves (1 a 30) : ");
    int nb;
    scanf("%d", &nb);
    while (nb < 1 || nb > 30)
    { // note : on aurait pu utiliser un do pour faire plus joli
        printf("Valeur invalide.\n");
        printf("Entrez le nombre d'eleves (1 a 30) : ");
        scanf("%d", &nb);
    }
    return nb;
}

int main()
{
    afficherMenu();
    lireChoix();
    saisirNombreEleves();
    return 0;
}