#include "tp5.h"
#include <Windows.h>

int main()
{
    system("cls"); // clear le cmd
    utf8();
    int conso[7];
    int choix = 0;
    if (charger(conso) == 0)
    {
        printf("Aucune sauvgarde trouvée\n");
        inititaliser(conso);
    }
    else{
        printf("Chargement réussi\n");
    }
    while (choix != 3)
    {
        menu_print();
        choix = menu_choix();
        printf("%d", choix);
        
        switch (choix)
        {
        case 1:
            ajouterConsommation(conso);
            break;
        case 2:
            afficheResume(conso);
            break;
        case 3:
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