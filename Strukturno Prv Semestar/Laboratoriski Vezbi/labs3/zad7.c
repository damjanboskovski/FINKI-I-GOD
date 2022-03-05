#include <stdio.h>

int main(){
    int num, ocena, temp, br; scanf("%d",&num);
    int lastDig=num%10;

    if(num<100 && num>=0){
        if(num%10 == 0){temp=0;} else {temp =1;}

        while(num){br=num%10; num/=10;}
        printf("%d",br);

        if(br>=5){ocena=br+temp;}
        else {ocena=5;}
        }

    else if(num == 100){ocena=10;}
    else{printf("Nevalidna vrednost za poeni!"); return 0;}
    

    printf("Ocenka %d",ocena);
    if(ocena>5){
        switch(lastDig){
            case 1: case 2: case 3: printf("-"); break;
            case 8: case 9: case 0: printf("+"); break;
        }
    }
    return 0;
}