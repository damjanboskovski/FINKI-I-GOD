#include <stdio.h>
#include <math.h>

int main(){

    int n, prev, num, max=0; scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &num); 
        if(abs(num-prev) > max && i>0 ){ max = abs(num-prev); }
        prev = num;
    }

    printf("%d", max); 

}