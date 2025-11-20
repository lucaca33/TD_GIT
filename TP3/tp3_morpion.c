#include <stdio.h>

int main()
{
    char plateau[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char winner = ' '; // 'N' pour égalité 'O' ou 'X' sinon
    int joueur = 1;
    int winner_trouve = 0; // 0 pour non et 1 pour oui
    char coup[4];
    while (winner_trouve == 0)
    {
        // check pour voir si jamais le mec a mis une case pas bonne/ mal écrit. Ex : "101" est ok mais "001" non et "1a3" ok
        int move_correct = 0;
        printf("==============\n");
        do
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
                        printf("Case  deja prise, ressayez, %c %c, a%ca\n", coup[0], coup[2], plateau[coup[0]][coup[2]]);
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
        char winner = ' ';
        int case_restante = 0;
        winner_trouve = 1; // on sort de la boucle sauf si on trouve une case de libre
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (plateau[i][j] == ' ')
                {
                    winner = 'N';
                    winner_trouve = 0; // on reste dans la boucle, il y a encore un case a jouer (le cas d'un gagnant est traité plus tard)
                }
            }
        }
        if (winner_trouve != 1)
        {
            // check des gagnants
            char point = 'r';
            int trouve = 0;
            // la boucle se répete 3 fois pour chaque ligne et colonne
            for (int i = 0; i < 3; i++)
            {
                // ligne
                if (plateau[i][0] == ' ' || plateau[i][0] == '\0')
                {
                    char point = 'r'; // caractère random, cette ligne ne peut pas faire gagner quelqu'un
                }
                else
                {
                    char point = plateau[i][0];
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
            }
        }
        // sortir de la boucle en cas de gagnant
        if (winner == 'O' || winner == 'X')
        {
            winner_trouve = 1;
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
    }
    printf("winner:%ca", winner);
    switch (winner)
    {
    case 'N':
        printf("Le match resulte en une egalite");
        break;

    default:
        break;
    }

    return 0;
}