#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class NoCourseException{
    private:
        int index{0};
    public:
        NoCourseException(int i){ this->index = i; } 
        void message(){ cout<<"Demonstratorot so indeks "<<index<<" ne drzi laboratoriski vezbi"<<endl; }
};

class Kurs{
    private:
        char ime[20]; int krediti;
    public:
        Kurs (char *ime,int krediti){ strcpy(this->ime,ime); this->krediti=krediti; }
        Kurs (){ strcpy(this->ime,""); krediti=0; }

        bool operator==(const char *ime) const{ return strcmp(this->ime,ime)==0; }
        char const * getIme()const{ return ime; }
        void pecati ()const{ cout<<ime<<" "<<krediti<<"ECTS"; }
};

class Student{
    private:
        int *ocenki, brojOcenki;
    protected:
        int indeks;
    public:
        Student(int indeks,int *ocenki, int brojOcenki){
            this->indeks=indeks; this->brojOcenki=brojOcenki;
    	    this->ocenki=new int[brojOcenki]; for (int i=0;i<brojOcenki;i++){ this->ocenki[i]=ocenki[i]; }
        }
        Student(const Student &k){
        	this->indeks=k.indeks; this->brojOcenki=k.brojOcenki;
        	this->ocenki=new int[k.brojOcenki]; for (int i=0;i<k.brojOcenki;i++) { this->ocenki[i]=k.ocenki[i]; }
        }
        Student operator=(const Student &k){
    	    if (&k==this){ return *this; }
            this->indeks=k.indeks; this->brojOcenki=k.brojOcenki;
    	    delete [] ocenki; this->ocenki=new int[k.brojOcenki]; for (int i=0;i<k.brojOcenki;i++) this->ocenki[i]=k.ocenki[i];
    	    return *this;
        }
        ~Student(){delete [] ocenki;}

        virtual int getBodovi(){  double sum=0; for(int i=0; i<brojOcenki; i++){ ocenki[i]>5?sum++:0; } return (sum/brojOcenki) * 100; }
        virtual void pecati(){ cout<<indeks; }
};

class Predavach{
    private:
	    Kurs kursevi[10]; int brojKursevi;
    protected:
	    char *imeIPrezime;
    public:
        Predavach(char *imeIPrezime,Kurs *kursevi,int brojKursevi){
    	    this->brojKursevi=brojKursevi; for (int i=0;i<brojKursevi;i++) this->kursevi[i]=kursevi[i];
    	    this->imeIPrezime=new char[strlen(imeIPrezime)+1]; strcpy(this->imeIPrezime,imeIPrezime);
        }
        Predavach(const Predavach &p){
            this->brojKursevi=p.brojKursevi; for (int i=0;i<p.brojKursevi;i++) this->kursevi[i]=p.kursevi[i];
    	    this->imeIPrezime=new char[strlen(p.imeIPrezime)+1]; strcpy(this->imeIPrezime,p.imeIPrezime);
        }
        Predavach operator=(const Predavach &p){
            if (this==&p){ return *this; }
            this->brojKursevi=p.brojKursevi; for(int i=0;i<p.brojKursevi;i++) this->kursevi[i]=p.kursevi[i];
            this->imeIPrezime=new char[strlen(p.imeIPrezime)+1]; delete [] imeIPrezime; strcpy(this->imeIPrezime,p.imeIPrezime);
            return *this;
        }
        ~Predavach(){delete [] imeIPrezime;}

   	    int getBrojKursevi()const {return brojKursevi;}
        char * const getImeIPrezime()const {return imeIPrezime;}
        Kurs operator[](int i) const { return i<brojKursevi && i>=0?kursevi[i]:Kurs(); }
        void pecati() const  { cout<<imeIPrezime<<" ("; for (int i=0;i<brojKursevi;i++){ kursevi[i].pecati(); if (i<brojKursevi-1) cout<<", ";  else cout<<")"; } }
};

class Demonstrator : public Student, public Predavach{
    private:
        int classNum{0};
    public:
        Demonstrator(int i, int *o, int bo, char *ip, Kurs *k, int bk, int cn):Student(i,o,bo),Predavach(ip,k,bk){ this->classNum = cn; }
        int getBodovi(){ 
            if(getBrojKursevi() == 0){ throw NoCourseException(indeks); }
            return Student::getBodovi() + (20 * classNum) / getBrojKursevi();
        }
        void pecati(){ Student::pecati(); cout<<": "; Predavach::pecati(); }
};

Student &vratiNajdobroRangiran(Student **studenti, int num){
    int max=0, pos=0;
    for(int i=0; i<num; i++){
        try{
            max < studenti[i]->getBodovi()?max = studenti[i]->getBodovi(), pos = i:0;
        }
        catch(NoCourseException &nce){ nce.message(); }
    } return *studenti[pos];
}

