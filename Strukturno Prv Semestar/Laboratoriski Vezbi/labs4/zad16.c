#include <stdio.h>

int prevBr(int num){int prev=0; while(num){prev=prev*10 + num%10; num/=10;} return prev; }


int main(){
    int m,n, br=0; scanf("%d %d",&m, &n);

    for(int i=m;i<=n;i++){
        if(i+prevBr(i) <= i*2){printf("%d\n",i); br++;}
    }

    printf("Vkupno: %d",br);
    return 0; 
}