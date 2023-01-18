#include <stdio.h>
#include <string.h>
#define size 101

int main(){
    char string[size]; fgets(string, size, stdin);
    string[strlen(string) - 1] == '\n' ? string[strlen(string) - 1] = '\0' : 0;

    char firstHalf[size], secondHalf[size]; int len = strlen(string) / 2;
    strncpy(firstHalf, string, len); firstHalf[len] = '\0';
    strncpy(secondHalf, string + len, strlen(string) - len); secondHalf[strlen(string) - len] = '\0';
    strcpy(string, secondHalf); strcat(string, firstHalf); printf("%s", string); return 0;
}