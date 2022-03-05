#include <stdio.h>
int main(){
    float mass,height; scanf("%f %f",&mass, &height);
    float height_cm = height / 100;
    float bmi = mass/(height_cm*height_cm);
    printf("%.2f",bmi);
    
    return 0;
    }