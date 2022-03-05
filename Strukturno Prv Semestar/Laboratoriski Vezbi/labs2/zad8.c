#include <stdio.h>
#include <ctype.h>

int main(){
    char string[4]; fgets(string,sizeof string, stdin);int l=0;

    while(string[l]!='\0'){
        if(isalnum(string[l])){printf("1");}
        else printf("0 ");l++;
    }
    printf("\n");l=0;
    while(string[l]!='\0'){
        if(isalpha(string[l])){printf("0");}
        else printf("1");l++; 
    }
    return 0;
}