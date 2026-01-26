#ifndef eleves
#define eleves

typedef struct Eleve
{
    char prenom[20];
    char nom[20];
}Eleve;

typedef struct Place
{
    int num_rangee;
    int num_table;
    int occupe = 0; // 0 pour non occupé et 2 pour occupé
}Place;


#endif