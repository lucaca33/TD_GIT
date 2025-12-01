#include "tp5.h"

void menu_print(){
    printf("=================================\n");
    printf("      Suivi de consommation      \n");
    printf("=================================\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Sauvgarder et quitter\n");
    printf("Votre choix : ");
}

int menu_choix(){
    int choix;
    scanf("%d", &choix);
    return choix;
}