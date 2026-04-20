#ifndef medicaments
#define medicaments

typedef struct medicament
{
    char nom[50];
    char code[30];
    char date_fabrication[30];
    char date_peremption[30];
    int prix;
    int nb_vente;
    int nb_stock;
}medicament;


#endif