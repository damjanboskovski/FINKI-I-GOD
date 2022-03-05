#include <stdio.h>

int main(){
    int num; scanf("%d",&num);
    int A[num];

    for(int i=0;i<num;i++){
        scanf("%d",&A[i]);
        if(A[i]%2==0){A[i]++;}
        else A[i]--;
    }

    for(int i=0;i<num;i++){
        printf("%d ",A[i]);
    }

    return 0
}