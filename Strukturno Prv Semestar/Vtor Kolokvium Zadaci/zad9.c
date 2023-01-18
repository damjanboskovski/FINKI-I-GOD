#include <stdio.h>

double func(int *arr, int num, int i){
    if(i == num + 1){ return 0; }
    return arr[i] + (1.00 / func(arr, num, i+1));
}

int main(){
    int num; scanf("%d", &num); int arr[num];
    for(int i=0; i<num; i++){ scanf("%d", &arr[i]); }
    printf("%lf", func(arr, num, 0)); return 0;
}