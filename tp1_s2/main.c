#include "main.h"


int main(){
    utf8();
    int nb_rangee = demander_range();
    int nb_table = demander_table();
    char chemin[25];
    demander_chemin_fichier(chemin);
    printf("fichier : %s", chemin);
    Eleve eleve[50];
    lire_fichier(chemin, eleve);
    return 0;
}