#include <stdio.h>
#include <stdlib.h>

int obratenBroj (int broj){
    int prev=0; while(broj){prev=prev*10+broj%10; broj/=10;} return prev;
}

int sumaNaCifri (int broj){
    int sum=0; while(broj){sum+=broj%10; broj/=10;} return sum;
}

void pecatiVoInterval (int a, int b){
    for(int i=a;i<=b;i++){
        if((i+obratenBroj(i)) % sumaNaCifri(i+obratenBroj(i))==0){printf("%d\n",i);}
    }
}

int main()
{
    int a, b; scanf("%d %d",&a,&b);
    pecatiVoInterval(a,b);
    return 0;
}
