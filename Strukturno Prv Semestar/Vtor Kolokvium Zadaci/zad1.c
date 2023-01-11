#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile() {
    FILE *f = fopen("text.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main() {
    writeToFile(); FILE *read = fopen("text.txt","r");
    char character, prev = ' ', vowels[] = {'a','e','i','o','u'}; int cnt = 0;

    while(!feof(read)){
        character = tolower(fgetc(read)); int flagOne = 0, flagTwo = 0;
        for(int i=0; i<sizeof(vowels)/sizeof(char); i++){
            if(character == vowels[i]){ flagOne = 1; }
            if(prev == vowels[i]){ flagTwo = 1; }
        }
        if(flagOne == 1 && flagTwo == 1){ printf("%c%c\n",prev,character); cnt++; } prev = character;
    }

    printf("%d",cnt); fclose(read); return 0;
}
