#include <stdio.h>

void afficherMenu(){
    printf("===== GESTION DES NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher le moyenne d'un eleve\n");
    printf("5. Afficher le moyenne generale\n");
    printf("6. Afficher le meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}

int lireChoix(){
    printf("Votre choix : ");
    int temp;
    scanf("%d", &temp);
    return temp;
}

int main(){
    return 0;
}