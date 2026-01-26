#include "main.h"


int main(){
    utf8();
    int nb_rangee = demander_range();
    int nb_table = demander_table();
    char chemin[25];
    demander_chemin_fichier(chemin);
    printf("fichier : %s", chemin);
    Eleve eleve[50];
    int nb_eleve = lire_fichier(chemin, eleve);
    Place places[100][100];
    initialiser_places(places, nb_rangee, nb_table);
    placer_eleves(places, eleve, nb_rangee, nb_table, nb_eleve);
    afficher_plan(places, nb_rangee, nb_table);
    return 0;
}
