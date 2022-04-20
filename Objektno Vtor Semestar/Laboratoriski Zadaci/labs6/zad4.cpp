#include <iostream>
#include <cstring>
using namespace std;

class Nedviznina{
    protected:
        char *address{nullptr}; int area{0}, price{0};
    public:
        Nedviznina(){ this->address = nullptr; this->address = new char[1024]; }
        ~Nedviznina(){ delete[] this->address; }
        friend istream &operator>>(istream &in, Nedviznina &other){ in >> other.address >> other.area >> other.price; return in; }
        int cena(){ return area * price; } double danokNaImot(){ return 0.05 * cena(); }
        char *getAdresa(){ return address; } 
        void pecati(){ cout<< address<<", Kvadratura: "<<area<<", Cena po Kvadrat: "<<price<<endl;}
};

class Vila : public Nedviznina{
    private:
        int tax{0};
    public:
        Vila() : Nedviznina(){}
        Vila(int t):Nedviznina(){ this->tax = t; }
        friend istream &operator>>(istream &in, Vila &other){ in>>other.address>>other.area>>other.price>>other.tax; return in; }
        double danokNaImot(){ return cena() * (tax + 5)/100.0; }
        void pecati(){ cout<< address<<", Kvadratura: "<<area<<", Cena po Kvadrat: "<<price<<", Danok na luksuz: "<<tax<<endl;}
};

int main(){
    Nedviznina n; Vila v;
    cin>>n>>v;
    n.pecati(); cout<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati(); cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}