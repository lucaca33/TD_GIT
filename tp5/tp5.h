#ifndef fonct
#define fonct

#include <windows.h> 
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void utf8();
void menu_print();
int menu_choix();
void inititaliser(int conso[7]);
void ajouterConsommation(int conso[7]);
void afficheResume(int conso[7]);
int charger(int conso[7]);
int sauvegarder(int conso[7]);
int humeurBonbons(int nbBonbons);
int humeurLegumes(int nbLegumes);
int humeurFruits(int nbFruits);
void afficherBarre(int conso[7], int val, int max);
#endif