#include <stdio.h>

int main(){
    int num1,num2,temp; scanf("%d%d",&num1,&num2);

    while(num1){
        temp=num2; 
        int br=num1%10, br2=0;
        while(temp){if(temp%10==br){br2=1;}temp/=10; }
        if(br2==0){printf("NE"); return 0;} num1/=10;
    }

    printf("DA");

    return 0;
}