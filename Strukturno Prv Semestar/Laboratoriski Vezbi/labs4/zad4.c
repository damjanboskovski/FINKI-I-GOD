#include <stdio.h>

int sum(int num){int sum=0; while(num){if((num%10)%2==0 && (num%10)%3 !=0){sum+=num%10;}num/=10;}return sum;}

int main(){
    int num1,num2,br=0; svanf("%d%d",&num1,&num2);

    for(int i=num1;i<=num2;i++){
        if(sum(i)>0 && sum(i)%7==0){
            br++; printf("%d\n",i);
        }
    }

    printf("Vkupno: %d", br);

    return 0;
}