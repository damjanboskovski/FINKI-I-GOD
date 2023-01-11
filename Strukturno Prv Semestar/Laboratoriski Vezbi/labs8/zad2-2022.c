#include <stdio.h>

int reverseNumber(int num){ int rev = 0; while(num){ rev = rev * 10 + num % 10; num/=10; } return rev; }

int isPalindrome(int num){ return num == reverseNumber(num); }

int containsDigits(int num){
    if(num == 0){ return 1; }
    int digit = num % 10;
    if(digit < 0 || digit > 4){ return 0; }
    return containsDigits(num/10);
}

int main(){
    int n, m; scanf("%d %d", &n, &m);

    for(int i=n; i<=m; i++){ containsDigits(i) && isPalindrome(i) ? printf("%d\n",i): 0; }
}
