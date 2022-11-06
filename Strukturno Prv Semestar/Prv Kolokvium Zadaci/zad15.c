#include <stdio.h>

int main(){
    int num; scanf("%d", &num); int arr[num];
    float sumFailed=0, sumPassed=0, cntFailed=0, cntPassed=0;

    for(int i=0; i<num; i++){ 
        scanf("%d", &arr[i]);
        if(arr[i] < 50){ sumFailed += arr[i]; cntFailed++; }
        else { sumPassed += arr[i]; cntPassed++; }
    }
    
    printf("Sredna vrednost na padnati %.2f\n", (float) sumFailed / cntFailed);
    for(int i=0; i<num; i++){ if(arr[i] < 50){ printf("%d ", arr[i]); } }

    printf("\nSredna vrednost na polozeni %.2f\n", (float) sumPassed / cntPassed);
    for(int i=0; i<num; i++){ if(arr[i] >= 50){ printf("%d ", arr[i]); } }
    return 0;
}