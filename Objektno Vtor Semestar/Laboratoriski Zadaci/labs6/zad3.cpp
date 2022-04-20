#include <iostream>
#include <cstring>
using namespace std;

class Lekar{
    protected:
        int facsimile{0}; char name[20], surname[20]; double startingPayment{0};
    public:
        Lekar(){}
        Lekar(int f, char *n, char *s, double p){ this->facsimile = f; strcpy(this->name,n); strcpy(this->surname,s); this->startingPayment = p; }
        Lekar(const Lekar &other){ this->facsimile = other.facsimile; strcpy(this->name,other.name); strcpy(this->surname,other.surname); this->startingPayment = other.startingPayment; }
        ~Lekar(){}
        double plata(){ return this->startingPayment; }
        void pecati(){ cout<<this->facsimile<<": "<<name<<" "<<surname<<endl; }
};

class MaticenLekar : public Lekar{
    private:
     int pacientNum{0}; double *registrationFee{nullptr};
    public:
        MaticenLekar() : Lekar(){ this->registrationFee = nullptr; }
        MaticenLekar(Lekar &l, int p, double *r) : Lekar(l){
            this->pacientNum = p; this->registrationFee = new double[p];
            for(int i=0; i<this->pacientNum; i++){ this->registrationFee[i] = r[i]; }
        }
        MaticenLekar(const MaticenLekar &other):Lekar(other){
            if (this != &other){
                this->pacientNum = other.pacientNum; this->registrationFee = new double[other.pacientNum];
                for(int i=0; i<other.pacientNum; i++){ this->registrationFee[i] = other.registrationFee[i]; }
            }
        }
        MaticenLekar &operator=(const MaticenLekar &other){
            if (this != &other){
                this->pacientNum = other.pacientNum; facsimile = other.facsimile; strcpy(name,other.name);
                strcpy(surname,other.surname); startingPayment = other.startingPayment;
                delete[] this->registrationFee; this->registrationFee = new double[other.pacientNum];
                for(int i=0; i<other.pacientNum; i++){ this->registrationFee[i] = other.registrationFee[i]; }
            } return *this;
        }
        ~MaticenLekar(){ delete[] this->registrationFee; this->registrationFee = nullptr; }

        void pecati(){ Lekar::pecati(); cout<<"Prosek na kotizacii: "<<regFee()<<endl; }
        double regFee(){ double sum=0; for(int i=0; i<this->pacientNum; i++){ sum+=registrationFee[i]; } return sum/pacientNum; }
        double plata(){ return Lekar::plata() + (0.3 * regFee()); }
};


int main() {
	int n, pacienti, faksimil; double kotizacii[100], osnovnaPlata; char ime [20], prezime [20]; cin>>n;

	Lekar * lekari = new Lekar [n]; MaticenLekar * maticni = new MaticenLekar [n];
	
	for (int i=0;i<n;i++){ cin >> faksimil >> ime >> prezime >> osnovnaPlata; lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);	}
	for (int i=0;i<n;i++){ cin >> pacienti; for (int j=0;j<pacienti;j++){ cin >> kotizacii[j]; } maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii); }
	
	int testCase; cin>>testCase;
	
	if (testCase==1){ cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
		for (int i=0;i<n;i++){ lekari[i].pecati(); cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl; }
	}
	else { cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
		for (int i=0;i<n;i++){ maticni[i].pecati(); cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl; }
	}
	delete [] lekari; delete [] maticni; return 0;
}