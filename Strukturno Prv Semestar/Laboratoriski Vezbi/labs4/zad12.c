#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; scanf("%d",&num);
    if(num<=2){printf("Nevaliden vlez"); return 0;}

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(i+j < num || j==num-i-1){ printf("*"); }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
