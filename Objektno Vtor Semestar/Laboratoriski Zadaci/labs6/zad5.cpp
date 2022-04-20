#include <iostream>
#include <cstring>
using namespace std;

class Ekipa{
    protected:
        char name[15]; int wins{0},loses{0};
    public:
        void print(){ cout<<"Ime: "<<name<<" Pobedi: "<<wins<<" Porazi: "<<loses; }
};

class FudbalskaEkipa : public Ekipa{
    private:
        int red, yellow, draw;
    public:
        FudbalskaEkipa(char *n, int w, int l, int r, int y, int d){  strcpy(name,n); wins = w; loses = l; red = r; yellow = y; draw = d; }
        void pecati(){ Ekipa::print(); cout<<" Nereseni: "<<draw<<" Poeni: "<<wins*3+draw<<endl; }
};

int main(){
	char ime[15]; int pob,por,ck,zk,ner; cin>>ime>>pob>>por>>ck>>zk>>ner;
	FudbalskaEkipa f1(ime,pob,por,ck,zk,ner); f1.pecati(); return 0;
}