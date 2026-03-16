#include "blindtest.h"

/* -------------------------------------------------- */
/* OUTILS SUR LES CHAINES                             */
/* -------------------------------------------------- */

/* Supprime les caractères de fin de ligne (\n ou \r) d'une chaîne */
void trim_newline(char *s)
{
    size_t len = strlen(s);

    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
    {
        s[len - 1] = '\0';
        len--;
    }
}

/*
Normalise une chaîne :
- supprime les espaces inutiles
- convertit en minuscules
Permet de comparer deux réponses sans tenir compte
des majuscules et des espaces.
*/
void normalize_string(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    int prev_space = 0;

    while (src[i] != '\0' && isspace((unsigned char)src[i]))
    {
        i++;
    }

    while (src[i] != '\0')
    {
        unsigned char c = (unsigned char)src[i];

        if (isspace(c))
        {
            prev_space = 1;
        }
        else
        {
            if (prev_space && j > 0)
            {
                dest[j++] = ' ';
            }
            dest[j++] = (char)tolower(c);
            prev_space = 0;
        }

        i++;
    }

    dest[j] = '\0';
}

/*
Compare deux chaînes après normalisation.
Retourne 1 si elles sont équivalentes, sinon 0.
*/
int string_equals_normalized(const char *a, const char *b)
{
    char na[256];
    char nb[256];

    normalize_string(na, a);
    normalize_string(nb, b);

    return strcmp(na, nb) == 0;
}

/* -------------------------------------------------- */
/* GESTION AUDIO                                      */
/* -------------------------------------------------- */

/*
Lance la lecture d'un extrait audio avec ffplay.
start = instant de départ
seconds = durée de l'extrait
*/
void play_song_excerpt_at(const char *filename, int start, int seconds)
{
    char command[1024];

    snprintf(command, sizeof(command),
             "ffplay -nodisp -autoexit -loglevel quiet -ss %d -t %d \"%s\"",
             start, seconds, filename);

    system(command);
}

/*
Charge les morceaux depuis songs.txt dans un tableau.
Retourne le nombre de morceaux chargés.
*/
int load_songs(char filename[256], song *Tab_song, int *max_song_nb)
{

    if (Tab_song == NULL || max_song_nb == NULL)
    {
        return 0;
    }

    FILE *f;
    char line[3 * 256];
    int count = 0;

    f = fopen(filename, "r");
    if (f == NULL)
    {
        perror("Erreur ouverture songs.txt");
        return -1;
    }

    while (fgets(line, sizeof(line), f) != NULL && count < 100)
    {
        char *file;
        char *title;
        char *artist;

        trim_newline(line);

        if (strlen(line) == 0)
        {
            continue;
        }

        file = strtok(line, ";");
        title = strtok(NULL, ";");
        artist = strtok(NULL, ";");

        if (file == NULL || title == NULL || artist == NULL)
        {
            printf("Ligne ignoree dans songs.txt.\n");
            continue;
        }
        // on rajoute dans un tableau de song les infos du son chargé

        if (max_song_nb >= count)
        {
            (*max_song_nb) *= 2;
            Tab_song = realloc(Tab_song, sizeof(song) * (*max_song_nb));
        }

        strcpy(Tab_song[count].chemin, file);
        strcpy(Tab_song[count].title, title);
        strcpy(Tab_song[count].artist, artist);

        count++;
    }

    fclose(f);
    return count;
}

/* -------------------------------------------------- */
/* PROGRAMME PRINCIPAL                                */
/* -------------------------------------------------- */

void init_tab(song *Tab_song, int size)
{
    if (Tab_song == NULL)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        strcpy(Tab_song[i].chemin, "");
        strcpy(Tab_song[i].title, "");
        strcpy(Tab_song[i].artist, "");
    }
}

void melanger_chansons(song* Tab_song, int size){
    if (Tab_song == NULL)
    {
        return;
    }
    
    
    int i1 = 0;
    int i2 = 1;
    
    song temp;

    for (int i = 0; i < 3*size; i++) // comme ça on est sur que a peu près tout est randomisé
    {
        i1 = rand()%size;
        i2 = rand()%size;

        temp = Tab_song[i1];
        
        Tab_song[i1] = Tab_song[i2];
        Tab_song[i2] = temp;
    }
}


int main()
{
    srand(time(NULL));

    int max_song_number = 100;

    song *tab_son = malloc(sizeof(song) * max_song_number); // on crée un tableau de 100 chansons

    int num_songs_loaded = load_songs("songs.txt", tab_son, &max_song_number); // remplissage du tableau

    melanger_chansons(tab_son, num_songs_loaded);

    

    return 0;
}