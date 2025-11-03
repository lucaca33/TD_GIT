#include <stdio.h>

int main() {
    int i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i += 1;
    }
    return 0;
}
/*
la condition de sortie est i >= 10 mais on ne change jamais la valeur de i donc on reste dans la boucle indéfiniment

correction : on ajoute i += 1;
*/