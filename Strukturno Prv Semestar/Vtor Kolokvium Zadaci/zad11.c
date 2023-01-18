#include <stdio.h>
#include <ctype.h>
#include <string.h>

void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf(); FILE *read = fopen("input.txt", "r");
    int arr[1024], cnt=0;
    while (!feof(read)){
        char character = fgetc(read);
        if(isdigit(character)){ arr[cnt] = character - '0'; cnt++; }

        if(character == '\n'){
            printf("%d:", cnt); int temp;
            for(int i=0; i<cnt; i++){
                for(int j=i+1; j<cnt; j++){
                    if(arr[i] > arr[j]){ temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; } } }

            for(int i=0; i<cnt; i++){ printf("%d", arr[i]); } cnt=0; printf("\n"); 
        }
    }
    return 0;
}
