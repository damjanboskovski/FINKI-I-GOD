#include <stdio.h>

int flipNum(int num, int rev){
    if(num == 0){ return rev; }
    rev = rev * 10 + (num%10);
    return flipNum(num/10,rev);
}

int counter(int num){
    int cnt=0; while(num){ cnt++;num/=10; } return cnt;
}

int main(){
    int num; scanf("%d",&num); num--;
    while(num<9){printf("Brojot ne e validen"); return 0;}
    while(flipNum(num,0) % counter(num) != 0){ num--; }
    printf("%d", num); return 0;
}