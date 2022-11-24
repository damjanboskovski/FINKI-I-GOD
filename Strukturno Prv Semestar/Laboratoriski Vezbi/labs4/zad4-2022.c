#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int min = b, max = 0, minBr = 0, maxBr = 0;

    for (int i = a + 1; i < b; i++){ int cnt = 0;
        for (int j = 1; j < i; j++) { i % j == 0 ? ++cnt : 0; }

        cnt >= max ? max = cnt, maxBr = i : 0;
        cnt <= min ? min = cnt, minBr = i : 0;
    }

    printf("Min: %d\nMax: %d", minBr, maxBr);
}