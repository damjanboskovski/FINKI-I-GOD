#include <stdio.h>
int main(){
char c,f; scanf("%c",&c);
int number; scanf("%d", &number); 
int num=c,move,pos;

for(int i=65;i<91;i++){
    f=(char)(65+i);
    if(f==c){pos=i;}
}

while(pos+move>90){move-=90;}
printf("%c",pos+move);


return 0;
}