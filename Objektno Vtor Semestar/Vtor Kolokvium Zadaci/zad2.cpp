#include <iostream>
#include <cstring>
using namespace std;

class Vozac{
    protected:
        char name[100]; int age{0}, races{0}; bool veteran{false};
    public:
        Vozac(){}
        Vozac(char *n, int a, int r, bool v){ strcpy(this->name,n); this->age = a; this->races = r; this->veteran = v; }
        Vozac(const Vozac &other){
            if(this != &other){ strcpy(this->name,other.name); this->age = other.age; this->races = other.races; this->veteran = other.veteran; }
        }
        Vozac &operator=(const Vozac &other){
            if(this != &other){ strcpy(this->name,other.name); this->age = other.age; this->races = other.races; this->veteran = other.veteran; } return *this;
        }
        virtual float earnings() = 0;
        virtual float danok() = 0;
        friend ostream &operator<<(ostream &out, const Vozac &other){
            out<<other.name<<endl<<other.age<<endl<<other.races<<endl; if(other.veteran){ out<<"VETERAN"<<endl; } return out; 
        }
        bool operator==(Vozac &other){ return this->earnings() == other.earnings(); }
};

class Avtomobilist : public Vozac{
    private:
        float price;
    public:
        Avtomobilist(){}
        Avtomobilist(char *n, int a, int r, bool v, float p):Vozac(n,a,r,v){ this->price = p; }
        Avtomobilist(Avtomobilist &other):Vozac(other.name,other.age,other.races,other.veteran){ if(this != &other){ this->price = other.price; } }
        Avtomobilist &operator=(Avtomobilist &other){
            if(this != &other){
                strcpy(this->name,other.name); this->age = other.age; this->races = other.races; this->veteran = other.veteran; this->price = other.price; 
            } return *this;
        }

        float earnings(){ return this->price / 5; } float danok(){ return this->races > 10?0.15 * earnings():0.1 * earnings();  }
};

class Motociklist : public Vozac{
    private:
        int power{0};
    public:
        Motociklist(){}
        Motociklist(char *n, int a, int r, bool v, int p) : Vozac(n,a,r,v){ this->power = p; }
        Motociklist(Motociklist &other):Vozac(other.name,other.age,other.races,other.veteran){ if(this != &other){ this->power = other.power; } }
        Motociklist &operator=(const Motociklist &other){ 
            if(this != &other){
                strcpy(this->name,other.name); this->age = other.age; this->races = other.races; this->veteran = other.veteran; this->power = other.power;
            } return *this;
        }
        ~Motociklist(){}
        float earnings(){ return this->power * 20; } float danok(){ return this->veteran?0.25 * earnings():0.2 * earnings(); }
};

int soIstaZarabotuvachka(Vozac **v, int num, Vozac *vx){ int sum=0; for(int i=0; i<num; i++){ if(vx->earnings() == v[i]->earnings()){ sum++; } } return sum; }

int main() {
	int n, x, vozrast, trki; cin >> n >> x; Vozac **v = new Vozac*[n]; char ime[100]; bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) { float cena_avto; cin >> cena_avto; v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto); } 
        else { int mokjnost; cin >> mokjnost; v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost); }
	}

	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) { cout << *v[i] << v[i]->danok() << endl; }

	cin >> ime >> vozrast >> trki >> vet; int mokjnost; cin >> mokjnost; Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl << *vx << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) { delete v[i]; } delete [] v; delete vx; return 0;
}