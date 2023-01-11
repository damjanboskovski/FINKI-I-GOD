#include <stdio.h>
#include <stdlib.h>

int recursiveFunction(int num){
    if(num==0){return 1;}
    if(num>10){
        if((num/10)%10 <= num%10){return 0;} }

    recursiveFunction(num/10);
}

int main()
{
    int n,m; scanf("%d",&n);
    while(n){scanf("%d",&m);
        printf("%d\n",recursiveFunction(m)); n--;}
    return 0;
}
