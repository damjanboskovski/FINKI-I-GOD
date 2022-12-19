#include <stdio.h>

int main(){
    int num; scanf("%d",&num);

    while(num){
        int size=101,br=0; 
        while(size>100){scanf("%d", &size);}
        int A[size];
        for(int i=0;i<size;i++){scanf("%d",&A[i]);}

        for(int i=0;i<size/2;i++){
            if(A[i]==A[size-i-1]){br+=2;}
        }
        if(size%2!=0){br+=1;}
        printf("%.02f%%\n",(float)br/size * 100);
        num--;
    }
    return 0;
}