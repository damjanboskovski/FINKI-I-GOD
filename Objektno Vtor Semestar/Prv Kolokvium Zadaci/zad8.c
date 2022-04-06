#include <stdio.h>
#include <string.h>

typedef struct Laptop{ char firm[100]; float size; int hasTouch, price}l;
typedef struct ITStore{ char storeName[100], location[100]; l arr[100]; int num; }its;

void print(its *a, int n)
{
    for(int i=0; i<n; i++){ printf("%s %s\n",a[i].storeName, a[i].location);
        for(int j=0; j<a[i].num; j++){
            if(a[i].arr[j].size == (int)a[i].arr[j].size){ printf("%s %d %d\n",a[i].arr[j].firm, (int)a[i].arr[j].size, a[i].arr[j].price); }
            else { printf("%s %.1f %d\n",a[i].arr[j].firm, a[i].arr[j].size, a[i].arr[j].price); } } }
}

void cheapest_store(its *a, int n)
{
    int min=0,pos=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<a[i].num; j++) {
            if(a[i].arr[j].hasTouch == 1 && (min>a[i].arr[j].price || min == 0)) { min = a[i].arr[j].price; pos = i; } } }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\nNajniskata cena iznesuva: %d",a[pos].storeName, a[pos].location,min);
}

int main()
{
    int num; scanf("%d", &num); its store[100];

    for(int i=0; i<num; i++){ scanf("%s %s %d",store[i].storeName, store[i].location, &store[i].num);
        for(int j=0; j<store[i].num; j++){ scanf("%s %f %d %d",store[i].arr[j].firm, &store[i].arr[j].size, &store[i].arr[j].hasTouch, &store[i].arr[j].price); } }
    print(store, num); cheapest_store(store, num);
    return 0;
}
