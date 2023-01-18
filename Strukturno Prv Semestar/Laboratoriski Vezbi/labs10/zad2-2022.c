#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 1024

int main(){
    int N, K, output = 0; char C, string[size];
    scanf("%d %d %c", &N, &K, &C); getchar();

    while(N){
        fgets(string, size, stdin); string[strlen(string) - 1] = '\0'; int cnt = 0;
        for(int i=0; i<strlen(string); i++){
            if(tolower(string[i]) == tolower(C)){ cnt++; }
        }
        if(cnt == K){ output = 1; printf("%s\n", string); } N--;
    }
    if(!output){ printf("NONE"); } return 0;
}