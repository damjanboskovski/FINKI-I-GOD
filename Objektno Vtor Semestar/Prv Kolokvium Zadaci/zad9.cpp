#include <iostream>
#include <string>
using namespace std;

struct Laptop{ char firm[100]; float size; int touch, price; };

struct ITStore{ char store_Name[100]; char location[100]; Laptop l[100]; int num;};

void print(ITStore *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].store_Name<<" "<<arr[i].location<<endl;
        for(int j=0;j<arr[i].num;j++){
            arr[i].l[j].size == (int)arr[i].l[j].size?cout<<arr[i].l[j].firm<<" "<<(int) arr[i].l[j].size<<" "<<arr[i].l[j].price<<endl: cout<<arr[i].l[j].firm<<" "<<arr[i].l[j].size<<" "<<arr[i].l[j].price<<endl;
        }
    }
}

void najeftina_ponuda(ITStore *arr, int n){
    int min=0; int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i].num;j++){
            if(arr[i].l[j].touch == 1){  min>arr[i].l[j].price || min == 0?min= arr[i].l[j].price,temp=i:0;}
        }
    }
    cout<<"Najeftina ponuda ima prodavnicata:"<<endl<<arr[temp].store_Name<<" "<<arr[temp].location<<endl<<"Najniskata cena iznesuva: "<<min;
}

int main(){
    ITStore s[100];int n; cin>>n;
    for (int i = 0; i < n; i++){
        cin>>s[i].store_Name>>s[i].location>>s[i].num;
        for (int j = 0; j < s[i].num; j++){
            cin>>s[i].l[j].firm>>s[i].l[j].size>>s[i].l[j].touch>>s[i].l[j].price;
        }
    }
    print(s, n);najeftina_ponuda(s, n);

    return 0;
}
