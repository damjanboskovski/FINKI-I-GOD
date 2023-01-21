#include <stdio.h>
#include <string.h>

void transform(char *str, int x){
    if(*str == '\0'){ return; }
    if(*str >= 'a' && *str <= 'z'){ *str = (*str - 'a' + x) % 26 + 'a'; }
    else if( *str >= 'A' && *str <= 'Z'){ *str = (*str - 'A' + x) % 26 + 'A'; }
    transform(str + 1, x);
}

int main(){
    int n, x; scanf("%d %d", &n, &x); char str[1024]; getchar();
    for(int i=0; i<n; i++){ fgets(str, sizeof(str), stdin); transform(str, x); printf("%s", str); }  return 0;
}