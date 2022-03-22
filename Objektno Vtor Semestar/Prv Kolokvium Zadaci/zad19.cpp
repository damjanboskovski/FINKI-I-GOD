#include <iostream>
#include <cstring>
using namespace std;

class IceCream{
    private:
        char *name, ingridients[100]; float price; int discount = 0;
    public:
        IceCream(){discount = 0; name = nullptr;}
        IceCream(char *n, char *i, float p){
            this->name = new char[strlen(n)+1]; strcpy(this->name,n);
            strcpy(this->ingridients,i); price = p;
        }
        IceCream(const IceCream &other){
            this->name = new char[strlen(other.name)+1]; 
            strcpy(this->name,other.name);
            strcpy(this->ingridients,other.ingridients); this->price = other.price; this->discount = other.discount;
        }
        ~IceCream(){delete[] name;}

        IceCream &operator = (const IceCream &other){
             this->name = new char[strlen(other.name)+1]; strcpy(this->name,other.name);
            strcpy(this->ingridients,other.ingridients); this->price = other.price; this->discount = other.discount; return *this;
        }

        friend ostream &operator<<(ostream &out, IceCream &other){
            out<<other.name<<": "<<other.ingridients<<" "<<other.price<<" ";
            if(other.discount > 0){ out<<"("<<other.price * (100 - other.discount) / 100 <<")";} return out;
        }

        IceCream &operator++(){this->discount+=5; return *this;}

        IceCream operator+(const char *ex){
            char *newName = new char[strlen(name)+strlen(ex)+3];
            strcat(newName,this->name); strcat(newName," + "); strcat(newName, ex);
            IceCream res(newName, this->ingridients, this->price + 10); res.setDiscount(discount); return res;
        }
        
        int setDiscount(int d){ this->discount = d; }
        void setName(char *n){ this->name = new char[strlen(n)+1]; strcpy(this->name,n); }
};

class IceCreamShop{
    private:
        char shop[50]; IceCream *arr; int num;
    public:
        IceCreamShop(){this->arr = nullptr; this->num = 0;};
        IceCreamShop(char *s){arr = new IceCream[num]; strcpy(this->shop,s);}
        IceCreamShop(const IceCreamShop &other){
            strcpy(this->shop,other.shop); num = other.num; this->arr = new IceCream[num];
            for(int i=0;i<num;i++){this->arr[i] = other.arr[i];}}
        ~IceCreamShop(){delete[] arr;};

        IceCreamShop &operator=(const IceCreamShop &other){
            delete[] arr;
            strcpy(this->shop, other.shop); this->num = other.num; this->arr = new IceCream[num];
            for(int i=0;i<this->num;i++){this->arr[i] = other.arr[i];} return *this;
        }

        IceCreamShop &operator+=(IceCream &other){
            IceCream *temp = arr; arr = new IceCream[this->num+1];
            for(int i=0;i<this->num;i++){ arr[i] = temp[i];}
            arr[this->num++] = other; delete[] temp; return *this; 
        }

        friend ostream &operator<<(ostream &out, IceCreamShop &other){
            out<<other.shop<<endl; for(int i=0;i<other.num;i++){ out<<other.arr[i]<<endl; } return out; }
};


int main() {
    char name[100], ingr[100];
    float price; int discount, testCase; cin >> testCase; cin.get();

    if(testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name,100); cin.getline(ingr,100); cin >> price >> discount;

        cout << "CONSTRUCTOR" << endl; IceCream ic1(name, ingr, price); ic1.setDiscount(discount);
        cin.get(); cin.getline(name,100); cin.getline(ingr,100); cin >> price >> discount;

        IceCream ic2(name, ingr, price); ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl << ic1 << endl  << ic2 << endl; 
        cout<< "OPERATOR ++" << endl; ++ic1; cout << ic1 << endl; 
        cout<< "OPERATOR +" << endl; IceCream ic3 = ic2 + "chocolate"; cout << ic3 << endl;
    } 

    else if(testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name,100); cin.getline(ingr,100); cin >> price;
        cout << "CONSTRUCTOR" << endl; IceCream ic1(name, ingr, price); cout << ic1 << endl; 

        cout << "COPY CONSTRUCTOR" << endl; IceCream ic2(ic1);
        cin.get(); cin.getline(name,100); ic2.setName(name);
        cout << ic1 << endl << ic2 << endl;

        cout<< "OPERATOR =" << endl; ic1 = ic2; cin.getline(name,100); ic2.setName(name); 
        cout << ic1 << endl << ic2 << endl; cin >> discount; ic1.setDiscount(discount);
    } 
    
    else if(testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50]; cin.getline(icsName,100); 
        
        cout << "CONSTRUCTOR" << endl; IceCreamShop ics(icsName); int n; cin >> n;

        cout << "OPERATOR +=" << endl;
        for(int i = 0; i < n; ++i) { 
            cin.get(); cin.getline(name,100); cin.getline(ingr,100); cin >> price; 
            IceCream ic(name, ingr, price); ics += ic; }
        cout << ics;
    } 
    
    else if(testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50]; cin.getline(icsName,100); IceCreamShop ics(icsName);
        int n; cin >> n;
        for(int i = 0; i < n; ++i) {
            cin.get(); cin.getline(name,100); cin.getline(ingr,100); cin >> price;
            IceCream ic(name, ingr, price); ics += ic; }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60); IceCreamShop icp = ics;
        ics+=x;cout << ics << endl << icp << endl;
    }
    return 0;
}