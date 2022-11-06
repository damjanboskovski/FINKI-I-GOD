#include <stdio.h>

int main(){
    int num, isNum=1, maxSize = 100000;
    int arr[5]; for(int i=0; i<5; i++){ arr[i] = 0; }

    while (isNum == 1){
        int max=0, cnt=0, pos=0; isNum = scanf("%d", &num);

        while (num / maxSize != 0){ isNum = scanf("%d", &num); }
        while (num) {
            num % 10 > max ? max=num%10, pos=cnt:0;
            num/=10; cnt++;
        }
        isNum == 1 ? arr[pos] += 1:0;
    }
    
    for(int i=0; i<5; i++){ printf("%d: %d \n", i, arr[i]); }
    return 0;
}
