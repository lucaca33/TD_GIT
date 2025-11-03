#include <stdio.h>

int main() {
    int a;
    int b = 10;
    printf("%d\n", b);
    return 0;
}
/*
compil3.c:5:5: error: 'b' undeclared (first use in this function)
     b = 10;
     ^

correction : int b = 10;
*/