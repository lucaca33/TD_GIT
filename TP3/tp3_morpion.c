#include <stdio.h>

int main()
{
    char plateau[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char winner = ' '; // 'N' pour égalité 'O' ou 'X' sinon
    int joueur = 1;
    char coup[4];
    int draw = 0;
    while (winner != 'X' && winner != 'O' && !draw) // oui
    {
        printf("=========winner : %c ==%d========= ", winner, draw);

        // check pour voir si jamais le mec a mis une case pas bonne/ mal écrit. Ex : "101" est ok mais "001" non et "1a3" ok
        int move_correct = 0;
        printf("==============\n");
        do // pour le faire au moins une fois, et continuer a le faire jusqu'a ce que la position est valide
        {
            printf("Joueur %d, entrez votre position (ligne colonne) : ", joueur);
            fgets(coup, 4, stdin); // sa marche
            if (coup[0] == '1' || coup[0] == '2' || coup[0] == '3')
            {
                if (coup[2] == '1' || coup[2] == '2' || coup[2] == '3')
                {
                    if (plateau[coup[0] - '0' - 1][coup[2] - '0' - 1] == ' ' || plateau[coup[0] - '0' - 1][coup[2] - '0' - 1] == '\0') // je sais pas pourquoi mais sa me dit que y'a un \0 parfois
                    {
                        move_correct = 1;
                    }
                    else
                    {
                        printf("Case  deja prise, ressayez");
                    }
                }
                else
                {
                    printf("Colonne non reconnue, ressayez\n");
                }
            }
            else
            {
                printf("Ligne non reconnue, ressayez\n");
            }
            printf("==============\n");
            getchar(); // vider le caractere \n
        } while (move_correct == 0);

        // mettre le move dans le tableau
        int ligne = coup[0] - '0' - 1; // vu que c'est en ascci : l'ordre est comme sa : '0' '1' '2' ect donc sa permet de transformer un char en nombre assez facilement, et on fait -1 pour avoir un index et 0 a 2
        int colonne = coup[2] - '0' - 1;
        if (joueur == 1)
        {
            plateau[ligne][colonne] = 'X';
            joueur = 2; // on switch le joueur
        }
        else
        {
            plateau[ligne][colonne] = 'O';
            joueur = 1; // on switch le joueur
        }

        // check egalité
        char winner = 'N';
        draw = 1;
        int case_restante = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (plateau[i][j] == ' ')
                {
                    winner = 'N'; // on sort pas, ya encore de move possibles
                    draw = 0;
                }
            }
        }
        // check des gagnants
        char point = 'r';
        int trouve = 0;
        // la boucle se répete 3 fois pour chaque ligne et colonne
        for (int i = 0; i < 3; i++)
        {
            // ligne
            if (plateau[i][0] == ' ' || plateau[i][0] == '\0')
            {
                point = 'r'; // caractère random, cette ligne ne peut pas faire gagner quelqu'un
            }
            else
            {
                point = plateau[i][0];
            }
            // on check voir si les deux autres sont les même que le premier
            for (int j = 0; j < 3; j++)
            {
                if (plateau[i][j] == point)
                {
                    winner = point;
                    trouve = 1; // on break pas : il faut vérifier que toute la ligne est bonne
                }
                else
                {
                    winner = ' ';

                    trouve = 0;
                    break; // on break parceque cette ligne ne peut plus gagner
                }
            }
            if (trouve) // si on a trouve un GAGNANT HEHEHEHEHE on sort de la boule
            {
                break;
            }
        }
        // afficher grille morpion
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != 2)
                {
                    printf(" %c |", plateau[i][j]);
                }
                else
                {
                    printf(" %c\n", plateau[i][j]);
                }
            }
            if (i != 2)
            {
                for (int j = 0; j < 11; j++)
                {
                    if (i == 4 || i == 7)
                    {
                        printf("|");
                    }
                    else
                    {
                        printf("-");
                    }
                }
            }
            printf("\n");
        }
        printf("=========winner : %c =========== ", winner);
    }

    switch (winner)
    {
        // c'est censé mettre n mais sa met un espace donc dans le doute je fait sa et sa marche
    case ' ':
        printf("Le match resulte en une egalite");
        break;
    case '\0':
        printf("Le match resulte en une egalite");
        break;
    case 'X':
        printf("Le gagnant est X (joueur 1)");
        break;
    case '0':
        printf("Le gagnant est 0 (joueur 2)");
        break;
    default:
        break;
    }
    return 0;
}