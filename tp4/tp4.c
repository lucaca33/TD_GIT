#include <stdio.h>

void afficherMenu()
{
    printf("===== GESTION DES NOTES =====\n");
    printf("1. Saisir le nombre d'eleves\n");
    printf("2. Saisir les notes des eleves\n");
    printf("3. Afficher toutes les notes\n");
    printf("4. Afficher le moyenne d'un eleve\n");
    printf("5. Afficher le moyenne generale\n");
    printf("6. Afficher le meilleure note de chaque controle\n");
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
        }
    }
}

int main()
{
    int nb_eleves = 0;
    int note_eleves[30][3];
    afficherMenu();
    int choix = lireChoix();
    
    switch (choix)
    {
    case 1:
        nb_eleves = saisirNombreEleves(note_eleves);
        break;
    case 2:
        saisirNotes(note_eleves, nb_eleves);
        break;
    case 3:
        saisirNombreEleves(note_eleves);
        break;
    case 4:
        saisirNombreEleves(note_eleves);
        break;
    }
    return 0;
}