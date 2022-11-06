#include <stdio.h>

int main(){
    int isNum=1, num, max=0;

    while (isNum == 1) {
        int sum=0; sum += max;
        isNum = scanf("%d", &num); int temp = num; max=0;
        while(temp){
            temp%10 > max ? max = temp%10:0;
            sum += temp%10; temp/=10;
        }
        if(isNum == 1){ printf("%d: %d \n", num, sum); }
    }
    
    return 0;
}