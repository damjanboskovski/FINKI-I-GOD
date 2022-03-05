#include<stdio.h>
#include<math.h>

int main(){
    int n,sum=0,sum2=0,sum3=0,sum4=0; scanf("%d",&n);
    int A[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        sum -=  A[i][i];
        sum2 -= A[i][n - i - 1];
    }

    for (int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            if(j==0){
                sum3-=A[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            if(j==n-1){
                sum4-=A[i][j];
            }
        }
    }
    
    printf("%d ",abs(sum) - abs(sum2)); printf("\n");
    printf("%d ",abs(sum3) - abs(sum4));

    return 0;
}