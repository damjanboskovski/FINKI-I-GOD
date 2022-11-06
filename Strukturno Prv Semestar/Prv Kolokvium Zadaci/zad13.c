#include <stdio.h>

int main(){
    int num; scanf("%d", &num); int arr[num];
    for(int i=0; i<num; i++){ scanf("%d", &arr[i]); }

    for(int i=1; i<=3; i++){
        printf("Grupa %d \n", i);

        for(int j=0; j<num; j++){
            if(i == 1){ switch (arr[j]%10) { case 0: case 1: case 2: printf("%d ", arr[j]); break; } }
            if(i == 2){ switch (arr[j]%10) { case 3: case 4: case 5: printf("%d ", arr[j]); break; } }
            if(i == 3){ switch (arr[j]%10) { case 6: case 7: case 8: case 9: printf("%d ", arr[j]); break; } }
        } printf("\n");
    }

    return 0;
}