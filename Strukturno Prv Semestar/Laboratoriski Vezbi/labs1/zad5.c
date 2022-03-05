#include <stdio.h>
int main(){
    int sec,h,m,s;
    scanf("%d", &sec);

   	h = (sec/3600); 
	m = (sec -(3600*h))/60;
	s = (sec -(3600*h)-(m*60));
    
    printf("%d sekundi se %d casovi, %d minuti i %d sekundi",sec,h,m,s);

    return 0;
}