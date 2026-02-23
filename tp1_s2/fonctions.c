#include "main.h"

void utf8()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8"); // ou ".65001" si ".UTF-8" ne passe pas
}

int demander_range()
{
    printf("Entrez le nombre de rangée : ");
    int temp = 0;
    scanf("%d", &temp);
    return temp;
}

int demander_table()
{
    printf("Entrez le nombre de table : ");
    int temp = 0;
    scanf("%d", &temp);
    return temp;
}

void demander_chemin_fichier(char chemin[25])
{
    if (chemin == NULL)
    {
        printf("PROBLEME\n");
        return;
    }

    printf("Entrez le chemin du fichier texte (il doit être au même niveau que l'exe)(ex : liste.txt) : ");
    scanf("%s", chemin);
}

int lire_fichier(char c[25], Eleve *eleve)
{
    if (eleve == NULL)
    {
        printf("Erreur\n");
        return 1;
    }
    FILE *fichier = fopen(c, "r");
    char line[256];
    char nom[128], prenom[128];
    int i = 0;
    printf("\n");
    while (fgets(line, sizeof(line), fichier))
    {
        if (sscanf(line, "%127s %127s", prenom, nom) == 2)
        {
            printf("%d) %s, %s\n", i + 1, prenom, nom);
            strcpy(eleve[i].nom, nom);
            strcpy(eleve[i].prenom, prenom);
            i++;
        }
    }
    return i;
}

void initialiser_places(Place places[100][100], int row, int col)
{
    if (places == NULL)
    {
        printf("Erreur\n");
        return;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            places[i][j].num_rangee = row + 1;
            places[i][j].num_table = col + 1;
            places[i][j].occupe = 0;
        }
    }
}

void placer_eleves(Place p[100][100], Eleve *e, int row_max, int col_max, int nb_eleve)
{
    if (p == NULL || e == NULL)
    {
        printf("Erreur\n");
        return;
    }

    int row_current = 0;
    int eleve_par_row = nb_eleve / row_max;
    if (eleve_par_row > col_max)
    {
        printf("Pas assez de place pour faire rentrer tout les élèves");
        return;
    }

    int temp_nb_eleves = nb_eleve;
    int temp_nb_eleves_par_row = eleve_par_row;
    // la logique pour placer les élèves / occuper les places
    while (row_current <= row_max - 1) // on fait chaque rangée
    {
        // printf("%d, %d\n", row_current, row_max-1);
        if (eleve_par_row == col_max)
        {
            for (int i = 0; i < col_max; i++)
            {
                p[row_current][i].occupe = 1;
            }
        }
        else // eleves_par_row : nb de gens qu'on dois placer ; col_max : longueur
        {
            p[row_current][0].occupe = 1;
            temp_nb_eleves_par_row--;
            for (int i = 1; i <= eleve_par_row; i++)
            {
                int taille = col_max - 1; // on enlève l parceque on a dejà placé le mec au début
                int espacement = taille / eleve_par_row;
                p[row_current][espacement * i].occupe = 1;
                if (temp_nb_eleves_par_row != 1)
                {
                    temp_nb_eleves_par_row--;
                }
            }
        }
        row_current++;
        temp_nb_eleves -= eleve_par_row;
        if (row_max - row_current > 0)
            eleve_par_row = temp_nb_eleves / (row_max - row_current);
        temp_nb_eleves_par_row = eleve_par_row;
    }
}

void afficher_plan(Place p[100][100], int row_max, int col_max)
{
    if (p == NULL)
    {
        printf("Erreur\n");
        return;
    }
    for (int i = 0; i < row_max; i++)
    {
        for (int j = 0; j < col_max; j++)
        {
            if (p[i][j].occupe)
            {
                printf("o");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}