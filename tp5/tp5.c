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
    printf("3. Afficher les objectifs et le score\n");
    printf("4. Sauvgarder et quitter\n");
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

void afficherBarre(int conso[7], int val, int max)
{
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
    float casesPleines = (val * 10.0f) / max;
    for (int i = 0; i < 10; i++)
    {
        if (i < casesPleines)
        {
            printf("█");
        }
        else
        {
            printf("░");
        }
    }
    printf("\n");
}

void afficher_objectifs(int conso[7], int objectif[7])
{
    printf("====== Objectifs du jour ======\n");
    printf("Catégorie     Objectif   Atteint ? \n\n");
    if (objectif[0] != 0)
    {
        printf("Eau       :  %d  ", objectif[0]);
        if (objectif[0] <= conso[0])
        {
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    else
    {
        printf("Eau       :  _   (pas d'objectif)\n");
    }
    if (objectif[1] != 0)
    {
        printf("Cafe      :  %d  ", objectif[1]);
        if (objectif[1] <= conso[1])
        {
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    else
    {
        printf("Cafe      :  _   (pas d'objectif)\n");
    }
    if (objectif[2] != 0)
    {
        printf("Bonbons   :  %d  ", objectif[2]);
        if (objectif[2] <= conso[2])
        {
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    else
    {
        printf("Bonbons   :  _   (pas d'objectif)\n");
    }
    if (objectif[3] != 0)
    {
        printf("Gateau    :  %d  ", objectif[3]);
        if (objectif[3] <= conso[3])
        {
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    else
    {
        printf("Gateau    :  _   (pas d'objectif)\n");
    }
    if (objectif[4] != 0)
    {
        printf("Legumes   :  %d  ", objectif[4]);
        if (objectif[4] <= conso[4])
        {
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    else
    {
        printf("Legumes   :  _   (pas d'objectif)\n");
    }
    if (objectif[5] != 0)
    {
        printf("Fruits    :  %d  ", objectif[5]);
        if (objectif[5] <= conso[5])
        {
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    else
    {
        printf("Fruits    :  _   (pas d'objectif)\n");
    }
    if (objectif[6] != 0)
    {
        printf("Protéine  :  %d  ", objectif[6]);
        if (objectif[6] <= conso[6])
        {
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    else
    {
        printf("Protéine  :  _   (pas d'objectif)\n");
    }
    int score = calculerScoreSante(conso, objectif);
    printf("Score santé du jour : %d / 100\n", score);
}

int calculerScoreSante(int conso[7], int objectif[7])
{
    int score_base = 50;
    if (conso[0] > objectif[0])
    {
        score_base += 10;
    }
    if (conso[4] > objectif[4])
    {
        score_base += 10;
    }
    if (conso[5] > objectif[5])
    {
        score_base += 10;
    }
    if (conso[6] > objectif[6])
    {
        score_base += 10;
    }
    if (conso[2] > 5)
    {
        if (conso[2] > 20)
        {
            score_base -= 15;
        }
        else
        {
            score_base -= conso[2] - 5;
        }
    }
    if (conso[1] > 3)
    {
        if (conso[1] > 13)
        {
            score_base -= 20;
        }
        else
        {
            score_base -= (conso[2] - 3)*2;
        }
    }
    if (score_base < 0)
    {
        score_base = 0;
    }
    else if (score_base > 100){
        score_base = 100;
    }
    return score_base;
}