#include <stdio.h>
#include <string.h>

typedef struct Product{char code[20]; int price, num;}Product;
typedef struct Order{char name[15]; Product arr[10]; int orders[10], n;}Order;

void print(Order n){
    printf("Faktura za %s\n",n.name); int sum=0;
    for(int i=0;i<n.n;i++){
        for(int j=0;j<n.n - i - 1;j++){
            if(strcmp(n.arr[j].code,n.arr[j+1].code) > 0) { Product temp=n.arr[j]; n.arr[j] = n.arr[j+1]; n.arr[j+1]=temp; } } }
    
    for(int i=0;i<n.n;i++){
        if(n.orders[i] > n.arr[i].num){printf("Fakturata ne moze da se izgotvi"); return;}
        else { printf("%s %d %d %d\n",n.arr[i].code,n.arr[i].price,n.orders[i],n.arr[i].price * n.orders[i]); sum+=n.arr[i].price * n.orders[i];}
    } printf("Vkupnata suma na fakturata e %d", sum);
}

int main() {
    Order o; scanf("%s%d",o.name, &o.n);
    for (int i = 0; i < o.n; ++i) { scanf("%s%d%d",o.arr[i].code, &o.arr[i].price, &o.arr[i].num); }
    for (int j = 0; j < o.n; ++j) { scanf("%d",&o.orders[j]); }
    print(o); return 0;
}