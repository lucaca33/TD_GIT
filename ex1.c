#include <stdio.h>

int main(){

    int sec;
    printf("combien de secondes ? ");
    scanf("%d",&sec);
    int h = sec /3600;
    int m = (sec-h*3600)/60;
    int s = (sec-h*3600-m*60);
    printf("%d secondes = %d heures, %d minutes, %d secondes", sec , h, m, s);
    return 0;

}