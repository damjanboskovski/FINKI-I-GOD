#include <iostream>
#include <cstring>
using namespace std;

struct Voz{ char direction[50]; double km; int passenger_Num; };
struct ZeleznickaStanica{ char city[20]; Voz v[30]; int train_Num; };

void najkratkaRelacija(ZeleznickaStanica *arr,int num, char *c){
    float min=0; int i1=0,j1=0;
    for(int i=0;i<num;i++){
        if(strcmp(arr[i].city,c)==0){
            for(int j=0;j<arr[i].train_Num;j++){
                min>=arr[i].v[j].km?min=arr[i].v[j].km,i1=i,j1=j:min=arr[i].v[j].km;} }
    }
    cout<<"Najkratka relacija: "<<arr[i1].v[j1].direction<<" ("<<arr[i1].v[j1].km<<" km)";
}
int main(){
    int n; cin>>n;

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){ cin>>zStanica[i].city>>zStanica[i].train_Num;
        for(int j=0;j<zStanica[i].train_Num;j++){ cin>>zStanica[i].v[j].direction>>zStanica[i].v[j].km>>zStanica[i].v[j].passenger_Num; }
    }
    char grad[25]; cin>>grad; najkratkaRelacija(zStanica,n,grad);
	return 0;
}