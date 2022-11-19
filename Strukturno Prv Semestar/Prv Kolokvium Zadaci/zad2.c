#include <stdio.h>
#include <math.h>

int flipNum(int num, int rev){
    if(num == 0){ return rev; }
    rev = rev * 10 + (num%10);
    return flipNum(num/10,rev);
}

int main(){
    int n; scanf("%d", &n); n--;
    while(n<9){ printf("Brojot ne e validen"); return 0; }
    while(flipNum(n,0) % (int)(n==0?1:log10(n)+1) != 0){ n--; }
    printf("%d",n); return 0;
}
