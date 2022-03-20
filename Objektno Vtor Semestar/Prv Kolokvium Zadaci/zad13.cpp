#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

class Zichara{
    private:
        char *location; int priceDaily;
    public:
        Zichara(){location = nullptr;};
        Zichara(char *l, int p){location = new char[strlen(location)+1]; strcpy(location,l); priceDaily = p;}
        ~Zichara(){delete[] location;};

        int getPrice(){return priceDaily;}
};

class PlaninarskiDom{
    private:
        char name[15],type; int price[2]; bool lift; Zichara *z;
    public:
        PlaninarskiDom(){};
        PlaninarskiDom(char n[15], int *p, char t){
            strcpy(this->name, n); this->type = t; lift = false;
            for(int i=0;i<2;i++){this->price[i]=p[i];}
        }
        ~PlaninarskiDom(){};

        void setZichara(Zichara &z){this->z = &z; lift = true;}

        PlaninarskiDom &operator=(PlaninarskiDom &other){
            strcpy(this->name, other.name); this->type = other.type; lift = other.lift;
            for(int i=0;i<2;i++){this->price[i]=other.price[i];} z = other.z;
        }
        
        PlaninarskiDom &operator--(){ if(type == 'F'){return *this;} type++; return *this; }

        friend ostream &operator<<(ostream &out, PlaninarskiDom &other){
            out<<other.name<<" klasa:"<<other.type; (other.lift?out<<" so Zichara"<<endl:out<<endl); return out;
        }

        int operator<=(char t) { return ((int)toupper(this->type)>=(int)toupper(t)); }

        void presmetajDnevenPrestoj(int day, int month, int &sum){
            sum = (this->lift?this->z->getPrice():0) + (month>=4||(month <= 9 && day == 1)?price[0]:price[1]);
            if (day > 31 || day <= 0 || month > 12 || month <= 0){ throw 404; }
        }
};


int main(){
    PlaninarskiDom p; 

    char imePlaninarskiDom[15],mestoZichara[30],klasa;
    int ceni[12], dnevnakartaZichara; bool daliZichara;
    cin>>imePlaninarskiDom; for (int i=0;i<2;i++) {cin>>ceni[i];} cin>>klasa>>daliZichara;

    if (daliZichara) {
        cin>>mestoZichara>>dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa); Zichara r(mestoZichara,dnevnakartaZichara);
        pom.setZichara(r); p=pom;
    }
    else{ PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa); p=*pok;}

    --p; --p; int cena,den,mesec;cin>>den>>mesec;

    try{
        p.presmetajDnevenPrestoj(den,mesec,cena); 
        cout<<"Informacii za PlaninarskiDomot:"<<endl<<p;
        if (p<='D'){ cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n"; }
        cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena;
    }
    catch (int){ cout<<"Mesecot ili denot e greshno vnesen!"; }

    return 0;
}
