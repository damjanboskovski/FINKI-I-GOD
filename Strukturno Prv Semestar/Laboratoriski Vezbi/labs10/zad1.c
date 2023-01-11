#include <stdio.h>
#include <ctype.h>

void writeToFile(){
    FILE *f = fopen("text.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); } fclose(f);
}

int main() {
    writeToFile(); FILE *read = fopen("text.txt", "r");
    char c; int cntTotal = 0, cntUpper = 0, cntLower = 0;
    while(!feof(read)){ c = fgetc(read); isalpha(c) ? cntTotal++, (isupper(c) ? cntUpper++ : cntLower++) : 0; }
    printf("%.4lf\n%.4lf", (float)cntUpper / cntTotal, (float)cntLower / cntTotal); fclose(read); return 0;
}