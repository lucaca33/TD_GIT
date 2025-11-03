#include <stdio.h>

// ici le comilateur ne dit malheureusement rien mais il devrait,
// executer pour essayer de comprendre ce qu'il se passe 
int main() {
    int tableau[6];
    int i = 12;
    for (int j = 0; j < 6; j++)
    {
        tableau[j] = 1;
    }
    printf("OK %d\n", tableau[5]);
    return 0;
}
/*
la variable tableau n'est pas assez grande : il faut lui mettre une taille de 6 et non 5
pas conséquent, on vas remplacer j < 5 par j < 6
*/