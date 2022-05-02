#include <iostream>
#include <cstring>
using namespace std;

class ZicanInstrument{
    protected:
        char name[20]; int stringNum{0}, price{0};
    public:
        ZicanInstrument(char *n, int s, int p){ strcpy(this->name,n); this->stringNum = s; this->price = p; }
        bool operator==(ZicanInstrument &other) const { return stringNum == other.stringNum; }
        friend ostream &operator<<(ostream &out, ZicanInstrument &other){
            out<<other.name<<" "<<other.stringNum<<" "<<other.price<<endl; return out;
        }
        virtual double cena() = 0;
};

class Mandolina : public ZicanInstrument{
    private:
        char form[20];
    public:
        Mandolina(char *n, int s, int p, char *f):ZicanInstrument(n,s,p){ strcpy(this->form,f); }
        double cena(){ return !strcmp("Neapolitan",form)?1.15*price:price; }
};

class Violina : public ZicanInstrument{
    private:
        double size{0};
    public:
        Violina(char *n, int s, int p, double size):ZicanInstrument(n,s,p){ this->size = size; }
        double cena(){ 
            if(size == 0.25){ return 1.1 * price; } 
            else if(size == 1){ return 1.2 * price; }
            else return price;
        }
};

void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument **i, int n){
    for(int j=0; j<n; j++){ if(*i[j] == zi){ cout<<i[j]->cena()<<endl; } }
}

int main() {
	char ime[20], forma[20]; int brojZici; float cena;
	cin >> ime >> brojZici >> cena >> forma; Mandolina m(ime, brojZici, cena, forma);
	int n; cin >> n; ZicanInstrument **zi = new ZicanInstrument*[2 * n];

	for(int i = 0; i < n; ++i) {
		cin >> ime >> brojZici >> cena >> forma;
		zi[i] = new Mandolina(ime, brojZici, cena, forma);
	}
	for(int i = 0; i < n; ++i) {
		float golemina; cin >> ime >> brojZici >> cena >> golemina;
		zi[n + i] = new Violina(ime, brojZici, cena, golemina);
	}

	pecatiInstrumenti(m, zi, 2 * n);
    for(int i = 0; i < 2 * n; ++i) { delete zi[i]; } delete [] zi; return 0;
}