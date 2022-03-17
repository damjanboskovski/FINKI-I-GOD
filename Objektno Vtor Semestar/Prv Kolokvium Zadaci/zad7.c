#include <stdio.h>
#include <string.h>

typedef struct Vozenje{
    char ime[100];
    int traenje,daliPopust;
    float cena;
}Vozenje;

typedef struct ZabavenPark{
    char ime[100], lokacija[100];
    Vozenje niza[100];
    int n;
}ZabavenPark;

void pecati(ZabavenPark *niza, int n)
{
    for(int i=0;i<n;i++){
        printf("%s %s\n",niza[i].ime,niza[i].lokacija);
        for(int j=0;j<niza[i].n;j++){
            printf("%s %d %.2f\n",niza[i].niza[j].ime,niza[i].niza[j].traenje,niza[i].niza[j].cena);
        }
    }
}

void najdobar_park(ZabavenPark *niza, int n)
{
    int maxI=0, maxV=0,maxVremetraenje= 0;

    for(int i=0;i<n;i++){
        int count=0, vreme=0;
        for(int j=0;j<niza[i].n;j++){
            if(niza[i].niza[j].daliPopust==1)
                count++;
            vreme+= niza[i].niza[j].traenje;
        }
        if(count>maxV){
            maxV = count;  maxI = i;  maxVremetraenje = vreme;
        }
        else if(count==maxV && vreme > maxVremetraenje){
            maxI = i;  maxVremetraenje = vreme;
        }
    }
    printf("Najdobar park: %s %s\n",niza[maxI].ime,niza[maxI].lokacija);
}

int main()
{
	int i, j, n, broj; ZabavenPark ff[100]; scanf("%d", &n);

    for (i = 0; i < n; i++){
		scanf("%s %s %d", ff[i].ime, ff[i].lokacija, &ff[i].n); 
		for (j = 0; j < ff[i].n; j++){
			scanf("%s %d %f %d", ff[i].niza[j].ime, &ff[i].niza[j].traenje, &ff[i].niza[j].cena, &ff[i].niza[j].daliPopust);
		}
    }
    pecati(ff,n);  najdobar_park(ff,n);

	return 0;
}
