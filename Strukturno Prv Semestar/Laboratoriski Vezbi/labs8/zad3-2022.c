#include <stdio.h>

int form(int n, int i){
    if(n == 0){ return 0; }
    if(i > n){ n--; i=1 ; printf("\n"); }
    if(n != 0){ printf("*"); }
    form(n, i+1);
}

int main(){ int n; scanf("%d",&n); form(n,1); return 0; }
