#include <iostream>
#include <cstring>
using namespace std;

class Film{
    private:
        char name[100],director[50],genre[50]; int year;
    public:
        Film(){}; Film(char n[100],char d[100],char g[50],int y){
            strcpy(name,n); strcpy(director,d); strcpy(genre,g); year=y;
        } ~Film(){};
    int getYear(){return year;} char *getGenre(){return genre;}
    char *getName(){return name;} char *getDirector(){return director;}
    void pecati_po_godina(Film *f,int n,int godina);
};

void Film::pecati_po_godina(Film *f,int n,int godina){
    for(int i=0;i<n;i++){
        if(f[i].getYear()==godina){
            cout<<"Ime: "<<f[i].getName()<<endl<<"Reziser: "<<f[i].getDirector();
            cout<<endl<<"Zanr: "<<f[i].getGenre()<<endl<<"Godina: "<<f[i].getYear()<<endl;
        }
    }
}

int main(){
 	int n; cin >> n;Film f[100];

 	for(int i = 0; i < n; i++) {
 		char ime[100], reziser[50], zanr[50]; int godina; 
        cin >> ime >> reziser >> zanr >> godina;
 		Film p(ime, reziser, zanr, godina);
        f[i]=p;
    }
 	int godina; cin >> godina;
    f[n].pecati_po_godina(f,n,godina);

 	return 0;
}