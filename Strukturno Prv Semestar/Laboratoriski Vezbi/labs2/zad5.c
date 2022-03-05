#include<stdio.h>

int main(){
    int index; scanf("%d",&index);

    int grade,reward=0; float sum = 0.000;
    for(int i=0;i<6;i++){scanf("%d",&grade); sum=sum+grade;}

    if(sum/6.00 >= 9.5){reward = 1;}
    printf("Prosek: %.3f\n",sum/6.000);
    printf("Student: %d\n",index);
    printf("%d godina\n",20-(index/10000));
    printf("Nagraden: %d",reward);
    return 0;
}