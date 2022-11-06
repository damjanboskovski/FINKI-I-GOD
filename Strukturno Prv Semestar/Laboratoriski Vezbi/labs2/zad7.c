#include<stdio.h>

int main(){
    int num,trans; scanf("%d",&num);
    for(int i=0;i<5;i++){ scanf("%d",&trans); num += trans; }
    printf("%d", num>0);
    return 0;
}