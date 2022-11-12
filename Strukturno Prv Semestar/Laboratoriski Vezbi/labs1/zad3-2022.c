#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m; scanf("%d %d", &n, &m);
    printf("Edinici: %d\n", n%10 + m%10);
    printf("Desetki: %d\n", n%100/10 + m%100/10);
    printf("Stotki: %d\n", n/100%10 + m/100%10);
    printf("Iljadarki: %d", n/1000%10 + m/1000%10);

    return 0;
}
