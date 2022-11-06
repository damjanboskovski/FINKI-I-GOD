#include <stdio.h>
#include <ctype.h>

int main(){
    char c; int sum=0;
    while (c != '.') {
        scanf("%c", &c); c = toupper(c);
        ((int)c - '0') > 0 && !isdigit(c) ? sum += (int)c - '0' - 7:0;
        isdigit(c) ? sum += c - '0':0;
    }
    sum%16==0 ? (sum%10==6 && (sum/10)%10==1 ? printf("Poln pogodok") : printf("Pogodok")) : printf("%d", sum);
 
    return 0;
}

