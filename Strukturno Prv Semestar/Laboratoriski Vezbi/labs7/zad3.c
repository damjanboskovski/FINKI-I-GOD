#include <stdio.h>
#include <stdlib.h>

void readMatrix(int m, int n,int Array[m][n]){
    int sum=0,min,pos=0;
    for(int j=0;j<n;j++){
        sum=0;
        for(int i=0;i<m;i++){
            sum+=Array[i][j];
        }
        if(j==0){min=sum;}
        if(sum<min){min=sum;pos=j;}
    }
    printf("%d",pos);
}

int main()
{
    int m,n; scanf("%d %d",&m,&n);
    int Array[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&Array[i][j]);
        }
    }

    readMatrix(m, n, Array);
    return 0;
}
