#include <stdio.h>
#include <stdlib.h>

int main(){
    int a1, a2; scanf("%d %d", &a1, &a2);
    int c1, c2; scanf("%d %d", &c1, &c2);

    int cmp1, cmp2; scanf("%d %d", &cmp1, &cmp2);
    int cmp3, cmp4; scanf("%d %d", &cmp3, &cmp4);

    if( cmp1 >= a1 && cmp1 <= c1 && cmp2 == a2 ){ printf("DA"); }
    else if( cmp1 == a1 && cmp2 >= a2 && cmp2 <= c2 ){ printf("DA"); }
    else if( cmp1 == c1 && cmp2 >= a2 && cmp2 <= c2 ){ printf("DA"); }
    else{ printf("NE"); }
    printf("\n");
    if( cmp3 >= a1 && cmp3 <= c1 && cmp4 >= a2 && cmp4 <= c2 ){ printf("DA"); }
    else{ printf("NE"); }

    return 0;
}
