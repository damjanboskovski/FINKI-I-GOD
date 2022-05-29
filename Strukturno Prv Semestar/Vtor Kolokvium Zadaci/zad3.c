#include <stdio.h>
#include <stdlib.h>

int sumPos(int *a, int n, int ind){
    if(ind == n){ return 0; }
    return *(a+ind) + sumPos(a, n, ind+1);
}

int main(){
    int num, index; scanf("%d",&num); int arr[num];
    for(int i=0; i<num; i++){ scanf("%d",&*(arr+i)); }
    scanf("%d",&index); printf("%d",sumPos(arr, num, index)); return 0;
}