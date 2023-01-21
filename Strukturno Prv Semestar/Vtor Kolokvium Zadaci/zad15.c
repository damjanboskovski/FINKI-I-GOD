#include <stdio.h>

int poramnet(int num){
    if(num == 0){ return 0; }
    if(num % 10 == 9){ return poramnet(num/10)*10+7; }
    else{ return poramnet(num/10)*10+num%10; }
}

int main(){
    int num, arr[100], cnt=0; while(scanf("%d", &num) == 1){ arr[cnt++] = num; }
    for(int i=0; i<cnt; i++){ arr[i] = poramnet(arr[i]); }

    for(int i=0; i<cnt; i++){
        int min = i;
        for(int j = i + 1; j < cnt; j++){ if(arr[j] < arr[min]){ min = j; } }
        int temp = arr[i]; arr[i] = arr[min]; arr[min] = temp;
    }

    for(int i=0; i<5 && i<cnt; i++){ printf("%d ", arr[i]); } return 0;
}