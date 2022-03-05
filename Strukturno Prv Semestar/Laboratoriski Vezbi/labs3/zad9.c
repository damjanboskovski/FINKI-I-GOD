#include <stdio.h>

int main(){
    float num, sum=0; scanf("%f",&num);

    if(num>=500){sum+=5*500;} else {sum+=5*num;}
    num=num-500;

    if(num>0){if(num>=150){sum+=7.5*150;} else {sum+=7.5*num;}
    num=num-150;
        if(num>0){if(num>=200){sum+=11*200;} else{sum+=11*num;}
        num=num-200;
            if(num>0){sum+=13.5*num;}}}

    if(sum<7000){sum*=1.10;}
    if(sum>7000){sum*=1.18;}
    printf("%.2f",sum);

    return 0;
}