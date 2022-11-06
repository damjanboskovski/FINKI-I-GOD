#include <stdio.h>

int main(){
    int num,sum=0,max=0,pos=0; scanf("%d",&num);
    for(int i=num-1;i>0;i--){ sum=0;
        for(int j=i; j>0;j--){ if(i%j==0){ sum+=j; } }
        if(sum>max){max = sum; pos=i; }
    }
    printf("%d",pos); return 0;
}