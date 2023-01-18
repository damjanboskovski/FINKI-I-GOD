#include <stdio.h>
#include <stdio.h>
#include <ctype.h>

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
    int cntDigits=0, cntTotal=0, posCnt=0, arr[1024], i=0, max=0, pos=0, flag=0, lastPos=0;

    while (!feof(read)){
        char c = fgetc(read); cntTotal++;
        if(isdigit(c)){ posCnt++; arr[i] = posCnt; cntDigits++; }
        if(cntTotal >= max && cntDigits >= 2){ pos = i; max = cntTotal; }
        if(c == '\n'){ i++; cntDigits = 0; cntTotal = 0; posCnt = 0; }
    }

    fclose(read); FILE *r = fopen("dat.txt", "r"); i=0;

    while (!feof(r)){
        char c = fgetc(r);
        if(i == pos){
            if(isdigit(c)){ flag = 1; lastPos++; }
            if(flag){ printf("%c", c); }
            if(lastPos == arr[pos]){ break; }
        } 
        if(c == '\n'){ i++; }
    }

    fclose(r); return 0;
}