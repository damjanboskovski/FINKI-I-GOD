#include <stdio.h>

int sum(int num){int sum=0; while(num){sum+=num%10;num/=10;} return sum;}

int main(){
    int numA,numP,br=0;
    scanf("%d%d",&numA,&numP);

    for(int i=numA;i>0;i--){
        if(br<5){ if ((((sum(i) / (float)i) * 100 )) == numP){br++; printf("%d\n",i);}
        }

    }
    if(br==0){printf("NEMA");}

    return 0;
}