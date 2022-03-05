#include <stdio.h>
#include <math.h>

int brojac(int num){int br1=0; while(num){br1++;num/=10;}return br1;}

int main(){
    int num,num2=0,br2=0; scanf("%d",&num);
    int br = ((num==0)?1:log10(num)+1);

    while(br){ int broj = num / (int)pow(10,br-1) % 10;
    if(broj==5){br2++; broj+=1;}
    num2=num2*10+broj; broj--;
    }   

    if(br2<2){printf("Error"); return 0;}

    int temp=num;if(num<num2){num=num2; num2=temp;}
    printf("%.04lf%%",((num-num2)/(float)temp)*100);
    
    
    return 0;
    }

    
