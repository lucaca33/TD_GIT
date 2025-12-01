#include "tp5.h"
#include <Windows.h>

int main()
{
    system("cls"); // clear le cmd
    utf8();
    int conso[7];
    int choix = 0;
    inititaliser(conso);
    charger(conso);
    while (choix != 3)
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
            printf("choix n3\n");
            break;

        default:
            printf("choix non reconnu\n");
        }
    }
    return 0;
}