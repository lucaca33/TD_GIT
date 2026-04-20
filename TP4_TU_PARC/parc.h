#pragma once
#ifndef PARC
#define PARC

#include <stdio.h>
#include <stdlib.h>

typedef struct Groupe
{
	int taille;
	struct Groupe* suivant;
}Groupe;

typedef struct File
{
	Groupe* premier;
	Groupe* dernier;
}File;


File* creerFile();
Groupe* creerGroupe(int taille);

void ajouterGroupeDansFile(Groupe *g_ajout, File *file);

void deplacerPremierEnDernier(File *file);

void afficherFile(File* f);

long long int gains(File *file, const int C, const int L, const int N);


#endif