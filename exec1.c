#include <stdio.h>

int main() {
    int a = 2;
    int b = 0;
    int c = 0;
    if (b == 0)
    {
        printf("erreur : division par 0\n");
    }
    else{
        c = a/b;
    }
    
    printf("%d\n", c);
    return 0;
}
/*
on peut pas diviser par 0 donc on crée un cas particulier ou on retourne un erreur
*/