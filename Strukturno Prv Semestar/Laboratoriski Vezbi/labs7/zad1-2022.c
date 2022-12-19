#include <stdio.h>

int main(){
    int num; scanf("%d", &num); int arr[num][num];

    for(int i=0; i<num; i++){ for(int j=0; j<num; j++){ scanf("%d", &arr[i][j]); } }

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            i == j ? printf("%3d ", arr[i][j] * -1) : printf("%3d ", arr[i][j]);
        } printf("\n");
    }
}
