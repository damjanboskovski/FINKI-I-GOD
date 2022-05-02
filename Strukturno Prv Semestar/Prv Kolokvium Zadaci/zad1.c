#include <stdio.h>

int softNum(int num){
    if(num == 0){ return 0; }
    if(num%2 != 0){ return 1; }
    else return softNum(num/10);
}

int main(){
    int n,m,cnt=0; scanf("%d%d",&n,&m); int min=m;
    for(int i=n; i<m; i++){ 
        cnt++; if(softNum(i) != 1 && i<min){ min = i; }
    }
    if(min!= m || cnt==1){ printf("%d",min); }
    else printf("NE");
    return 0;
}