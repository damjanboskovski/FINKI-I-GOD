#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int m, n; scanf("%d %d", &m, &n); int arr[m][n], arr_save[m];
    for(int i=0; i<m; i++){ for(int j=0; j<n; j++){ scanf("%d", &arr[i][j]); } }

    for(int i=0; i<m; i++){
        int sum=0, pos=0; float avg=0, maxDiff=0;
        for(int j=0; j<n; j++){ sum += arr[i][j]; }
        avg = (float) sum / n;
        for(int j=0; j<n; j++){
            float diff = fabs((float)arr[i][j] - avg);
            if(diff > maxDiff){ maxDiff = diff; pos = j; }
        }
        arr_save[i] = arr[i][pos];
    }
    for(int i=0; i<m; i++){ printf("%d ", arr_save[i]); } printf("\n"); return 0;
}