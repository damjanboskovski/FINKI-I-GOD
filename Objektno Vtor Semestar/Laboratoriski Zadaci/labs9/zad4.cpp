#include<iostream>
#include<cstring>
#include <math.h>
using namespace std;

constexpr auto EUR_VALUE = 61.00;
constexpr auto USD_VALUE = 50.00;
enum class ERROR{ NO_ERROR, DATE_ERROR, CURRENCY_ERROR };

class InvalidDateException{
    private:
        int day{0}, month{0}, year{0};
    public:
        InvalidDateException(){}
        InvalidDateException(int d, int m, int y){ this->day = d, this->month = m; this->year = y; }
        void print(){ cout<<"Invalid Date "<<day<<"/"<<month<<"/"<<year<<endl; }
};

class NotSupportedCurrencyException{
    private:
        char currecny[4];
    public:
        NotSupportedCurrencyException(){}
        NotSupportedCurrencyException(char *c){ strcpy(this->currecny,c); }
        void print(){ cout<<currecny<<" is not a supported currency"<<endl; }
};

class Transakcija{
    protected:
        int day{0}, month{0}, year{0}; double value{double()};
    public:
        static double EUR; static double USD;

        Transakcija(){}
        Transakcija(int d, int m, int y, double v){  this->day = d; this->month = m; this->year = y; this->value = v; }
        Transakcija(const Transakcija &other){ if(this != &other){ this->day = other.day; this->month = other.month; this->year = other.year; this->value = other.value; } }
        Transakcija &operator=(const Transakcija &other){ if(this != &other){ this->day = other.day; this->month = other.month; this->year = other.year; this->value = other.value; } return *this; }
        ~Transakcija(){}

        virtual double voDenari() = 0; virtual double voEvra() = 0; virtual double voDolari() = 0; virtual void print() = 0;
};

double Transakcija::EUR = EUR_VALUE;
double Transakcija::USD = USD_VALUE;

class DenarskaTransakcija : public Transakcija{
    public:
        DenarskaTransakcija(){}
        DenarskaTransakcija(int d, int m, int y, double v):Transakcija(d,m,y,v){ }
        DenarskaTransakcija(const DenarskaTransakcija &other):Transakcija(other.day,other.month,other.year,other.value){}
        DenarskaTransakcija &operator=(const DenarskaTransakcija &other){ if(this != &other){ this->day = other.day; this->month = other.month; this->year = other.year; this->value = other.value; } }
        ~DenarskaTransakcija(){}

        double voDenari(){ return this->value; }
        double voEvra(){ return this->value / EUR; }
        double voDolari(){ return this->value / USD; }
        void print(){ cout<<day<<"/"<<month<<"/"<<year<<" "<<value<<" MKD "<<endl; }
};

class DeviznaTransakcija : public Transakcija{
    private:
        char currency[4];
    public:
        DeviznaTransakcija(){}
        DeviznaTransakcija(int d, int m, int y, double v, char *c):Transakcija(d,m,y,v){ strcpy(this->currency,c); }
        DeviznaTransakcija(const DeviznaTransakcija &other):Transakcija(other.day,other.month,other.year,other.value){ if(this != &other){ strcpy(this->currency,other.currency); } }
        DeviznaTransakcija &operator=(const DeviznaTransakcija &other){ if(this != &other){ this->day = other.day; this->month = other.month; this->year = other.year; this->value = other.value; strcpy(this->currency,other.currency); } return *this; }
       ~DeviznaTransakcija(){}

       double voDenari(){ 
            if(strcmp(currency,"EUR") == 0){ return this->value * EUR; }
            if(strcmp(currency,"USD") == 0){ return floor(this->value * USD); }
            else { return this->value; }
        } 
        double voEvra(){ 
            if(strcmp(currency,"EUR") == 0){ return this->value; }
            if(strcmp(currency,"USD") == 0){ return (this->value * USD) / EUR; }
            else { return this->value / EUR; }
        } 
        double voDolari(){ 
            if(strcmp(currency,"USD") == 0){ return this->value; }
            if(strcmp(currency,"EUR") == 0){ return (this->value * EUR) / USD; }         
            else { return this->value / EUR; }
        } 
        void print(){ cout<<day<<"/"<<month<<"/"<<year<<" "<<value<<" "<<currency<<endl; }
};

class Smetka{
    private:
        Transakcija **arr{nullptr}; int num{0}; char accountNum[16]; double balanceMKD{double()};
    public:
        Smetka(){}
        Smetka(char *an, int b){ strcpy(this->accountNum,an); this->balanceMKD = b; }
        Smetka(const Smetka &other){
            if(this != &other){
                delete[] this->arr; this->arr = new Transakcija *[other.num]; for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
                strcpy(this->accountNum, other.accountNum); this->num = other.num; this->balanceMKD = other.balanceMKD; }
        }
        Smetka &operator=(const Smetka &other){
            if(this != &other){
                delete[] this->arr; this->arr = new Transakcija *[other.num]; for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
                strcpy(this->accountNum, other.accountNum); this->num = other.num; this->balanceMKD = other.balanceMKD; } return *this;
        }
        Smetka &operator+=(Transakcija *newTrans){
            Transakcija **temp = new Transakcija *[this->num+1]; for(int i=0; i<this->num; i++){ temp[i] = arr[i]; }
            temp[this->num++] = newTrans; delete[] this->arr; this->arr = new Transakcija *[this->num]; this->arr = temp; return *this;
        }
        ~Smetka(){ delete[] this->arr; this->arr = nullptr; }

        void izvestajVoDenari(){
            double sum = this->balanceMKD; for(int i=0; i<this->num; i++){ sum += arr[i]->voDenari(); }
            cout<<"Korisnikot so smetka: "<<accountNum<<" ima momentalno saldo od "<<sum<<" MKD"<<endl;
        }

        void pecatiTransakcii(){ for(int i=0; i<this->num; i++){ arr[i]->print(); } }
};

int main () {
	
	Smetka s ("300047024112789",1500); int n, den, mesec, godina, tip; double iznos; char valuta [4]; 

    cin>>n; cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
	for (int i=0;i<n;i++){
		cin>>tip>>den>>mesec>>godina>>iznos; if(tip == 2){ cin>>valuta; }
        try{
            if(den < 0 || den > 31 || mesec < 0 || mesec > 12){ throw(ERROR::DATE_ERROR); }		
		    if(tip == 2){ if(strcmp(valuta, "EUR")!=0 && strcmp(valuta,"USD")!=0){ throw(ERROR::CURRENCY_ERROR); } }
            throw(ERROR::NO_ERROR);
        }
        catch(ERROR ERROR_CODE){
            if(ERROR_CODE == ERROR::DATE_ERROR){ InvalidDateException ide(den,mesec,godina); ide.print(); }
            if(ERROR_CODE == ERROR::CURRENCY_ERROR){ NotSupportedCurrencyException nsce(valuta); nsce.print(); }
            if(ERROR_CODE == ERROR::NO_ERROR){
                if (tip==2){ Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta); s+=t; /*delete t;*/ }
		        else { Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos); s+=t; /*delete t;*/ }
            }
        }			
	}

    cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl; s.pecatiTransakcii();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl; s.izvestajVoDenari();
    cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;         
    double newEUR, newUSD; cin>>newEUR>>newUSD; Transakcija::EUR = newEUR; Transakcija::USD = newUSD;
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl; s.izvestajVoDenari();
    	
	return 0;
}