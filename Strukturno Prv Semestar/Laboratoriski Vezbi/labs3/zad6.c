#include <stdio.h>
#include <stdlib.h>



int main()
{
    int num,num2=0,temp=0,br=0;
    scanf("%d",&num);
    temp = num;
    
    while(temp){br++;num2 = num2*10+temp%10;temp=temp/10;}
    
    if(br != 5){printf("Nevaliden vlez");}
    else if(num != num2){printf("Ne e palindrom");}
    else {printf("Palindrom");}
    
    return 0;
}
