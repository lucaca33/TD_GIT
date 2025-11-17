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

    // la pointe de l'étoile
    for (int i = 0; i < taille; i++)
    {
        if (i == taille - 1)
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

    // le corps central de l'étoile
    for (int i = taille; i < taille * 2 - 2; i++)
    {
        int taille_base = 2 * i - 2 * taille;
        for (int j = taille_base; j < width - taille_base; j++)
        {
            img[i][j] = 'S';

            if (j == taille_base || j == width - taille_base - 1)
            {
                img[i][j] = '.';
                img[i][taille_base+1] = 'V';
                img[i][width - taille_base-2] = 'V';
            }
        }
    }

    // les jambes
    int k = taille * 2 - 2; // sert pour avoir le vrai indice i
    for (int i = 0; i < taille + 1; i++)
    {
        // on remplis l'intérieur de S
        for (int j = 0; j < width; j++)
        {
            img[k][j] = 'S';
        }
        // les bords
        for (int j = 0; j < 2 * taille - 4 - i; j++)
        {
            img[k][j] = ' ';
            img[k][width - j - 1] = ' ';
            if (j == 2 * taille - 5 - i)
            {
                img[k][width - j - 1] = '.';
                img[k][j] = '.';
            }
        }
        // le centre
        for (int j = mid - 2 * i; j < mid; j++)
        {
            img[k][j] = ' ';
            img[k][width - j - 1] = ' ';
            img[k][mid] = ' ';
            if (j == mid - 2 * i)
            {
                img[k][width - j - 1] = '\"';
                img[k][j] = '\"';
            }
        }

        k++;
    }

    // dessiner l'étoile
    for (int i = 0; i < max_height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}