#include <stdio.h>

int main(){
    int taille;
    printf("Saisissez une taille n (5 <= n <= 10) : ");
    scanf("%d", &taille);
    int width = taille*taille;
    int max_height = taille * 3 - 1;
    char img[112][30];
    for (int i = 0; i < 111; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            img[i][j] = ' ';
        }
    }
    for (int i = 0; i < 111; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            printf("%c", img[i][j]);
        }
    }
    
    return 0;
}