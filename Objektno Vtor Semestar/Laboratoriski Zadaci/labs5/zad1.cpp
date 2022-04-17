#include <iostream>
#include <cstring>
using namespace std;

class Automobile{
    private:
        char *carName{nullptr}; int *registration{nullptr}, maxSpeed{0};
    public:
        Automobile(){ this->carName = nullptr; this->registration = nullptr; }
        Automobile( char *m, int *r, int s) {
            this->carName = new char[strlen(m)+1]; strcpy(this->carName,m);
            this->registration = new int[5]; for(int i=0; i<5; i++){ this->registration[i] = r[i]; }
            this->maxSpeed = s;
        }
        Automobile(const Automobile &other){ if(this != &other) {
                delete[] this->carName; this->carName = new char[strlen(other.carName)+1]; strcpy(this->carName,other.carName);
                delete[] this->registration; this->registration = new int [5]; for(int i=0; i<5; i++){ this->registration[i] = other.registration[i];}
                this->maxSpeed = other.maxSpeed; }
        }
        Automobile &operator=(const Automobile &other){ if(this != &other) {
                delete[] this->carName; this->carName = new char[strlen(other.carName)+1]; strcpy(this->carName,other.carName);
                delete[] this->registration; this->registration = new int [5]; for(int i=0; i<5; i++){ this->registration[i] = other.registration[i];}
                this->maxSpeed = other.maxSpeed; } return *this;
        }
        ~Automobile(){ delete[] this->carName; this->carName = nullptr; delete[] this->registration; this->registration = nullptr; }
        
        bool operator==(const Automobile &other){
            for(int i=0; i<5; i++){ if(this->registration[i] != other.registration[i]) { return false; } }
            return true;
        }

        friend ostream &operator<<(ostream &out, const Automobile &other){
            out<<"Marka\t"<<other.carName<<"\tRegistracija[ ";
            for(int i=0; i<5; i++){ out<<other.registration[i]<<" "; }
            out<<"]"<<endl; return out;
        }

        int getMaxSpeed(){ return this->maxSpeed; }
};

class RentACar{
    private:
        char agencyName[100]; Automobile *arr{nullptr}; int num{0};
    public:
        RentACar(){ this->arr = nullptr; }
        RentACar(char *n){ strcpy(this->agencyName,n); arr = new Automobile[num]; this->num = 0; }
        ~RentACar(){ delete[] this->arr; this->arr = nullptr; }

        RentACar &operator+=(const Automobile &other){
            Automobile *temp = new Automobile[this->num+1];
            for(int i=0; i<this->num; i++){ temp[i] = this->arr[i]; }
            temp[num++] = other; delete[] this->arr; this->arr = temp;
        }
        RentACar &operator-=(const Automobile &other){
            for(int i=0; i<num; i++){
                if(this->arr[i] == other){ --this->num;
                for(int j=i; j<this->num; j++){ this->arr[j] = this->arr[j+1]; } break; } }
        }

        void pecatiNadBrzina(int n){
            cout<<"FINKI-Car"<<endl;
            for(int i=0; i<num; i++){ if( arr[i].getMaxSpeed() > n ){ cout<<arr[i]; }}
        }
};

int main(){
    RentACar agencija("FINKI-Car"); int n; cin>>n;
    
    for (int i=0;i<n;i++) {
    	char marka[100]; int regisracija[5], maximumBrzina; cin>>marka;
    
       	for (int i=0;i<5;i++){ cin>>regisracija[i]; }
    	cin>>maximumBrzina; Automobile nov=Automobile(marka,regisracija,maximumBrzina); agencija+=nov;      
    }

    char marka[100]; int regisracija[5], maximumBrzina; cin >> marka;
    for (int i=0;i<5;i++){ cin>>regisracija[i]; } cin >> maximumBrzina; 
    Automobile greshka=Automobile(marka,regisracija,maximumBrzina); 
    agencija-=greshka; agencija.pecatiNadBrzina(150); return 0;
}