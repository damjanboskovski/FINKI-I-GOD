#include <stdio.h>

int main(){
    int num, check=0, exists=0, sum=0;

    while(scanf("%d", &num)){ int temp = num;
        while(num>10){
            check = 1; if(num%10 >= ((num/10)%10)){ check = 0; break; } num/=10;
        }
        if(check == 1){ exists=1; sum+=temp; }
    }
    if(exists == 1){ printf("%d", sum); }
    else{ printf("NEMA"); }

}