#include <stdio.h>

int main(){
    float mass, height, heightConv;
    scanf("%f %f",&mass, &height); heightConv = height / 100;
    printf("%.2f",mass / (heightConv * heightConv));
    return 0;
    }