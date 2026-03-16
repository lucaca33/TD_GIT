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

void init_tab(song** Tab_song);

int load_songs(char filename[256], song** Tab_song);

void melanger_chansons(...);
void charger_scores(...);
void update_score(...);
void sauver_scores(...);

#endif