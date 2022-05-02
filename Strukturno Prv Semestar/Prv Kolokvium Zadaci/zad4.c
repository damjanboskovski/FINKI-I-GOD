#include <stdio.h>
#include <ctype.h>

int main(){
    char c; int num=0,sum=0;
    while(c!='!'){
        scanf("%c",&c); 
        if(isdigit(c)){num = num*10 + c - '0';}
        else{ sum+= num; num=0; }
    } 
    printf("%d",sum); return 0;
}