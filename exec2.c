#include <stdio.h>

int main() {
    char tab[10];
    
    for (int i = 0; i < 10; i++) {
        tab[i] = i;  
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n",tab[i]);  
    }
    printf("fait\n");
    return 0;
}
/*
on remplace int tab[5] par char tab[10]
*/