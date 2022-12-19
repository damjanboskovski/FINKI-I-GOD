#include <stdio.h>

int main(){
    int num, cnt=0; scanf("%d", &num);
    int arr[num], transformedArr[num];

    for(int i=0; i<num; i++){ scanf("%d", &arr[i]); }
    int k; scanf("%d", &k);

    for(int i=0; i<num; i++){ arr[i] < k ? transformedArr[cnt] = arr[i], cnt++ : 0; }
    for(int i=0; i<num; i++){ arr[i] >= k ? transformedArr[cnt] = arr[i], cnt++ : 0; }

    for(int i=0; i<num; i++){ printf("%d ", transformedArr[i]); }
}