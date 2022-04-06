#include <iostream>
#include <cstring>
using namespace std;

struct Laptop{ char firm[100]; float screenSize; bool hasTouch; int price; };
struct ITStore{ char storeName[100], location[100]; Laptop l[100]; int num; };

void print(ITStore *arr, int n){
    for(int i=0; i<n; i++){ cout<<arr[i].storeName<<" "<<arr[i].location<<endl;
        for(int j=0; j<arr[i].num; j++){
            if( arr[i].l[j].screenSize == (int) arr[i].l[j].screenSize ){ cout<<arr[i].l[j].firm<<" "<<(int) arr[i].l[j].screenSize<<" "<<arr[i].l[j].price<<endl; }
            else cout<<arr[i].l[j].firm<<" "<<arr[i].l[j].screenSize<<" "<<arr[i].l[j].price<<endl; } }
}

void cheapest_store(ITStore *arr, int n){
    int minPrice=0, pos=0;
    for(int i=0; i<n; i++){ for(int j=0; j<arr[i].num; j++){ 
        arr[i].l[j].hasTouch && (minPrice > arr[i].l[j].price || minPrice == 0)? minPrice = arr[i].l[j].price, pos = i:0; } }
    cout<<"Najeftina ponuda ima prodavnicata:"<<endl<<arr[pos].storeName<<" "<<arr[pos].location<<endl<<"Najniskata cena iznesuva: "<<minPrice;
}

int main(){
    int num; cin>>num; ITStore store[100];
    for(int i=0; i<num; i++){ cin>>store[i].storeName>>store[i].location>>store[i].num;
        for(int j=0; j<store[i].num; j++){ cin>>store[i].l[j].firm>>store[i].l[j].screenSize>>store[i].l[j].hasTouch>>store[i].l[j].price; } }
    print(store, num); cheapest_store(store, num);
    return 0;
}