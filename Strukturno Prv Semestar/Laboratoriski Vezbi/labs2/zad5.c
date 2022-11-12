#include <stdio.h>

int main(){
    int index, grades, sum = 0; scanf("%d", &index);
    for(int i=0; i<6; i++){ scanf("%d", &grades); sum += grades; }
    printf("Prosek: %.3f\n", (float) sum / 6 );
    printf("Student: %d\n", index);
    printf("%d godina\n", 23-(index/10000));
    printf("Nagraden: %d", ((float) sum / 6) >= 9.5);
}