#include <stdio.h>

int main(){
    int cmp, n, m; scanf("%d %d %d", &cmp, &n, &m); int arr[n][m], printArr[n];
    for(int i=0; i<n; i++){ int sum=0;
        for(int j=0; j<m; j++){ scanf("%d", &arr[i][j]); sum += arr[i][j]; } 
        printArr[i] = sum>cmp ? 1 : (sum<cmp ? -1 : 0);
    }

    for(int i=0; i<n; i++){ for(int j=0; j<m; j++){ printf("%d ", printArr[i]); } printf("\n"); } return 0;
}