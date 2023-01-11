#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str){
    for(int i=0; i<strlen(str); i++){
        if(str[i] != str[strlen(str) - i - 1]){ return 0; }
    } return 1;
}

int specialChar(char *str){
    for(int i=0; i<strlen(str); i++){
        if((str[i] >= 'a' && str[i] <= 'z' ) || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')){ return 1; }
    } return 0;
}

int main(){
    int num, max = -1; scanf("%d", &num); char strSave[1024];
    for(int i=0; i<num; i++){
        char str[1024]; scanf("%s", str);
        if(isPalindrome(str) && specialChar(str) && strlen(str) > max){ strcpy(strSave, str); max = strlen(str); }
    }

    max == -1 ? printf("Nema!\n") : printf("%s\n", strSave);
    return 0;
}