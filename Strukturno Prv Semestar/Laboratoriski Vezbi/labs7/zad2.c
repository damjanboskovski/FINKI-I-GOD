#include <stdio.h>

void elka(int n){
    int mesto=n/2, dzv=1;
    for(int i=0; i<=n/2;i++){
        int tempMesto=mesto; while(tempMesto){printf(" "); tempMesto--;}
        int tempDzv = dzv; while(tempDzv){printf("*"); tempDzv--;}
        printf("\n");mesto--;dzv+=2;
    } 
}

int main(){
    int num; scanf("%d",&num); elka(num);
    return 0;
}