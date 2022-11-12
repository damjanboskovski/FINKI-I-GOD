#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, s, m, k; scanf("%d %d %d %d", &n, &s, &m, &k);
    int leftOver = ( m / 100 ) % 10, leftOverTwo = (k / 100) % 10;
    (n - leftOver > 0) ? ((((n - leftOver) + s) - leftOverTwo) >= 0 ? printf("1") : printf("0")) : printf("-1");
    return 0;
}
