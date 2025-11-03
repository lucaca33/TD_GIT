#include <stdio.h>

int main() {
    int x = 42;
    printf("%d\n", x);
    return 0;
}
/*
erreur : 
compil2.c: In function 'main':
compil2.c:4:13: warning: initialization makes integer from pointer without a cast [-Wint-conversion]
     int x = "42";
             ^~~~

correction : j'ai enlevé les guillemets
*/