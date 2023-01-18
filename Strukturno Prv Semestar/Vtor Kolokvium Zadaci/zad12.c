#include <stdio.h>

int BrojPozitivni(int arr[], int num){
    if(num <= 0){ return 0; }
    if(arr[num - 1] > 0){ return 1 + BrojPozitivni(arr, num - 1); }
    else return BrojPozitivni(arr, num - 1);
}

int main(){
    int num; scanf("%d", &num); int arr[num];
    for(int i=0; i<num; i++){ scanf("%d", &arr[i]); }
    printf("%d", BrojPozitivni(arr, num)); return 0;
}