#include <stdio.h>
#include <stdlib.h>

void wtf(){
    FILE *f = fopen("podatoci.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main(){
    wtf(); FILE *read = fopen("podatoci.txt", "w"); int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("%d %d", num1, num2); fclose(read);
}