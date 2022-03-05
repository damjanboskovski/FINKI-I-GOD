#include <stdio.h>

int prev(int num){int rev=0;while(num){rev=rev*10+(num%10); num/=10;} return rev;}
int brojac(int num){int br=0; while(num){br++;num/=10;}return br;}

int main(){
    int num; scanf("%d",&num);

    int firstTwo=num/1000000;

    int temp=prev(num)/100; int midThree=prev(temp)/1000;

    int lastThree=num%1000;

    if(brojac(lastThree)==1){printf("0%d/%d-00%d",firstTwo, midThree, lastThree);}
    else if(brojac(lastThree)==2 && brojac(midThree)==3){printf("0%d/%d-0%d",firstTwo, midThree, lastThree);}
    else if(brojac(midThree)==1 && brojac(lastThree)==3){printf("0%d/00%d-%d",firstTwo, midThree, lastThree);}
    else if(brojac(midThree)==2 && brojac(lastThree)==3){printf("0%d/0%d-%d",firstTwo, midThree, lastThree);}
    else if(brojac(lastThree)==2 && brojac(midThree)==2){printf("0%d/0%d-0%d",firstTwo, midThree, lastThree);}
    else if(brojac(lastThree)==1 && brojac(midThree)==1){printf("0%d/00%d-00%d",firstTwo, midThree, lastThree);}
    else if(brojac(lastThree)==1 && brojac(midThree)==2){printf("0%d/0%d-00%d",firstTwo, midThree, lastThree);}
    else if(brojac(lastThree)==2 && brojac(midThree)==1){printf("0%d/00%d-0%d",firstTwo, midThree, lastThree);}
    else {printf("0%d/%d-%d",firstTwo, midThree, lastThree);}
    
    switch(firstTwo%10){
        case 0: case 1: case 2: printf(" T-mobile"); break;
        case 5: case 6: case 7: case 8: printf(" A1"); break;
        case 9: printf(" LycaMobile");  break;
    }
    
    return 0;
}