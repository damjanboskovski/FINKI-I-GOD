#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; scanf("%d",&num);
    for(int i=0; i<num; i++){
        if(i != 0){ printf("\n|\n|"); }
        for(int j=0; j<num; j++){
            if(i == 0 && j == 0){ printf("*"); }
            else if(i>=j){ printf("*"); }
        }
    }
    return 0;
}
