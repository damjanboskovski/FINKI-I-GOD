#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n, x; scanf("%lld %lld", &n,&x); int min = n+1;

    for(int i=n-1; i>=0; i--){
        long long int tempNum = x; int flag=0;
        while(tempNum){
            long long int tempCurr = i;
            while(tempCurr){
                if(tempNum%10 == tempCurr%10){ flag = 1; break; }
                tempCurr/=10;
            } tempNum/=10;  if(flag == 1){ break; }
        } if(flag==0){ min=i; break; }
    }

    printf("%d", min); return 0;
}
