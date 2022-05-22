#include<iostream>
#include<cstring>
using namespace std;

constexpr double DEFAULT_GUSTINA = 0.8;
constexpr double MASA_NA_AMBALAZA = 0.2;
constexpr int SIZE = 8;

class ImaMasa{
    public:
        virtual double vratiMasa() = 0;
        virtual void pecati() = 0;
};

class PaketPijalok : public ImaMasa{
    protected:
        static const double gustina, masaNaAmbalaza;
        double volumenEden{0}; int kolicina{0};
    public:
        PaketPijalok(){}
        PaketPijalok(double v, int k){ this->volumenEden = v; this->kolicina = k; }
        PaketPijalok(const PaketPijalok &other){ if(this != &other){ this->volumenEden = other.volumenEden; this->kolicina = other.kolicina; } }
        PaketPijalok &operator=(const PaketPijalok &other){ if(this != &other){ this->volumenEden = other.volumenEden; this->kolicina = other.kolicina; } return *this; }
        ~PaketPijalok(){}
        double vratiMasa() { return (this->volumenEden * gustina + masaNaAmbalaza) * getKolicina(); }
        int getKolicina() { return this->kolicina; } 
};

const double PaketPijalok::gustina = DEFAULT_GUSTINA;
const double PaketPijalok::masaNaAmbalaza = MASA_NA_AMBALAZA;

class PaketSok : public PaketPijalok{
    private:
        bool daliGaziran;
    public:
        PaketSok(){}
        PaketSok(double v, int k, bool g) : PaketPijalok(v,k){ this->daliGaziran = g; }
        PaketSok(const PaketSok &other) : PaketPijalok(other.gustina, other.kolicina){ if(this != &other){ this->daliGaziran = other.daliGaziran; } }
        PaketSok &operator=(const PaketSok &other){ if(this!=&other){ this->daliGaziran = other.daliGaziran; }  return *this;}
        ~PaketSok(){}

        void pecati(){ cout<<"Paket sok"<<endl<<"kolicina "<<getKolicina()<<", so po "<<volumenEden * gustina<<" l(dm3)"<<endl; }
        double vratiMasa(){ if(!daliGaziran){ return PaketPijalok::vratiMasa() + (0.1 * getKolicina()); } return PaketPijalok::vratiMasa(); }
};

class PaketVino : public PaketPijalok{
    private:
        double procentAlkohol;
    public:
        PaketVino(){}
        PaketVino(double v, int k, double p):PaketPijalok(v,k){ this->procentAlkohol = p; }
        PaketVino(const PaketVino &other):PaketPijalok(other.gustina,other.kolicina){ if(this != & other){ this->procentAlkohol = other.procentAlkohol; } }
        PaketVino &operator=(const PaketVino &other){ if(this != &other){ this->procentAlkohol = other.procentAlkohol; } return *this; }
        ~PaketVino(){}
        double vratiMasa(){ return PaketPijalok::vratiMasa() * (0.9 + this->procentAlkohol); }        
        void pecati(){ cout<<"Paket vino"<<endl<<"kolicina "<<getKolicina()<<", "<<procentAlkohol * 100<<"% alkohol od po "<<volumenEden * gustina<<" l(dm3)"<<endl; }
        double getProcentAlkohol() { return this->procentAlkohol; }
};

