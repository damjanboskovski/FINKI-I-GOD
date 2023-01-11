#include <stdio.h>
#include <stdlib.h>

int recursionTest(int n){
    if(n==0){return 1;}
    if(n>=10){if((n/10)%10>= n%10){return 0;} }
    recursionTest(n/10);
}

int main()
{
    int n,m; scanf("%d",&n);
    while(n){scanf("%d",&m);
    if(recursionTest(m)==1){printf("DA\n");}
    else printf("NE\n"); n--; }
    return 0;
}
