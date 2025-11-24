#include <stdio.h>
#include "tp4.h"

void afficherMenu()
{
    printf("===== GESTION DES NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher la moyenne d'un eleve\n");
    printf("5. Afficher la moyenne generale\n");
    printf("6. Afficher la meilleure note de chaque controle\n");
    printf("0. Quitter\n");
}

int lireChoix()
{
    printf("Votre choix : ");
    int temp;
    scanf("%d", &temp);
    return temp;
}

int saisirNombreEleves(int note_eleves[30][3])
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
    // on initialise les note de tout les élèves a -1
    for (int i = 0; i < nb; i++)
    {
        note_eleves[i][0] = -1;
        note_eleves[i][1] = -1;
        note_eleves[i][2] = -1;
    }
    return nb;
}

void saisirNotes(int eleves[30][3], int nb_eleves)
{ // 30 élèves max et que 3 controles
    for (int i = 0; i < nb_eleves; i++)
    {
        printf("Eleve %d :\n", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("   Note du controle %d (0 a 20) : ", j + 1);
            int note;
            scanf("%d", &note);
            while (note < 0 || note > 20)
            { // note : on aurait pu utiliser un do pour faire plus joli
                printf("   ! Note invalide.\n");
                printf("   Note du controle %d (0 a 20) : ", j + 1);
                scanf("%d", &note);
            }
            eleves[i][j] = note;
        }
    }
}

void afficherNotes(int tab[30][3], int nb_eleves)
{
    printf("Tableau des notes\n");
    printf("Eleve  C1  C2  C3");
    for (int i = 0; i < nb_eleves; i++)
    {
        printf("\n   ");
        if (i < 10)
        {
            printf(" ");
        }
        // note 1
        printf("%d  ", i);
        if (tab[i][0] < 10)
        {
            printf(" ");
        }
        printf("%d  ", tab[i][0]);
        // note 2
        if (tab[i][1] < 10)
        {
            printf(" ");
        }
        printf("%d  ", tab[i][1]);
        // note 3
        if (tab[i][2] < 10)
        {
            printf(" ");
        }
        printf("%d", tab[i][2]);
    }
    printf("\n");
}

float calculerMoyenneEleve(int tab[30][3], int n_eleve)
{
    if (tab[n_eleve][0] == -1)
    {
        printf("Cet eleve n'as pas de note attribue\n");
        return 1.0f;
    }
    float moyenne = 0;
    for (int i = 0; i < 3; i++)
    {
        moyenne += tab[n_eleve][i];
    }
    moyenne /= 3;
    printf("\n");
    return moyenne;
}

void calculerMoyenne_demander(int tab[30][3], int nb_eleves)
{
    printf("Entrez le numero de l'eleve : ");
    int nb;
    scanf("%d", &nb);
    nb--;
    if (nb < 0 || nb > 29 || nb > nb_eleves)
    {
        printf("Numero d'eleve invalide");
        return;
    }
    
    float moyenne = 0;
    moyenne += calculerMoyenneEleve(tab, nb);
    printf("La moyenne de l'eleve %d est %.2f", nb + 1, moyenne);
    return;
}

void calculerMoyenneGenerale(int tab[30][3], int nb_eleves)
{
    if (nb_eleves == 0)
    {
        printf("Il n'y a pas d'eleves\n");
        return;
    }

    float moyenne = 0;
    for (int i = 0; i < nb_eleves; i++)
    {
        moyenne += calculerMoyenneEleve(tab, i);
    }
    moyenne /= nb_eleves;
    printf("La moyenne de la classe est de %f\n", moyenne);
    return;
}

int trouverMeilleureNoteControle(int tab[30][3], int nb_eleves, int indiceControle)
{
    if (indiceControle < 0 || indiceControle > 2)
    {
        printf("L'incide du controle est incorrect");
        return 0;
    }

    int best = tab[0][indiceControle];
    for (int i = 0; i < nb_eleves; i++)
    {
        if (tab[i][indiceControle] > best)
        {
            best = tab[i][indiceControle];
        }
    }
    return best;
}

void afficherMeilleuresNotes(int tab[30][3], int nb_eleves)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Meilleure note au controle %d : %d\n", i, trouverMeilleureNoteControle(tab, nb_eleves, i));
    }
}

int main()
{
    int nb_eleves = 0;
    int note_eleves[30][3];
    int choix = -1;
    while (choix != 0)
    {
        afficherMenu();
        choix = lireChoix();
        printf("================\n");
        switch (choix)
        {
        case 1:
            nb_eleves = saisirNombreEleves(note_eleves);
            break;
        case 2:
            saisirNotes(note_eleves, nb_eleves);
            break;
        case 3:
            afficherNotes(note_eleves, nb_eleves);
            break;
        case 4:
            calculerMoyenne_demander(note_eleves, nb_eleves);
            break;
        case 5:
            calculerMoyenneGenerale(note_eleves, nb_eleves);
            break;
        case 6:
            afficherMeilleuresNotes(note_eleves, nb_eleves);
            break;
        }
    }
    return 0;
}
