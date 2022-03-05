#include <stdio.h>

typedef struct tocka{
    double x;
    double y;
}tocka;

typedef struct otsecka{
    tocka t1;
    tocka t2;
}otsecka;

int se_secat(otsecka o1,otsecka o2){
    double c1=(o1.t2.y - o1.t1.y)/(o1.t2.x - o1.t1.x);
    double c2=(o2.t2.y - o2.t1.y)/(o2.t2.x - o2.t1.x);

    if(c1 == c2 || o1.t1.x == -2){return 0;}
    else return 1;
}

int main(){
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    tocka t1 = {x1, y1};
    tocka t2 = {x2, y2};
    otsecka o1 = {t1, t2};
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    tocka t3 = {x1, y1};
    tocka t4 = {x2, y2};
    otsecka o2 = {t3, t4};
    printf("%d\n", se_secat(o1, o2));
    
    return 0;
}