#include <stdio.h>

int main()
{
    char plateau[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int joueur = 1;
    int winner_trouve = 0; // 0 pour non et 1 pour oui
    char coup[4];
    while (winner_trouve == 0)
    {
        printf("Joueur %d, entrez votre position (ligne colonne) : ", joueur);
        fgets(coup, 4, stdin); // sa marche

        char point = ' ';
        char winner = ' ';
        for (int i = 0; i < 3; i++)
        {
            // les lignes
            if (plateau[i][0] == ' ')
            {
                point = 'r'; // un truc au pif : dans tout les cas il y a pas de gagnants ici
            }
            else{
                point = plateau[i][0] ;
            }

            if (plateau[i][1] == point && plateau[i][0] == point)
            {
                winner = point;
            }
            // les colonnes
            if (plateau[0][i] == ' ')
            {
                point = 'r'; // un truc au pif : dans tout les cas il y a pas de gagnants ici
            }
            else{
                point = plateau[i][0] ;
            }
            if (plateau[1][i] == point && plateau[1][i] == point)
            {
                winner = point;
            }
            // diagonale n 1
            if (plateau[0][0] == ' ')
            {
                point = 'r'; // un truc au pif : dans tout les cas il y a pas de gagnants ici
            }
            else{
                point = plateau[i][0] ;
            }
            if (plateau[1][1] == point && plateau[2][2] == point)
            {
                winner = point;
            }
            // diagonale n 2
            if (plateau[2][0] == ' ')
            {
                point = 'r'; // un truc au pif : dans tout les cas il y a pas de gagnants ici
            }
            else{
                point = plateau[i][0] ;
            }
            if (plateau[1][1] == point && plateau[0][2] == point)
            {
                winner = point;
            }
        }
        // on dit égalité
        if (winner == 'O' || winner == 'X')
        {
            winner_trouve = 1; // sa vas sortir de la boucle
        }

        int case_restante = 0;
        // case jouable check, sinon egalité
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (plateau[i][j] == ' ')
                {
                    winner_trouve = 1; // sa vas sortir de la boucle
                }
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
    }

    return 0;
}