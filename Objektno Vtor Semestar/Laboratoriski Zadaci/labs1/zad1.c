#include <stdio.h>

typedef struct store{
    char prod[15];
    float price, amount;
} store;


int main(){
    int n; scanf("%d",&n);
    store shop[20];
    float total=0;

    for(int i=0;i<n;i++){
        scanf("%s %f %f",shop[i].prod,&shop[i].price,&shop[i].amount);
    }

    for(int i=0;i<n;i++){
        printf("%d. %s\t%.2f x %.1f = %.2f\n",i+1,shop[i].prod,shop[i].price,shop[i].amount,shop[i].price*shop[i].amount);
        total += shop[i].price * shop[i].amount;
    }
    printf("Total: %.2f",total);

    return 0;    
}