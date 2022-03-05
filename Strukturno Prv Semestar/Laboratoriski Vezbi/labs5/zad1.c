#include <stdio.h>
#include <math.h>

int main(){
    int num; scanf("%d",&num);
    int a,b,c,min=0,d;

    for(int i=0;i<num;i++){scanf("%d%d%d",&a,&b,&c);
    d = abs((a-b)) + abs((b-c)); if(min==0){min = d;}
    else if(d<min){min=d; }
    }

    printf("%d",min);

    return 0;
}