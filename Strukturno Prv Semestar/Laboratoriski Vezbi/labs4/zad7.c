#include <stdio.h>
#include <math.h>

int main(){
    int num, max=0; scanf("%d",&num);
    int A[num];

    for(int i=0;i<num;i++){
        scanf("%d",&A[i]);
        for(int j=i;j>=0;j--){
            if(abs(A[j]-A[i]) > max){max = abs(A[i]-A[j]);}
        }
    }

    printf("Najgolemata razlika: %d",max);

    return 0;
}