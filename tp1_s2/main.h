#ifndef eleves
#define eleves
#include <windows.h> 
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Eleve
{
    char prenom[20];
    char nom[20];
}Eleve;

typedef struct Place
{
    int num_rangee;
    int num_table;
    int occupe; // 0 pour non occupé et 2 pour occupé
}Place;

void utf8();
int demander_range();
int demander_table();
void demander_chemin_fichier(char chemin[25]);
void lire_fichier(char c[25], Eleve eleve[50]);

#endif