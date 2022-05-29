#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m; scanf("%d %d", &n, &m); int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int posOne = 0, posTwo = 0; scanf("%d%d",&posOne,&posTwo); int quad[4] = {0,0,0,0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int q = (i<posOne)?(j>=posTwo?1:2):(j<posTwo?3:4);
            quad[q - 1] += arr[i][j]; 
        } 
    }

    for(int i=0; i<4; i++){ printf("%d ",quad[i]); } return 0;
}