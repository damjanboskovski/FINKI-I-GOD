#include<iostream>
#include<cstring>

using namespace std;

class Sneakers {
private:
    char model[50];
    int size;
    float price;

public:
    Sneakers(const char *model = "", int size = 38, float price = 1000) : size(size), price(price) {
        strncpy(this->model, model, 49);
        this -> model[49] = 0;
    }

    friend istream &operator>>(istream &in, Sneakers &s) {
        return in >> s.model >> s.size >> s.price;
    }

    friend ostream &operator<<(ostream &out, const Sneakers &s) {
        return out << "Model: " << s.model << " Size: " << s.size << " Price: " << s.price;
    }

    Sneakers &operator+=(float increment) {
        price += increment;
        return *this;
    }

    Sneakers &operator*=(float coefficient) {
        price *= coefficient;
        return *this;
    }

    bool operator==(Sneakers &s) {
        return strcmp(this->model, s.model) == 0 && this->size == s.size;
    }

    char *getModel() {
        return model;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        this->price = price;
    }
};

class SneakersShop{
    protected:
        char storeName[50]; Sneakers *arr{nullptr}; int num{0}; static int higherP;
    public:
        SneakersShop(){}
        SneakersShop(char* storeName){
            strcpy(this->storeName, storeName); this->arr = new Sneakers[num];
        }
        SneakersShop(const SneakersShop& other){
            if(this != &other){
                this->num = other.num;
                strcpy(this->storeName, other.storeName);
                this->arr = new Sneakers[other.num];
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
            }
        }
        SneakersShop& operator=(const SneakersShop &other){
            if(this != &other){
                this->num = other.num;
                strcpy(this->storeName, other.storeName);
                this->arr = new Sneakers[other.num];
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
            } return *this;
        }
        ~SneakersShop(){ delete[] this->arr; }

        SneakersShop &operator+=(const Sneakers &other){
            Sneakers *temp = new Sneakers[this->num + 1];
            for(int i=0; i<num; i++){ temp[i] = this->arr[i]; }
            temp[num++] = other; delete[] this->arr; this->arr = temp;
        }

        virtual float checkItemAvailability(char* model, int size){
            for(int i=0; i<num; i++){
                if(model == arr[i].getModel() && size == arr[i].getSize()){
                    return arr[i].getPrice();
                }
                else { return 0; }
            }
        }

        static int setIncreasePercentage(int n){ higherP = n; }

        int operator++(){ int sum=0; for(int i=0; i<num; i++) { sum += arr[i].getPrice() * (higherP/100); } return sum; }

        friend ostream &operator<<(ostream &out, SneakersShop &other){
            return out<<"Sneakers shop: "<<other.storeName<<endl<<"List of sneakers: "<<endl;
            if(other.num == 0){ out<<"EMPTY"; }
            else{ for(int i=0; i<other.num; i++){ cout<<i+1<<other.arr[i]; } }
            return out<<endl;
        }
};

int SneakersShop::higherP = 5;

class OnlineSneakersShop : public SneakersShop{
    private:
        char url[100]; static int discount;
    public:
        OnlineSneakersShop(){}
        OnlineSneakersShop(char* storeName, char* url) : SneakersShop(storeName){
            strcpy(this->url, url);
        }
        OnlineSneakersShop(OnlineSneakersShop &other) : SneakersShop(other.storeName){
            if(this != &other){ strcpy(this->url, other.url); }
        }
        OnlineSneakersShop &operator=(OnlineSneakersShop &other){
            if(this != &other){
                strcpy(this->storeName, other.storeName);
                strcpy(this->url, other.url);
            }
        }
        ~OnlineSneakersShop(){}

        float checkItemAvailability(char* model, int size){
            for(int i=0; i<num; i++){
                if(model == arr[i].getModel() && size == arr[i].getSize()){
                    return arr[i].getPrice();
                }
            }
        }

        friend ostream &operator<<(ostream &out, OnlineSneakersShop &other){
            out<<" URL: "<<other.url<<endl;
//            for(int i=0; i<num; i++){
//                out<<i+1<<other.arr[i];
//            }
        }
};

int OnlineSneakersShop::discount = 10;

void printShop(SneakersShop *shop) {
    OnlineSneakersShop *casted = dynamic_cast<OnlineSneakersShop *>(shop);
    if (casted) {
        cout << (*casted);
    } else {
        cout << (*shop);
    }
}

int main() {
    int testCase;
    cin >> testCase;
    char name[100];
    char url[100];

    if (testCase == 1) {
        cout << "TESTING CLASS SneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
    } else if (testCase == 2) {
        cout << "TESTING CLASS OnlineSneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
    } else if (testCase == 3) {
        cout << "TESTING CLASS SneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 4) {
        cout << "TESTING CLASS OnlineSneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 5) {
        cout << "TESTING METHOD checkItemAvailability" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        char model[100];
        int size;
        cin >> model >> size;
        cout << "Price for model " << model << " with size: " << size << " is: "
             << shop->checkItemAvailability(model, size) << endl;
    } else if (testCase == 6) {
        cout << "TESTING OPERATOR ++" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);
    } else if (testCase == 7) {
        cout << "TESTING OPERATOR ++ AND CHANGE OF STATIC MEMBER" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

        cout <<"CHANGING INCREASE PERCENTAGE IN SneakersShop" << endl;
        SneakersShop::setIncreasePercentage(17);

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

    }


}
