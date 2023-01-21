#include <stdio.h>

int main(){
    int n; scanf("%d", &n); float arr[n][n], arr_copy[n][n], sum_one = 0, sum_two=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%f", &arr[i][j]); arr_copy[i][j] = 0;
            if(i > j){ sum_one += arr[i][j]; }
            if(i+j > n-1){ sum_two += arr[i][j]; }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){ arr_copy[i][j] += sum_one; }
            if(i+j == n-1){ arr_copy[i][j] += sum_two; }
            printf("%.1f ", arr_copy[i][j]);
        } printf("\n");
    }
}