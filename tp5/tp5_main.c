#include "tp5.h"
#include <Windows.h>

int main(){
    system("cls"); // clear le cmd
    int conso[7] = {0};
    int choix = 0;
    while (choix != 3)
    {
        menu_print();
        choix = menu_choix();
        switch (choix)
        {
        case 1:
            printf("choix n1\n");
            break;
        case 2:
            printf("choix n2\n");
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