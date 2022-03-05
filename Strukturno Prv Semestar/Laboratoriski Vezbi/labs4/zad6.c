#include <stdio.h>

int main(){
    int n,cena,num; scanf("%d", &num); char c;
    float ddv=0.00, sum=0.00, sum2=0.00, max=0.00,maxTax=0.00;

    for(int i=0;i<num;i++)
    {
        sum=0; sum2=0; scanf("%d",n);
        for(int j=0;j<n;j++)
        {
            scanf("%d %c",&cena, &c); sum2+=cena;
            switch(c)
            {
            case 'A': ddv = 0.18; break;
            case 'B': ddv = 0.05; break;
            case 'V': ddv = 0.00; break;
            }
            if(ddv !=0){sum+=(cena*ddv) - cena;}
        }

        float ddv2 = (sum * 1.15) - sum;
        if(sum2<=30000){
        printf("Total tax return is: %.2lf\n",ddv2);
            if(ddv>maxTax){maxTax=ddv2; max=sum2;}
        }
        else {printf("Sum %d is bigger than 30000\n",(int)sum2);}
        printf("%f\n",max);
    }

    printf("Max amount of reciept: %d. Max tax return for reciepts: %.02f",(int)max,maxTax);

    return 0;
}