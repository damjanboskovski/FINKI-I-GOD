#include <stdio.h>

void wtf() {
    FILE *f = fopen("dat.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf(); FILE *read = fopen("dat.txt", "r");

    return 0;
}