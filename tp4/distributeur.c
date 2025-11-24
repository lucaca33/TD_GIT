#include <stdio.h>

void afficherMenu()
{
    printf("===== Banque - Distributeur =====\n");
    printf("1. Faire un retrait\n");
    printf("2. Quitter\n");
}
int lireChoix(){
    printf("Votre choix : ");
    int temp = 0;
    scanf("%d", &temp);
}

int main()
{
    int choix = -1;
    while (choix != 0)
    {
        afficherMenu();
        choix = lireChoix();
        printf("================\n");
        switch (choix)
        {
        case 1:
            break;
        case 2:
            break;
        }
    }
    return 0;
}