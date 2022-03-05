#include<stdio.h>

int main(){
    int num,trans; scanf("%d",&num);
    for(int i=0;i<5;i++){
        scanf("%d",&trans); num = num + trans;
    }
    if(num>0){printf("1");}
    else printf("0");
    return 0;
}