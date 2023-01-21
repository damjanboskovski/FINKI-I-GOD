#include <stdio.h>

int main(){
    int n; scanf("%d", &n); int arr[n*2][n*2];

    for(int i=0; i<n; i++){
        for(int j=0; j<n*2; j++){
            if(j > n-1){ scanf("%d", &arr[i+n][j-n]); }
            else { scanf("%d", &arr[i][j]); }
        }
    }

    for(int i=0; i<n*2; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        } printf("\n");
    }
}