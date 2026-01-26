#include "main.h"

void utf8()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8"); // ou ".65001" si ".UTF-8" ne passe pas
}

int demander_range(){
    printf("Entrez le nombre de rangée : ");
    int temp = 0;
    scanf("%d", &temp);
    return temp;
}

int demander_table(){
    printf("Entrez le nombre de table : ");
    int temp = 0;
    scanf("%d", &temp);
    return temp;
}

void demander_chemin_fichier(char chemin[25]){
    if (chemin == NULL)
    {
        printf("PROBLEME");
        return;
    }
    
    printf("Entrez le chemin du fichier texte (il doit être au même niveau que l'exe)(ex : liste.txt) : ");
    scanf("%s", chemin);
}

void lire_fichier(char c[25], Eleve eleve[50]){
    FILE * fichier = fopen(c, "r");
    char line[256];
    char nom[128], prenom[128];
    int i = 0;
    while (fgets(line, sizeof(line), fichier))
    {
        if (sscanf(line, "%127s %127s", prenom, nom) == 2)
        {
            printf("%s, %s\n", prenom, nom);
            strcpy(eleve->nom, nom);
            strcpy(eleve->prenom, prenom);
        }
    }
    
    
}