#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class Karticka{
    protected:
        char smetka[16]; int pin; bool povekjePin;
    public:
        Karticka(){}
        Karticka(char* smetka,int pin){ strcpy(this->smetka,smetka); this->pin=pin; this->povekjePin=false; }
        Karticka(const Karticka &other){ if(this != &other){ strcpy(this->smetka,other.smetka); this->pin = other.pin; this->povekjePin = false; } }
        Karticka &operator=(const Karticka &other){ if(this != &other){ strcpy(this->smetka,other.smetka); this->pin = other.pin; this->povekjePin = false; } return *this; }
        virtual ~Karticka(){}
        
        friend ostream &operator<<(ostream &out, const Karticka &other){ return out<<other.smetka<<": "<<other.getTezina()<<endl; }
        virtual int getTezina() const { return ceil(log10(pin)); }
        char *getSmetka(){ return smetka; } int getPin(){ return pin; } bool getDopolnitelenPin(){ return povekjePin; }
};

class OutOfBoundsException{
    public:
        static void message(){ cout << "Brojot na pin kodovi ne moze da go nadmine dozvolenoto" << endl; }
};

class SpecijalnaKarticka : public Karticka{
    private:
        int *pins{nullptr}, num{0}; const static int P = 4;
    public:
        SpecijalnaKarticka(){}
        SpecijalnaKarticka(char *s, int p) : Karticka(s,p){ this->povekjePin = true; this->pins = new int[this->num]; }
        SpecijalnaKarticka(const SpecijalnaKarticka &other) : Karticka(other){
            if(this != &other){
                this->povekjePin = true; this->num = other.num; this->pins = new int[other.num];
                for(int i=0; i<other.num; i++){ this->pins[i] = other.pins[i]; }
            }
        }
        ~SpecijalnaKarticka(){ delete[] this->pins; }

        SpecijalnaKarticka &operator+=(int n){
            if(num == P){ throw OutOfBoundsException(); }
            int *temp = new int[this->num+1];
            for(int i=0; i<this->num; i++){ temp[i] = this->pins[i]; }
            temp[num++] = n; delete[] this->pins; this->pins = temp; return *this;
        }

        int getTezina() const { return Karticka::getTezina() + num; }
};

class Banka {
    private:
        char naziv[30]; Karticka *karticki[20]; int broj; static int LIMIT;
    public:
        Banka(char *naziv, Karticka** karticki,int broj ){
            strcpy(this->naziv,naziv); this->broj=broj;
            for (int i=0;i<broj;i++){
                if (karticki[i]->getDopolnitelenPin()){ this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i])); }
                else this->karticki[i]=new Karticka(*karticki[i]);
            }   
        }
    ~Banka(){ for(int i=0;i<broj;i++) delete karticki[i]; }

    static void setLIMIT(int n){ LIMIT = n; }
    void pecatiKarticki(){
        cout<<"Vo bankata "<<naziv<<" moze da se probijat kartickite:"<<endl;
        for(int i=0; i<broj; i++){ if(karticki[i]->getTezina() <= LIMIT){ cout<<*karticki[i]; } }
    }

    void dodadiDopolnitelenPin(char *smetka, int pin){
        for(int i=0; i<broj; i++){
            if(karticki[i]->getDopolnitelenPin()){
                if(!strcmp(smetka,karticki[i]->getSmetka())){
                    *dynamic_cast<SpecijalnaKarticka*>(karticki[i]) += pin;
                }
            }
        }
    }
};

int Banka::LIMIT = 7;

int main(){
    Karticka **niza; int n, m, pin; char smetka[16]; bool daliDopolnitelniPin; cin>>n; niza = new Karticka*[n];
    for (int i=0;i<n;i++){
        cin>>smetka>>pin>>daliDopolnitelniPin;
        if (!daliDopolnitelniPin){ niza[i]=new Karticka(smetka,pin); }
        else { niza[i]=new SpecijalnaKarticka(smetka,pin); }
    }

    Banka komercijalna("Komercijalna",niza,n); for (int i=0;i<n;i++){ delete niza[i]; } 
    delete [] niza; cin>>m;
   
    for (int i=0;i<m;i++){ cin>>smetka>>pin;
        try{ komercijalna.dodadiDopolnitelenPin(smetka,pin); }
        catch(OutOfBoundsException){ OutOfBoundsException::message(); }
    }

    Banka::setLIMIT(5); komercijalna.pecatiKarticki(); return 0;
}
