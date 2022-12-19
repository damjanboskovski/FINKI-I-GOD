#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=101; while(n>100){scanf("%d",&n);}
    int Array[n], Array2[n], k, br=0;

    for(int i=0;i<n;i++){scanf("%d",&Array[i]);}
    scanf("%d",&k);

    for(int i=0;i<n;i++){if(Array[i]<k){Array2[br]=A[i]; br++;}}
    for(int i=0;i<n;i++){if(Array[i]>=k){Array2[br]=A[i];br++;}}

    for(int i=0;i<n;i++){printf("%d",Array2[i]);}
    return 0;
}

