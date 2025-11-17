#include <stdio.h>

int main()
{
    char plateau[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int joueur = 1;
    char coup[4];
    printf("Joueur %d, entrez votre position (ligne colonne) : ", joueur);
    fgets(coup, 4, stdin); // sa marche

    char point = ' ';
    char winner = ' ';
    for (int i = 0; i < 3; i++)
    {
        // les lignes
        point = plateau[i][0];
        if (plateau[i][1] == point && plateau[i][0] == point)
        {
            winner = point;
        }
        // les colonnes
        point = plateau[0][i];
        if (plateau[1][i] == point && plateau[1][i] == point)
        {
            winner = point;
        }
        // diagonale n 1
        point = plateau[0][0];
        if (plateau[1][1] == point && plateau[2][2] == point)
        {
            winner = point;
        }
        // diagonale n 2
        point = plateau[2][0];
        if (plateau[1][1] == point && plateau[0][2] == point)
        {
            winner = point;
        }
    }
    // on dit égalité
    if (winner == ' ')
    {
        winner = 'e';
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

    return 0;
}