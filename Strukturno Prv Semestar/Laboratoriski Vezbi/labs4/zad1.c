#include <stdio.h>

int main()
{
    int num; scanf("%d",&num);

    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(i==j || j == (num-i-1)){ printf("*"); }
            else if(j==0 || j==num-1){ printf("*"); }
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}