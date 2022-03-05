#include <stdio.h>

int main(){
    int num; scanf("%d",&num);
    printf("%d ",(num/10000)+(num%10));
    printf("%d ",((num/10)%10) + ((num/1000)%10));
    printf("%d", (num/100)%10);
    return 0;
}