class Kamion{
    private:
        char *registracija{nullptr}, *vozac{nullptr}; ImaMasa **arr{nullptr}; int num{0};
    public:
        Kamion(){}
        Kamion(char *v){ this->vozac = new char[strlen(v)+1]; strcpy(this->vozac,v); }
        Kamion(char *r, char *v){
            this->vozac = new char[strlen(v)+1]; strcpy(this->vozac,v);
            this->registracija = new char[strlen(r)+1]; strcpy(this->registracija, r);
        }
        Kamion(const Kamion &other){
            if(this != &other){
                this->num = other.num;
                delete[] this->vozac; this->vozac = new char[strlen(other.vozac)+1]; strcpy(this->vozac,other.vozac);
                delete[] this->registracija; this->registracija = new char[strlen(other.registracija)+1]; strcpy(this->registracija,other.registracija);
            }
        }
        Kamion &operator=(const Kamion &other){
            if(this != &other){
                this->num = other.num;
                delete[] this->vozac; this->vozac = new char[strlen(other.vozac)+1]; strcpy(this->vozac,other.vozac);
                delete[] this->registracija; this->registracija = new char[strlen(other.registracija)+1]; strcpy(this->registracija,other.registracija);
            } return *this;
        }
        ~Kamion(){ if(this->arr != nullptr){ delete[] this->arr; this->arr = nullptr; } delete[] this->vozac; this->vozac = nullptr; delete[] this->registracija; this->registracija = nullptr; }

        void reg(char *reg){ this->registracija = new char[strlen(reg)+1]; strcpy(this->registracija, reg); }
        void dodadiElement(ImaMasa *im){ 
            ImaMasa **temp = new ImaMasa *[this->num+1];
            for(int i=0; i<this->num; i++){ temp[i] = this->arr[i]; }
            temp[this->num++] = im; delete[] this->arr; this->arr = new ImaMasa *[this->num]; this->arr = temp;
        } 
        Kamion pretovar(char *reg, char *name){
            Kamion temp(reg,name); int pos=0; double max=0.00;
            for(int i=0; i<this->num; i++){ if(this->arr[i]->vratiMasa() > max){ max = this->arr[i]->vratiMasa(); pos = i; } }
            for(int i=0; i<this->num; i++){ if(i != pos){ temp.dodadiElement(this->arr[i]); } } return temp;
        }
        double vratiVkupnaMasa(){ double sum=0.00; for(int i=0; i<this->num; i++){ sum+=arr[i]->vratiMasa(); } return sum; }
        void pecati(){ 
            cout<<"Kamion so registracija "<<this->registracija<<" i vozac "<<this->vozac<<" prenesuva: "<<endl;
            for(int i=0; i<this->num; i++){ arr[i]->pecati(); }
        }        
};

int main()
{
    char ime[20], reg[9]; double vol,proc; int kol; bool g; cin>>reg>>ime;
    try{
        if((isalpha(reg[0])) && (isalpha(reg[strlen(reg)-1])) && (isalpha(reg[1])) && (isalpha(reg[strlen(reg)-2]) && (strlen(reg) == 8) ) ){ 
            Kamion A(reg, ime); ImaMasa **d = new ImaMasa *[5];

            cin>>vol>>kol>>g;    d[0] = new PaketSok(vol,kol,g);
            cin>>vol>>kol>>proc; d[1] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol>>proc; d[2] = new PaketVino(vol, kol, proc);
            cin>>vol>>kol>>g;    d[3] = new PaketSok(vol, kol, g);
            cin>>vol>>kol>>proc; d[4] = new PaketVino(vol, kol, proc);

            A.dodadiElement(d[0]); A.dodadiElement(d[1]); A.dodadiElement(d[2]); A.dodadiElement(d[3]); A.dodadiElement(d[4]);
            A.pecati(); cout<<"Vkupna masa: "<<A.vratiVkupnaMasa()<<endl; 
        
            cin>>reg>>ime;
            try{
                if((isalpha(reg[0])) && (isalpha(reg[strlen(reg)-1])) && (isalpha(reg[1])) && (isalpha(reg[strlen(reg)-2]) && (strlen(reg) == 8) ) ){ 
                    Kamion B = A.pretovar(reg, ime); B.pecati();
                    cout<<"Vkupna masa: "<<B.vratiVkupnaMasa()<<endl;
                }
                else{ throw(404); }
            }
            catch (int error){ cout << "Pogresno vnesena registracija" << endl; }
        }
        else{ throw(404); }
    }
    catch (int error){ cout << "Pogresno vnesena registracija" << endl; } return 0;
}
