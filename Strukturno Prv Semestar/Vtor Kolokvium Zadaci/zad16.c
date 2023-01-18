#include <stdio.h>

int maxNum(int num){
    if(num == 0){ return 0; }
    return num%10 > maxNum(num/10) ? num%10 : maxNum(num/10);
}

int main(){ int num; while(scanf("%d", &num)){ printf("%d\n", maxNum(num)); } return 0; }