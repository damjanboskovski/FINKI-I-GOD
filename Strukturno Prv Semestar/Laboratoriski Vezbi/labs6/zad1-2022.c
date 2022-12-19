#include <stdio.h>

int main(){
    int num; scanf("%d", &num); int arr[num];
    for(int i=0; i<num; i++){ scanf("%d", &arr[i]); }
    for(int i=0; i<num; i++){ arr[i] % 2 == 0 ? arr[i]++ : arr[i]--; printf("%d ", arr[i]); }
}