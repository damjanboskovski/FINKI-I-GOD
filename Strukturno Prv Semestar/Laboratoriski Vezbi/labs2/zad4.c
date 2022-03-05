#include<stdio.h>

int main(){
    int km;scanf("%d",&km);

    int p_cen,p_km,d_cen,taxi1;
    scanf("%d",&p_cen);scanf("%d",&p_km);scanf("%d",&d_cen);

    int brz,p_cen2,min_cen,km_cen,taxi2;
    scanf("%d",&brz);scanf("%d",&p_cen2);scanf("%d",&min_cen);scanf("%d",&km_cen);

    taxi1 = p_cen + (km - p_km) * d_cen;
    taxi2 = p_cen2 + (km/brz)*km_cen + km * min_cen;

    printf("%d %d\n",taxi1,taxi2);
    if(taxi1 <= taxi2){printf ("1");}
    else printf("0");

    return 0;
}