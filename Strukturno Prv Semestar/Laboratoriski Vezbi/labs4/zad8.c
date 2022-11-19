#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; scanf("%d",&num);

    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            if(i==num-j-1){printf("*");}
            else if(j==0 || j==num-1 || i==0 ||i==num-1){printf("*");}
            else printf(" ");
        }
        printf("\n");
    }


    return 0;
}
