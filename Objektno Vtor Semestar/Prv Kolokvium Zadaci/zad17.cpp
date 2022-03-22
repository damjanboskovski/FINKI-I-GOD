#include <iostream>
#include <cstring>
using namespace std;

enum Tip{LINUX, UNIX, WINDOWS};

class OperativenSistem{
    private:
        char *osName; float osVesion, osSize; Tip osType;
    public:
        OperativenSistem(){osName = nullptr;};
        OperativenSistem(char *n, float v, Tip t, float s){
            this->osName = new char[strlen(n)+1]; strcpy(this->osName,n);
            this->osVesion = v; this->osType = t; this->osSize = s; }
        OperativenSistem(const OperativenSistem &other) {
            this->osName = new char[strlen(other.osName)+1]; strcpy(this->osName,other.osName);
            this->osVesion = other.osVesion; this->osType = other.osType; this->osSize = other.osSize; }
        ~OperativenSistem(){delete[] osName;};

        OperativenSistem &operator=(const OperativenSistem &other){
            osName = new char[strlen(other.osName)+1];
            strcpy(this->osName,other.osName); this->osVesion = other.osVesion; 
            this->osType = other.osType; this->osSize = other.osSize; return *this; }

        float getVer()const{return this->osVesion;} 
        void print(){cout<<"Ime: "<<this->osName<<" Verzija: "<<this->osVesion<<" Tip: "<<this->osType<<" Golemina:"<<this->osSize<<"GB"<<endl;}
        bool verComp(const OperativenSistem &other){ return (this->osVesion == other.osVesion);}
        bool familyComp(const OperativenSistem &other){ return (strcmp(this->osName,other.osName) == 0 && this->osType == other.osType);}
        bool isEqual(const OperativenSistem &other){ return (familyComp(other) && verComp(other) && this->osSize == other.osSize);}
};

class Repozitorium{
    private:
        char repoName[20]; OperativenSistem *os; int osNum;
    public:
        Repozitorium(){};
        Repozitorium(const char *r){ strcpy(this->repoName,r); os = new OperativenSistem[this->osNum]; }
        ~Repozitorium(){delete[] os;};

        void pecatiOperativniSistemi(){
            cout<<"Repozitorium: "<< repoName <<endl;
            for(int i=0;i<osNum;i++){ this->os[i].print(); } }

        void izbrishi(const OperativenSistem &other){
            for(int i=0;i<osNum;i++){
                if(this->os[i].isEqual(other)){ --this->osNum;
                    for(int j=i;j<osNum;j++){ this->os[j] = os[j+1]; } break; } } }
        
        void dodadi(const OperativenSistem &other){
            OperativenSistem *temp = new OperativenSistem[osNum+1]; bool flag = false;
            for(int i=0;i<this->osNum;i++){
                temp[i] = (this->os[i].familyComp(other) && os[i].getVer() < other.getVer() )?(flag=true),other:this->os[i]; }
            if(flag == false){ temp[osNum++] = other; } delete[] this->os; this->os=temp; }
};

int main() 
{
    char repoName[20];cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0; cin>>brojOperativniSistemi;
    char ime[20]; float verzija, golemina; int tip;

    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime>>verzija>>tip>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi(); cin>>ime>>verzija>>tip>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os); repozitorium.pecatiOperativniSistemi();
    return 0;
}