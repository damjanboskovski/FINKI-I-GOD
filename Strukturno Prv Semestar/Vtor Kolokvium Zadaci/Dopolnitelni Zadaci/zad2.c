#include <stdio.h>
#include <math.h>

void printFile() {
    FILE *f=fopen("shema.txt","r"); char line[1000];
    while(!feof(f)){ fgets(line,1000,f); if (feof(f)){ break;} printf("%s",line); }
    fclose(f);
}

int main() {
    int n; scanf("%d", &n); 
    int size = ceil(sqrt(n)), matrix[size][size], num = 1;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < size; j++) { num <= n ? matrix[j][i] = num, num++ : matrix[j][i] = 0; }
        } 
        else { for (int j = size - 1; j >= 0; j--) { num <= n ? matrix[j][i] = num, num++ : matrix[j][i] = 0; } }
    }

    FILE *f = fopen("shema.txt", "w");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) { fprintf(f,"%d ", matrix[i][j]);}
        fprintf(f, "\n");
    }
    fclose(f); printFile(); return 0;
}