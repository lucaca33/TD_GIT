#include "tp5.h"
#include <stdlib.h>

void utf8()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8"); // ou ".65001" si ".UTF-8" ne passe pas
}

void menu_print()
{
    printf("=================================\n");
    printf("      Suivi de consommation      \n");
    printf("=================================\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Sauvgarder et quitter\n");
    printf("Votre choix : ");
}

int menu_choix()
{
    int choix;
    scanf("%d", &choix);
    return choix;
}

void inititaliser(int conso[7])
{
    for (int i = 0; i < 7; i++)
    {
        conso[i] = 0;
    }
}

void ajouterConsommation(int conso[7])
{
    printf("==========\n");
    printf("1. Eau 💧\n");
    printf("2. Cafe ☕\n");
    printf("3. Bonbons 🍬\n");
    printf("4. Gateau 🍰\n");
    printf("5. Legumes 🥦\n");
    printf("6. Fruits 🍎\n");
    printf("7. Protéines 🍗\n");
    printf("Votre choix : ");
    int choix = 0;
    choix = menu_choix();
    if (choix < 8 && choix > 0)
    {
        printf("Combien d'unités a ajouter ? ");
        int combien = menu_choix();
        conso[choix - 1] += combien;
        printf("Consommation mise a jour\n");
    }
    else
    {
        printf("Nombre rentré invalide\n");
    }
}

void afficheResume(int conso[7])
{
    printf("========= Resume du jour =========\n");
    printf("Eau      :  %d 💧 ", conso[0]);
    afficherBarre(conso, conso[0], 13);
    printf("Cafe     :  %d ☕ ", conso[1]);
    afficherBarre(conso, conso[1], 5);
    printf("Bonbons  :  %d 🍬 ", conso[2]);
    switch (humeurBonbons(conso[2]))
    {
    case 0:
        printf("😇 ");
        break;
    case 1:
        printf("🙂 ");
        break;
    case 2:
        printf("😒 ");
        break;
    case 3:
        printf("😈 ");
        break;
    }
    afficherBarre(conso, conso[2], 15);
    printf("Gateau   :  %d 🍰 ", conso[3]);
    afficherBarre(conso, conso[3], 5);
    printf("Legumes  :  %d 🥦 ", conso[4]);
    switch (humeurLegumes(conso[2]))
    {
    case 0:
        printf("😭 ");
        break;
    case 1:
        printf("🙂 ");
        break;
    case 2:
        printf("😎 ");
        break;
    }
    afficherBarre(conso, conso[4], 10);
    printf("Fruits   :  %d 🍎 ", conso[5]);
    switch (humeurFruits(conso[2]))
    {
    case 0:
        printf("😢 ");
        break;
    case 1:
        printf("🙂 ");
        break;
    case 2:
        printf("😄 ");
        break;
    }
    afficherBarre(conso, conso[5], 10);
    printf("Protéine :  %d 🍗 ", conso[6]);
    afficherBarre(conso, conso[6], 7);
    return;
}

int charger(int conso[7])
{
    FILE *f = fopen("consommation.txt", "r");
    if (f == NULL)
    {
        printf("Erreur lors du chargement du fichier\n");
        return 0;
    }

    fscanf(f, "%d%d%d%d%d%d%d", &conso[0], &conso[1], &conso[2], &conso[3], &conso[4], &conso[5], &conso[6]);
    fclose(f);
    return 1;
}

int sauvegarder(int conso[7])
{
    FILE *f = fopen("consommation.txt", "w+");
    if (f == NULL)
    {
        printf("Erreur lors du chargement du fichier\n");
        return 0;
    }
    fprintf(f, "%d %d %d %d %d %d %d", conso[0], conso[1], conso[2], conso[3], conso[4], conso[5], conso[6]);
    fclose(f);
    return 1;
}

int humeurBonbons(int nbBonbons)
{
    if (nbBonbons <= 3)
    {
        return 0;
    }
    if (nbBonbons <= 7)
    {
        return 1;
    }
    if (nbBonbons <= 12)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int humeurLegumes(int nbLegumes)
{
    if (nbLegumes <= 2)
    {
        return 2;
    }
    if (nbLegumes <= 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int humeurFruits(int nbFruits)
{
    if (nbFruits <= 2)
    {
        return 2;
    }
    if (nbFruits <= 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afficherBarre(int conso[7], int val, int max){
    if (max <= 0)
    {
        max = 1;
    }
    if (val < 0)
    {
        val = 0;
    }
    else if (val > max)
    {
        val = max;
    }
    float casesPleines = (val * 10.0f) /max;
    for (int i = 0; i < 10; i++)
    {
        if (i < casesPleines)
        {
            printf("█");
        }
        else{
            printf("░");
        }
    }
    printf("\n");
}