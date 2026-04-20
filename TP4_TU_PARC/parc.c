#include "parc.h"

File* creerFile()
{
	File* f = malloc(sizeof(File));
	if (f == NULL)
		return NULL;
	f->premier = NULL;
	f->dernier = NULL;

	return f;
}

Groupe* creerGroupe(int taille)
{
	Groupe* g = malloc(sizeof(Groupe));
	if (g == NULL)
		return NULL;

	g->suivant = NULL;
	g->taille = taille;

	return g;
}

void ajouterGroupeDansFile(Groupe* g_ajout, File* file)
{
	if (g_ajout == NULL || file == NULL)
		return;

	if (file->premier == NULL)
		file->premier = g_ajout;

	else if (file->dernier == NULL)
	{
		file->premier->suivant = g_ajout;
		file->dernier = g_ajout;
	}
	else
	{
		file->dernier->suivant = g_ajout;
		file->dernier = g_ajout;
	}
}

void deplacerPremierEnDernier(File* file)
{
	if (file == NULL)
		return;

	if (file->premier == NULL || file->dernier == NULL)
	{
		return;
	}
	file->dernier->suivant = file->premier;
	file->dernier = file->dernier->suivant;

	file->premier = file->premier->suivant;
	file->dernier->suivant = NULL;
	
}

void afficherFile(File* f)
{
	if (f == NULL)
		return;

	Groupe* temp = f->premier;
	int i = 1;
	while (temp != NULL)
	{
		printf("Groupe %d : %d \n", i, temp->taille);
		temp = temp->suivant;
		i++;
	}
}

long long int gains(File* file, const int C, const int L, const int N)
{
	if (file == NULL)
		return 0;

	long long int gain = 0;

	Groupe* courant = file->premier;
	if (courant == NULL)
		return;

	for (int i = 0; i < C; i++)
	{
		int nb_places_restantes = L;
		int j = 0;
		while (nb_places_restantes > 0 && j<N)
		{
			if (courant->taille <= nb_places_restantes)
			{
				gain += courant->taille;
				nb_places_restantes -= courant->taille;
				deplacerPremierEnDernier(file);
				courant = file->premier;
				j++;
			}
			else
			{
				break;
			}

		}

	}
	return gain;
}

