#include <stdio.h>

int main() {
    int x;
    x = 5;
    int y = x + 5;  
    printf("%d\n", y);
    return 0;
}
/*
on initialise pas la variable x et pourtant on l'utilise dans la déclaration de y
*/