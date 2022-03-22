#include<stdio.h>
#include<string.h>

typedef struct SkiLift{ char name[15]; int num, hasLift; }SL;
typedef struct SkiCenter{ char country[20],centerName[20]; SL arr[20];int liftNum;}SC;

int capacity(SC sc){ int temp = 0;
    for(int i=0;i<sc.liftNum;i++){  sc.arr[i].hasLift == 1?temp+=sc.arr[i].num:0; } return temp; }

void maxCapacity(SC *sc, int num){ int temp=0,max=0,max2=0;
    for(int i=0;i<num;i++){ temp = capacity(sc[i]);
        (temp > max) || (temp == max && sc[i].liftNum > sc[max2].liftNum)? max = temp, max2 = i:0; }
    printf("%s\n%s\n%d",sc[max2].centerName,sc[max2].country,max);
}

int main() {
	int n;scanf("%d", &n); SC sc[20];
	for (int i = 0; i < n; i++){
		scanf("%s %s %d",sc[i].centerName,sc[i].country, &sc[i].liftNum);
		for(int j = 0; j < sc[i].liftNum; j++){
            scanf("%s %d %d",sc[i].arr[j].name, &sc[i].arr[j].num, &sc[i].arr[j].hasLift); } }
    maxCapacity(sc,n);return 0;
}