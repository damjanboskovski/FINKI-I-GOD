#include <stdio.h>
int brojac(int num){
    int br=0; while(num){br++;num/=10;} return br;}

int main(){
    int num; scanf("%d",&num);

    int god=1000+(num%1000);
    int mes=(num/1000)%100;
    int den=(num/100000)%100;
    int sum=(den*100)+(mes*1000)+god;

    if(brojac(sum)!=5){
        if(god%100 > 60 && god%100 <= 80){sum+=80000;}
        if(god%100 > 80 && god%100 <= 99){sum+=90000;}
        else{sum+=70000;}
    }

    printf("%d",sum);

    return 0;
}