void pecatiDemonstratoriKurs(char *kurs, Student **studenti, int num){
    for(int i=0; i<num; i++){
        if(dynamic_cast<Demonstrator*>(studenti[i])){
            for(int j=0; j<dynamic_cast<Demonstrator*>(studenti[i])->getBrojKursevi(); j++){
                if(!strcmp(kurs,dynamic_cast<Demonstrator*>(studenti[i])->operator[](j).getIme())){ studenti[i]->pecati(); cout<<endl; break; } } } }
}

int main(){
    Kurs kursevi[10]; int indeks,brojKursevi, ocenki[20],ocenka,brojOcenki,tip,brojCasovi,krediti; char ime[20],imeIPrezime[50]; cin>>tip;

    if (tip==1){
        cout<<"-----TEST Demonstrator-----"<<endl; cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){ cin>>ocenka; ocenki[i]=ocenka; }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){ cin>>ime>>krediti; kursevi[i]=Kurs(ime,krediti); }
        cin>>brojCasovi;
        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi); 
        cout<<"Objekt od klasata Demonstrator e kreiran";
    } 
    else if (tip==2){
        cout<<"-----TEST pecati-----"<<endl; cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){ cin>>ocenka; ocenki[i]=ocenka; }
        Student s(indeks,ocenki,brojOcenki); s.pecati();
    } 
    else if (tip==3){
        cout<<"-----TEST getVkupnaOcenka-----"<<endl; cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){ cin>>ocenka; ocenki[i]=ocenka; }
        Student s(indeks,ocenki,brojOcenki); cout<<"Broj na bodovi: "<<s.getBodovi()<<endl;
    } 
    else if (tip==4){
        cout<<"-----TEST getVkupnaOcenka-----"<<endl; cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){ cin>>ocenka; ocenki[i]=ocenka; }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){ cin>>ime>>krediti; kursevi[i]=Kurs(ime,krediti); }
        cin>>brojCasovi;
        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi); 
        cout<<"Broj na bodovi: "<<d.getBodovi()<<endl;
    } 
    else if (tip==5) {
        cout<<"-----TEST pecati -----"<<endl; cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){ cin>>ocenka; ocenki[i]=ocenka; }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){ cin>>ime>>krediti; kursevi[i]=Kurs(ime,krediti); } 
        cin>>brojCasovi;
        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi); d.pecati();
    } 
    else if (tip==6) {
        cout<<"-----TEST Student i Demonstrator-----"<<endl; cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){ cin>>ocenka; ocenki[i]=ocenka; }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){ cin>>ime>>krediti; kursevi[i]=Kurs(ime,krediti); }
        cin>>brojCasovi;
        Student *s=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi); s->pecati();
        cout<<"\nBroj na bodovi: "<<s->getBodovi()<<endl; delete s;
    } 
    else if (tip==7){
        cout<<"-----TEST vratiNajdobroRangiran-----"<<endl; int k, opt; cin>>k;
        Student **studenti=new Student*[k];
        for (int j=0;j<k;j++){
            cin>>opt>>indeks>>brojOcenki;
            for (int i=0;i<brojOcenki;i++) { cin>>ocenka; ocenki[i]=ocenka; }
            if (opt==1){ studenti[j]=new Student(indeks,ocenki,brojOcenki); }
            else{ 
                cin>>imeIPrezime>>brojKursevi;
        	    for (int i=0;i<brojKursevi;i++){ 
                    cin>>ime>>krediti; kursevi[i]=Kurs(ime,krediti); 
                } 
                cin>>brojCasovi; studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
            }
        }
        Student& najdobar=vratiNajdobroRangiran(studenti,k);
        cout<<"Maksimalniot broj na bodovi e:"<<najdobar.getBodovi()<<"\nNajdobro rangiran:"; najdobar.pecati();
        for (int j=0;j<k;j++){ delete studenti[j]; } delete [] studenti;
    } 
    else if (tip==8) {
        cout<<"-----TEST pecatiDemonstratoriKurs-----"<<endl; int k, opt; cin>>k;
        Student **studenti=new Student*[k];
        for (int j=0;j<k;j++){
            cin>>opt>>indeks>>brojOcenki;
            for (int i=0;i<brojOcenki;i++){ cin>>ocenka; ocenki[i]=ocenka; }
            if (opt==1){ studenti[j]=new Student(indeks,ocenki,brojOcenki); }
            else{
                cin>>imeIPrezime>>brojKursevi;
                for (int i=0;i<brojKursevi;i++){ cin>>ime>>krediti; kursevi[i]=Kurs(ime,krediti); }     
                cin>>brojCasovi; studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
            }
        }
        char kurs[20]; cin>>kurs; cout<<"Demonstratori na "<<kurs<<" se:"<<endl; pecatiDemonstratoriKurs (kurs,studenti,k);
        for (int j=0;j<k;j++) delete studenti[j]; { delete [] studenti; }
    }
    return 0;
}