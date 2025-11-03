#include <stdio.h>

int main() {
    char s[6] = "Hello";
    printf("%s\n", s);
    return 0;
}
/*
erreur ligne 4 : "a value of type "char [6]" cannot be used to initialize an entity of type "char [3]"

donc on met une taille de 6 pour la variable char s
*/