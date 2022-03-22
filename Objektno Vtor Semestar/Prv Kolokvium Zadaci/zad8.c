#include <stdio.h>
#include <string.h>

typedef struct Laptop{ char firm[100]; float size; int touch, price; } Laptop;
typedef struct ITStore{ char store_Name[100]; char location[100]; Laptop l[100]; int num; } ITStore;

void print(ITStore *arr,int n){
    for(int i=0;i<n;i++){ 
        printf("%s %s\n",arr[i].store_Name,arr[i].location);
        for(int j=0;j<arr[i].num;j++){
            arr[i].l[j].size == (int)arr[i].l[j].size?printf("%s %d %d\n",arr[i].l[j].firm, (int) arr[i].l[j].size, arr[i].l[j].price):printf("%s %.1f %d\n", arr[i].l[j].firm, arr[i].l[j].size, arr[i].l[j].price);
        }
    }
}

void najeftina_ponuda(ITStore *arr, int n){
    int min=0; int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i].num;j++){
            if(arr[i].l[j].touch == 1){ min>arr[i].l[j].price || min == 0?min= arr[i].l[j].price,temp=i:0; }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\nNajniskata cena iznesuva: %d",arr[temp].store_Name,arr[temp].location,min);
}

int main(){
    ITStore s[100]; int n; scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%s %s %d", s[i].store_Name, s[i].location, &s[i].num);
        for (int j = 0; j < s[i].num; j++){
            scanf("%s %f %d %d", s[i].l[j].firm, &s[i].l[j].size, &s[i].l[j].touch ,&s[i].l[j].price);
        }
    }
    print(s, n); najeftina_ponuda(s, n);

    return 0;
}
