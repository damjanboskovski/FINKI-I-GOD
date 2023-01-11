#include <stdio.h>
#include <stdlib.h>

int proizvod(int n, int i, int sum){
    if(n==0){return sum;}
    if(i%2==0){sum*=n%10;}
    proizvod(n/10,i+1,sum);
}

int main()
{
    int n; scanf("%d",&n);
    printf("%d",proizvod(n,1,1));
    return 0;
}
