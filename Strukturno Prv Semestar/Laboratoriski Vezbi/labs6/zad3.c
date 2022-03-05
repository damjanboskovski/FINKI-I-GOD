#include <stdio.h>

int main(){
    int num; scanf("%d",&num); 
    int A[num],prevPol[num/2],br=0;

    for(int i=0;i<num;i++){scanf("%d",&A[i]);}
    for(int i=0;i<num;i++){printf("%d ",A[i]);} printf("\n");
    for(int i=num-1;i>=0;i--){printf("%d ",A[i]);}  printf("\n");
    for(int i=num-1;i>=0;i-=2){prevPol[br]=A[i];br++;printf("%d ",A[i]);}  printf("\n");
    for(int i=br-1;i>=0;i--){printf("%d ",prevPol[i]);}  printf("\n");

    return 0;
}