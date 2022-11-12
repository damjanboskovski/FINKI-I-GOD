#include<stdio.h>

int main(){
    int num, prod; scanf("%d",&num);
    for(int i = 0; i < 5; i++){ scanf("%d", &prod); num += prod; }
    printf("%d", num > 0);
    return 0;
}