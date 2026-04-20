#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

int saisir_medoc(medicament *tab, int max)
{
    if (tab == NULL)
    {
        return 0;
    }
    

    int i = 0;
    int choix = 1;

    while (i < max && choix == 1)
    {
        printf("rentrer nom medicament : ");
        fgets(tab[i].nom, 256, stdin);
        printf("rentrer code medicament (pas d'espace) : ");
        scanf("%s", &tab[i].code);
        printf("rentrer date fabrication medicament (ANNEE-MOIS-JOUR) : ");
        scanf("%s", &tab[i].date_fabrication);
        printf("rentrer date peremption medicament (ANNEE-MOIS-JOUR) : ");
        scanf("%s", &tab[i].date_peremption);

        printf("rentrer prix (nombre entier) : ");
        scanf("%d", &tab[i].prix);
        printf("rentrer nombre de vente : ");
        scanf("%d", &tab[i].nb_vente);
        printf("rentrer nombre de stock : ");
        scanf("%d", &tab[i].nb_stock);
        i++;
        printf("Ajouter nouveau medicament (1 : oui, 0: non)?");
        scanf("%d", &choix);
    }
    if (choix)
    {
        printf("Plus d'espace pour de nouveaux medicaments");
    }
    return i;
}

//fonctions du cours, revisitée
void swap(medicament *xp, medicament *yp) {
    medicament temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(medicament *tab, int n) {
    if (tab == NULL)
    {
        return;
    }
    
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(tab[j].date_fabrication, tab[j + 1].date_fabrication)>0) {
                swap(&tab[j], &tab[j + 1]);
                swapped = 1;
            }
            //printArray(arr, n);
        }
        //printf("\n");
        // si il n'y a pas eu de swap dans la boucle interne, on break
        if (swapped == 0)
            break;
    }
}

int main()
{

    int taille = 80;
    medicament *tab_medoc = malloc(sizeof(medicament) * taille);

    int vrai_taille = saisir_medoc(tab_medoc, taille);

    printf("aa %s aa %d", tab_medoc[0].nom, tab_medoc[0].prix);

    bubbleSort(tab_medoc, vrai_taille);

    printf("aa %s aa %d", tab_medoc[0].nom, tab_medoc[0].prix);

    return 0;
}