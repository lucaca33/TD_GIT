#include <stdio.h>

int main() {
    int distance_km = 100;
    int vitesse_kmh = 50;
    float temps = distance_km / vitesse_kmh; 
    int minutes = temps * 60;
    printf("minutes = %d\n", minutes); 
    return 0;
}
/*
on remplace temps par un float
*/