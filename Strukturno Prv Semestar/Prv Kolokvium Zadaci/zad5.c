#include<stdio.h>

int main(){
    int num1,num2,i = 1,temp;
    scanf("%d",&num1); scanf("%d",&num2);

    if(num1 <= 0 || num2 <= 0){printf("Invalid input"); return 0;}

    if(num2>num1){temp=num1;num1=num2;num2=temp;}
    while(num2){
        if(i%2==0){
            if(num1%10 != num2%10){
                printf("NE");
                return 0;
            }
            num2/=10;
        }
        num1/=10;
        i++;
    }
    printf("PAREN");
    return 0;
}