#include <stdio.h>

int main(){
    int num; scanf("%d",&num);
    int firstDig=num;

    while(firstDig>=10){firstDig=firstDig/10;}
    int secondDig=num/100000%10;
    int sumLastTwo=num%10 + (num/10)%10;


    if(firstDig == 0 || secondDig == 0 || sumLastTwo == 0 || num == 0){printf("Nevaliden broj"); return 0;}

    if(num % firstDig == 0 && num % sumLastTwo != 0){printf("DA");}
    else if(num % secondDig != 0 && num % sumLastTwo != 0){printf("DA");}
    else printf("NE");

    return 0;
}