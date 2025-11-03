#include <stdio.h>

int main() {
    int t[3] = {10, 20, 30};
    int i = 2;
    printf("%d\n", t[i]); 
    return 0;
}
/*
on peut pas prendre -1 comme index et arriver au dernier élement du tableau en c donc on remplace le -1 par 2
*/