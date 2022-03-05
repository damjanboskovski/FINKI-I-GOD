#include <stdio.h>
#include <math.h>

int brojac(int num){int br=0; while(num){br++;num/=10;}return br;}


int main(){
    int num,sum=0,mult=1,prev=0,br=0; scanf("%d",&num);

    if(brojac(num) != 7){printf("Vneseniot broj ne e 7 cifren!");return 0;}
    
    while(num){ prev=prev*10 + (num%10); num/=10;}
    while(prev){ br=prev%10;prev/=10; printf("%d\n",br);
    sum+=br;mult*=br;}
    printf("%d\n%d\n",sum,mult);
    

    return 0;
}