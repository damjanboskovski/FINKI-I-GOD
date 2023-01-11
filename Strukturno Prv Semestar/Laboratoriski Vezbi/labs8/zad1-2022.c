#include <stdio.h>

int divisibleByK(int num, int k){
    if(num % k == 0){ return 1; }
    else { return 0; }
}

int nextDivisibleByK(int num, int k){
    if(divisibleByK(num, k) == 1){ return num; }
    return nextDivisibleByK(num + 1, k); 
}

int main() {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);

    for (int i = a; i <= b; i++) {
        printf("%d -> %d\n", i, nextDivisibleByK(i+1, k));
    }

    return 0;
}
