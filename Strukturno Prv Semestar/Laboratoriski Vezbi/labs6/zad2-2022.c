#include <stdio.h>

int main(){
    int num; scanf("%d", &num);
    int arr[num][num], tempTwo = 0, max = 0;

    for(int i=0; i<num; i++){
        int temp = num;
        for(int j=0; j<num; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] <= tempTwo){ temp--; }
            tempTwo = arr[i][j];
        }
        if(temp > max){ max = temp; } temp = 0;
    }
    printf("%d", max);
}