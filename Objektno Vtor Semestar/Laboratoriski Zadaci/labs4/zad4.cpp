#include <iostream>
#include <string.h>
using namespace std;

enum zanr{ akcija, komedija, drama};

class Film{
    private:
        char *movieName{nullptr}; int movieSize{0}; zanr type{(zanr)0};
    public:
        Film(){movieName = nullptr;}
        Film( char *movieName, int movieSize, zanr type):Film(){
            this->movieName = new char[strlen(movieName)+1]; strcpy(this->movieName,movieName);
            this->movieSize = movieSize; this->type = type;
        }
        Film(const Film &other){
            if(this != &other){
                this->movieName = new char[strlen(other.movieName)+1]; strcpy(this->movieName,other.movieName);
                this->movieSize = other.movieSize; this->type = other.type;
            }
        }
        Film &operator=(const Film &other){
            if(this != &other){
                this->movieName = new char[strlen(other.movieName)+1]; strcpy(this->movieName,other.movieName);
                this->movieSize = other.movieSize; this->type = other.type;
            } return *this;
        }
        ~Film(){delete[] this->movieName; movieName = nullptr;}
        
        zanr getType(){return this->type;} int getSize(){return this->movieSize;}
        void pecati(){cout<<this->movieSize<<"MB-\""<<this->movieName<<"\""<<endl;}
};

class DVD{
    private:    
        Film arr[5]; int movieNum{0}, sizeSum{0};
    public:
        DVD(){this->movieNum = 0; this->sizeSum = 0;}
        DVD(int sizeSum){this->sizeSum = sizeSum;}
        DVD (const DVD &other){
            if(this != &other){
                this->movieNum = other.movieNum; this->sizeSum = other.sizeSum;
                for(int i=0;i<this->movieNum;i++){arr[i] = other.arr[i];}
            }
        }
        DVD &operator=(const DVD &other){
            if(this != &other){
                this->movieNum = other.movieNum; this->sizeSum = other.sizeSum;
                for(int i=0;i<this->movieNum;i++){arr[i] = other.arr[i];}
            } return *this;            
        }
        ~DVD(){};

        Film getFilm(int i){ return this->arr[i]; } int getBroj(){ return this->movieNum; }
        void dodadiFilm(Film other){
            if(other.getSize() > sizeSum || movieNum == 5){return;}
            arr[movieNum++] = other; sizeSum -= other.getSize();
        }

        void pecatiFilmoviDrugZanr(zanr typeCmp){
            for(int i=0; i<this->movieNum; i++){if(this->arr[i].getType()!=typeCmp){this->arr[i].pecati();}}
        }

        double procentNaMemorijaOdZanr(zanr other){
            double total=0,sum=0;
            for(int i=0; i<this->movieNum; i++){
                total+=arr[i].getSize(); sum+=this->arr[i].getType() == other?arr[i].getSize():0;
            }
            return sum/total * 100;
        }
};

int main() {
    int testCase, n, memorija, kojzanr; char ime[50];
    cin >> testCase;

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime >> memorija >> kojzanr;
        Film f(ime, memorija, (zanr) kojzanr); f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50); cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime >> memorija >> kojzanr;
            Film f(ime, memorija, (zanr) kojzanr); omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++) {(omileno.getFilm(i)).pecati();}
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50); cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime >> memorija >> kojzanr;
            Film f(ime, memorija, (zanr) kojzanr); omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++) {(omileno.getFilm(i)).pecati();}
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50); cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime >> memorija >> kojzanr;
            Film f(ime, memorija, (zanr) kojzanr); omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } 
    else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50); cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime >> memorija >> kojzanr;
            Film f(ime, memorija, (zanr) kojzanr); omileno.dodadiFilm(f);
        }
        cin >> kojzanr; omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);
    } 
    else if (testCase == 6){
		cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
		DVD omileno(40); cin >> n;
		for (int i = 0; i < n; i++) {
            cin >> ime >> memorija >> kojzanr;
            Film f(ime, memorija, (zanr) kojzanr); omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentNaMemorijaOdZanr((zanr) kojzanr)<<"%\n";
		
	}

    return 0;
}