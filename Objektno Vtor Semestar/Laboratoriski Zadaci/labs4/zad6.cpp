#include <iostream>
#include <cstring>
using namespace std;

enum Tip{LINUX, UNIX, WINDOWS};

class OperativenSistem{
    private:
        char *osName{nullptr}; float osVersion{0},osSize{0}; Tip type{(Tip)0};
    public:
        OperativenSistem(){osName = nullptr;}
        OperativenSistem(char *n, float v, Tip t, float s):OperativenSistem(){
            this->osName = new char[strlen(n)+1]; strcpy(this->osName,n);
            this->osVersion = v; this->type = t; this->osSize = s;
        }
        OperativenSistem(const OperativenSistem &other):OperativenSistem(){
            if(this != &other){
                delete[] osName; this->osName = new char[strlen(other.osName)+1]; strcpy(this->osName,other.osName);
                this->osVersion = other.osVersion; this->type = other.type; this->osSize = other.osSize;
            }
        }
        OperativenSistem &operator=(const OperativenSistem &other){
            if(this != &other){
                delete[] osName; this->osName = new char[strlen(other.osName)+1]; strcpy(this->osName,other.osName);
                this->osVersion = other.osVersion; this->type = other.type; this->osSize = other.osSize;
            } return *this;            
        }
        ~OperativenSistem(){delete[] osName; osName = nullptr;}

        float getVer()const{return this->osVersion;}
        void pecati(){cout<<"Ime: "<<this->osName<<" Verzija: "<<this->osVersion<<" Tip: "<<this->type<<" Golemina:"<<this->osSize<<"GB"<<endl;}
        bool verComp(const OperativenSistem &os){ return (this->osVersion == os.osVersion);}
        bool famComp(const OperativenSistem &os){ return (strcmp(this->osName,os.osName) == 0 && this->type == os.type);}
        bool isEqual(const OperativenSistem &os){ return (famComp(os) && verComp(os) && this->osSize == os.osSize);}
};

class Repozitorium{
    private:
        char repoName[20]; OperativenSistem *arr{nullptr}; int num{0};
    public:
        Repozitorium(){arr = nullptr;}
        Repozitorium(const char *n):Repozitorium(){strcpy(this->repoName,n); this->arr = new OperativenSistem[this->num];}
        ~Repozitorium(){delete[] arr; arr = nullptr;}

        void pecatiOperativniSistemi(){
            cout<<"Repozitorium: "<< this->repoName <<endl; for(int i=0; i<this->num; i++){this->arr[i].pecati();}
        }

        void dodadi(const OperativenSistem &other){
            OperativenSistem *temp = new OperativenSistem[this->num+1]; bool flag = false;
            for(int i=0; i<this->num; i++){
                temp[i] = (this->arr[i].famComp(other) && arr[i].getVer() < other.getVer())?(flag=true),other:this->arr[i];
            }
            if(flag == false){ temp[num++] = other;} delete[] this->arr; this->arr = temp;
        }

        void izbrishi(const OperativenSistem &other){
            for(int i=0; i<this->num; i++){
                if(this->arr[i].isEqual(other)){--this->num;
                for(int j=i; j<this->num; j++){this->arr[j] = arr[j+1];} break;
                }
            }
        }
};

int main() {
    char repoName[20],ime[20]; int brojOperativniSistemi = 0,tip; float verzija, golemina;
    cin >> repoName >> brojOperativniSistemi;
    Repozitorium repozitorium=Repozitorium(repoName);

    for (int i = 0; i<brojOperativniSistemi; i++){ cin >> ime >> verzija >> tip >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina); repozitorium.dodadi(os); }

    repozitorium.pecatiOperativniSistemi(); cin >> ime >> verzija >> tip >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os); repozitorium.pecatiOperativniSistemi();
    return 0;
}