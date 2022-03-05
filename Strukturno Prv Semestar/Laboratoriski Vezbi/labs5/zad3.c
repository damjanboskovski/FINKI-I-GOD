#include <stdio.h>

int main(){
    int num=1,br=0,sum;

    while(num< 90 && num > 0){
        br++; scanf("%d",&num);
        if(br<=7){sum=sum*10+num%10;}
        else if(num<=90 && num>=0){sum+=num;}
    }

    printf("%d",sum);

    return 0;
}