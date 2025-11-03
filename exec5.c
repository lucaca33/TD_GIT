#include <stdio.h>

int main() {
    char s[5];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'y';
    s[3] = '!';
    s[4] = '\0';
    printf("%s\n", s); 
    return 0;
}

/*
On rajoute la ligne :
s[4] = '\0';
car il manque le charactère de fin
*/