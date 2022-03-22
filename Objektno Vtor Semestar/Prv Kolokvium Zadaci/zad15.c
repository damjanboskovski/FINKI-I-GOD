#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5

typedef struct RabotnaNedela{ int casovi[DENOVI], weekNum; }RN;
typedef struct Rabotnik { char ime[50]; RN nedeli[NEDELI]; }R;

int maxNedela(R *r){
    int max=0, temp=0;
    for(int i=0;i<NEDELI;i++){ int sum = 0;
        for(int j=0;j<DENOVI;j++){ sum += r->nedeli[i].casovi[j]; }
            if(sum > max){ max = sum; temp = i; } 
    }
    return temp + 1;
}

void table(R *r, int n){
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for(int i=0;i<n;i++){ int total=0; printf("%s\t",r[i].ime);
        for(int j=0;j<NEDELI;j++){ int sum = 0;
            for(int k=0;k<DENOVI;k++){ sum+=r[i].nedeli[j].casovi[k];}
            printf("%d\t", sum); total+=sum;
        }
        printf("%d\n",total);
    }
}

int main() {
    int n;scanf("%d", &n);
    R rabotnici[n];

    for (int i = 0; i < n; ++i) { scanf("%s", rabotnici[i].ime);
        for (int j = 0; j < NEDELI; ++j) {
            for (int k = 0; k < DENOVI; ++k) { scanf("%d", &rabotnici[i].nedeli[j].casovi[k]); }
        }
    }
    printf("TABLE\n"); table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n%d\n", rabotnici[n / 2].ime,maxNedela(&rabotnici[n / 2]));
    return 0;
}
