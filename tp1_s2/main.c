#include "main.h"
#include <stdlib.h>

void utf8()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8"); // ou ".65001" si ".UTF-8" ne passe pas
}

void demander_range(){
    printf("Entrez nb rangée");
}

void demander_table(){

}

int main(){
    return 0;
}