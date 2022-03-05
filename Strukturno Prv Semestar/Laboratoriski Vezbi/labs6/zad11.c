#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=101; while(n>100 || n<3){scanf("%d",&n);}
    int Array[n][n], Array2[2][2]={0,0,0,0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&Array[i][j]);
            if(j<n/2){
                if(i<n/2){
                    Array2[0][0]+=Array[i][j];
                }
                if(i>n/2){
                    Array2[1][0]+=Array[i][j];
                }
            }
            if(j>n/2){
                if(i<n/2){
                    Array2[0][1]+=Array[i][j];
                }
                if(i>n/2){
                    Array2[1][1]+=Array[i][j];
                }
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",Array2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
