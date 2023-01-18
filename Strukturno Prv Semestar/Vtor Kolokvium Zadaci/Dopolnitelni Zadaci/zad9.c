#include <stdio.h>
#include <string.h>

int svrzniciCnt(char *str){
    int cnt=0; char *word = strtok(str, " \t\n\r\f\v,.!?");
    while(word != NULL){
        if(strlen(word) <= 3){ cnt++; }
        word = strtok(NULL, " \t\n\r\f\v,.!?");
    } return cnt;
}

int main(){
    char str[1024], str_save[1024]; int max=0;
    while(fgets(str, sizeof(str), stdin) != NULL){
        if(str[strlen(str) - 1] == '\n'){
            str[strlen(str) - 1] == '\0';
        }
        int cnt = svrzniciCnt(str);
        if(cnt > max){ max = cnt; strcpy(str_save, str); }
    } printf("%d: %s", max, str_save); return 0;
}