#include <stdio.h>
int main(){
    int grade1,grade2,grade3,grade4,grade5;
    scanf("%d %d %d %d %d",&grade1,&grade2,&grade3,&grade4,&grade5);
    float gpa = (grade1+grade2+grade3+grade4+grade5)/5.00;
    printf("%.2f",gpa);
    return 0;
}