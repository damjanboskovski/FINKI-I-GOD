#include <stdio.h>
#include <stdlib.h>

void print_N(int n,int i){
    if(i>n){return;}
    printf("%d",i);
    print_N(n,i+1);
}

void triagolnik(int n){
    if(n==0){return;}
    triagolnik(n-1);
    print_N(n,1);
    printf("\n");
}

int main()
{
    int n; scanf("%d",&n);
    triagolnik(n);
    return 0;
}
