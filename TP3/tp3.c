#include <stdio.h>

int main()
{
    int taille;
    printf("Saisissez une taille n (5 <= n <= 10) : ");
    scanf("%d", &taille);
    int width = taille * taille;
    int max_height = taille * 3 - 1;
    char img[30][122];
    for (int i = 0; i < 29; i++)
    {
        for (int j = 0; j < 121; j++)
        {
            img[i][j] = ' ';
        }
    }

    int mid = width / 2;
    for (int i = 0; i < taille; i++)
    {
        if (i == taille-1)
        {
            for (int j = 0; j < width; j++)
            {
                img[i][j] = '_';
            }
        }
        for (int j = 0; j < i * 2 + 1; j++)
        {
            if (j == 0 || j == i * 2)
            {
                img[i][mid + (j - i)] = 'A';
            }
            else
            {
                img[i][mid + (j - i)] = 'S';
            }
        }
    }

    for (int i = 0; i < 29; i++)
    {
        for (int j = 0; j < 121; j++)
        {
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}