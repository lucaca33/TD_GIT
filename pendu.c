#include <stdio.h>

int main()
{

    char perdu1[] = "\n\n\n\n\n\n\n-------\n";
    char perdu2[] = "\n |\n |\n |\n |\n |\n |\n-------\n";
    char perdu3[] = " -------\n | |\n |\n |\n |\n |\n-------\n";
    char perdu4[] = " -------\n | |\n | O\n |\n |\n |\n-------\n";
    char perdu5[] = " -------\n | |\n | O\n | |\n |\n |\n-------\n";
    char perdu6[] = " -------\n | |\n | O\n | /|\\\n |\n |\n-------\n";
    char perdu7[] = " -------\n | |\n | O\n | /|\\\n | / \\\n |\n-------\n";
    char mot[30];
    printf("Choisir le mot cache (PAS DE D'ACCENT) --> ");
    scanf("%29s", &mot);
    int len;
    // cacher le mot
    for (int i = 0; i < 18; i++)
    {
        printf("\n");
    }
    for (int i = 0; i < 30; i++)
    {
        if (mot[i] == ' ' || mot[i] == '\0')
        {
            len = i;
        }
    }
    char brouille = '_';
    char mot_brouille[len];
    mot_brouille[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        mot_brouille[i] = brouille;
    }
    int run = 1;
    char ljoueur;
    int indice_mot, essai_reussi, perdunumero;
    perdunumero = 0;
    while (run == 1)
    {
        printf("Rentre une lettre pour voir si elle est dans le mot --> ");
        scanf(" %1c", &ljoueur);
        getchar();
        getchar();
        essai_reussi = 0;
        for (int i = 0; i < len; i++)
        {
            // on check chaque lettre voir si on touche
            if (mot[i] == ljoueur && mot_brouille[i] == brouille)
            {
                mot_brouille[i] = ljoueur;
                essai_reussi = 1;
            }
        }
        if (essai_reussi == 1)
        {
            printf("Touche ! La lettre %c est dans le mot", ljoueur);
        }
        else
        {
            printf("sal nul la lettre %c est pas dedans", ljoueur);
            perdunumero += 1;
            printf("\n");
            switch (perdunumero)
            {
            case 1:
                printf("=====");
                printf("%s", perdu1);
                printf("=====");
                break;
            case 2:
                printf("=====");
                printf("%s", perdu2);
                printf("=====");
                break;
            case 3:
                printf("=====");
                printf("%s", perdu3);
                printf("=====");
                break;
            case 4:
                printf("=====");
                printf("%s", perdu4);
                printf("=====");
                break;
            case 5:
                printf("=====");
                printf("%s", perdu5);
                printf("=====");
                break;
            case 6:
                printf("=====");
                printf("%s", perdu6);
                printf("=====");
                break;
            case 7:
                printf("=====");
                printf("%s", perdu7);
                printf("=====");
                break;
            default:
                break;
            }
        }
        printf("\n%s\n",mot_brouille);
        printf("\n");
    }

    return 0;
}