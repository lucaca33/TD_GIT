#ifndef BLINDTEST
#define BLINDTEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct song
{
    char chemin[256];
    char title[256];
    char artist[256];
}song;

typedef struct joueur
{
    char nom[256];
    int score;
}joueur;
typedef struct liste_joueur
{
    char nom[256];
    int meilleur_score;
    joueur * 
}liste_joueur;



void init_tab(song* Tab_song);

int load_songs(char filename[256], song *Tab_song, int *max_song_nb);

void melanger_chansons(song* Tab_song, int size);
void charger_scores(...);
void update_score(...);
void sauver_scores(...);

#endif