#include <stdio.h>

int softNumCheck(int n){
    if(n == 0){ return 0; }
    if(n % 2 != 0){ return 1; }
    else return softNumCheck(n/10);
}

int main(){
    int n, m; scanf("%d%d", &n, &m); int min=m,cnt = 0;
    for(int i=n; i<m; i++){ cnt++; softNumCheck(i) != 1 && i < min ? min = i:0; }
    min !=m || cnt == 1 ? printf("%d",min) : printf("NE");
    return 0;
}