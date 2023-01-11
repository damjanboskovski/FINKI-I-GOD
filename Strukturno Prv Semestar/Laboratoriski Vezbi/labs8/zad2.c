#include <stdio.h>
#include <stdlib.h>

int test(int num, int k, int sum){
    if(num==0){return sum;}
    int temp=num,n=1;
    while (temp>10){n*=10; temp/=10;}
    if((num/n)%10 > k){printf("%d",num/n%10); sum+=(num/n)%10;}
    return test(num-(num/n)*n,k,sum);
}
int main()
{
    int k,n; scanf("%d %d",&k, &n); int num;

    while(n){scanf("%d",&num);
    int sum = test(num,k,0);
    printf(" : %d\n",sum);n--;}
    return 0;
}
