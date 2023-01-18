#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int num; scanf("%d", &num); char str[1024];

    for(int i=0; i<num; i++){
        scanf("%s", str);
        for(int j=0; j<strlen(str); j++){ str[j] = towlower(str[j]); }
        int cnt=0; char *arr = "a1c", *p = str;
        while(p = strstr(p, arr)){ cnt++; p++; }
        if(cnt >= 2){ printf("%s\n", str); }
    } return 0;
}