#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c,prv;
    scanf("%f%f%f",&a,&b,&c);

    prv = (pow((int)b,2)-(4*a*c));

    if(prv != 0){
        if(prv>0){printf("Reshenija na ravenkata se: %.02f i %.02f\n",(-b-sqrt(prv))/(2*a),(-b+sqrt(prv))/(2*a));}
        else{printf("Ravenkata nema realni reshenija"); return 0;}
    }
    else{printf("Dvojno reshenie na ravenkata e: %.02f",-b/2*a);}
    return 0;
}
