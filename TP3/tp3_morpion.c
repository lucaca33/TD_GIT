#include <stdio.h>

int main()
{
    char plateau[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
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