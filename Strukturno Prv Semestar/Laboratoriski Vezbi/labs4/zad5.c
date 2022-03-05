#include <stdio.h>

int main(){
    int num; scanf("%d",&num);
    float n,sum=0.00; char c;

    while(num){
        scanf("%f %c",&n, &c);
        switch(c){
            case 'A': n *= 0.18; break;
            case 'B': n *= 0.05; break;
            case 'V': n *= 0; break;
        }
        sum+=n; n--;
    }

    printf("Total tax return is: %.2f", sum*=0.15);

    return 0;
}