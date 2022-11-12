#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k; scanf("%d %d %d",&n, &m, &k);
    int abs = (n + m + k) / 3;
    printf("%d m %d cm",abs/100%10, abs%100 );
    return 0;
}
