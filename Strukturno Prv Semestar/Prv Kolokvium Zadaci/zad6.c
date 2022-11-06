#include <stdio.h>

int main(){
    int cmp ,num1, num2; scanf("%d %d %d", &cmp, &num1, &num2);
    int cnt=0, cntTotal=0, sum=0;
    
    while ( (num1 + num2) != 0 ) {
        sum += num1 + num2; cmp == sum ? cnt++ : 0; cntTotal++; sum=0;
        scanf("%d %d", &num1, &num2);
    }

    printf("Vnesovte %d parovi od broevi chij zbir e %d \n", cnt, cmp);
    printf("Procentot na parovi so zbir %d e %.02f%% \n", cmp, ((float)cnt/cntTotal)*100);
    
    return 0;
}
