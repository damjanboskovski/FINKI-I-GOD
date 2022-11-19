#include <stdio.h>

int main(){
    int n, m, sum=0; scanf("%d %d", &n, &m);
    for(int i = n; i<m; i++){ i % 3 == 0 ? sum += i : 0; }
    printf("%d", sum);
}