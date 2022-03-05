#include<stdio.h>
int main(){
    float money,product; scanf("%f %f",&money,&product);   
    float tax = product * 1.18;


    if((money-tax)>=1){
        printf("1");
    }
    else printf("0");
    
    return 0;
}
