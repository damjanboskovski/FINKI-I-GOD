#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; scanf("%d", &n);
    printf("%d", (n > -100 && n < 100) || (n >= 200 && n <  300));
    return 0;
}