#include "tp5.h"
#include <Windows.h>

int main()
{
    system("cls"); // clear le cmd
    utf8();
    int conso[7];
    int objectif[7] = {8, 0, 0, 0, 5, 3, 2};
    int choix = 0;
    if (charger(conso) == 0)
    {
        printf("Aucune sauvgarde trouvée\n");
        inititaliser(conso);
    }
    else{
        printf("Chargement réussi\n");
    }
    while (choix != 4)
    {
        menu_print();
        choix = menu_choix();
        
        switch (choix)
        {
        case 1:
            ajouterConsommation(conso);
            break;
        case 2:
            afficheResume(conso);
            break;
        case 3:
            afficher_objectifs(conso, objectif);
            break;
        case 4:
            if (sauvegarder(conso) == 0){
                printf("Sauvegarde échoué\n");
            }
            else{
                printf("Sauvegarde réussie");
            }
            break;

        default:
            printf("choix non reconnu\n");
        }
    }
    return 0;
}