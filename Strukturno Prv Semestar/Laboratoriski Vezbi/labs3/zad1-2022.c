#include <stdio.h>
#include <stdlib.h>

int main()
{
    float i,j,k;
    scanf("%f %f %f", &i, &j, &k);
    if(i < j && i < k){ printf("1"); }
    else if(j < i && j < k){ printf("2"); }
    else if(k < i && k < j){ printf("3"); }
    else if( i == j && (i < k || j < k)){ printf("12"); }
    else if( i == k && (k < j || i < j)){ printf("13"); }
    else if( j == k && (j < i || j < k)){ printf("23"); }
    else if( i == j && i == k && j == k){ printf("123"); }
    return 0;
}
