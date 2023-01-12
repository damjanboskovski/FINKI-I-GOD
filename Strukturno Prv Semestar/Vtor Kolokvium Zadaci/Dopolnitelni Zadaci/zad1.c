#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 81

int isPalindrome(char *str){
    for(int i=0; i<strlen(str)/2; i++){
        if(str[i] != str[strlen(str) - i - 1]){ return 0; }
    } return 1;
}

int specialChar(char *str){
    for(int i=0; i<strlen(str); i++){
        if(!isalnum(str[i])){ return 1; }
    } return 0;
}

int main(){
    int num; scanf("%d", &num); char strSave[size] = "";
    for(int i=0; i<num; i++){
        char str[size]; scanf("%s", str);
        if(isPalindrome(str) && specialChar(str) && strlen(str) > strlen(strSave)){ strcpy(strSave, str); }
    }

    strlen(strSave) == 0 ? printf("Nema!\n") : printf("%s\n", strSave);
    return 0;
}