#include <iostream>
#include <cstring>
using namespace std;

class Ucesnik{
    private:
        char *name{nullptr}; bool gender; int age{0};
    public:
        Ucesnik(){ name = nullptr; }
        Ucesnik(char *n, bool g, int a){
            delete[] this->name; this->name = new char[strlen(n)+1]; strcpy(this->name,n);
            this->gender = g; this->age = a;
        }
        Ucesnik(const Ucesnik &other){ if(this != &other){
            delete[] this->name; this->name = new char[strlen(other.name)+1]; strcpy(this->name,other.name);
            this->gender = other.gender; this->age = other.age; }
        }
        Ucesnik &operator=(const Ucesnik &other){ if(this != &other){
            delete[] this->name; this->name = new char[strlen(other.name)+1]; strcpy(this->name,other.name);
            this->gender = other.gender; this->age = other.age; } return *this;
        }
        ~Ucesnik(){ delete[] this->name; this->name = nullptr; }

        Ucesnik &operator>(const Ucesnik &other){ this->age>other.age?this->age:other.age; return *this; }
        friend ostream &operator<<(ostream &out, Ucesnik &other){
            string genderConv; other.gender==0?genderConv="zhenski":genderConv="mashki";
            out<<other.name<<endl<<genderConv<<endl<<other.age<<endl;
        }
        int getAge(){return this->age;}
};

class Maraton{
    private:
        char location[100]; Ucesnik *arr{nullptr}; int num{0};
    public:
        Maraton(){ this->arr = nullptr; }
        Maraton(char *l){ strcpy(this->location,l); this->arr = new Ucesnik[this->num]; }
        ~Maraton(){ delete[] this->arr; arr = nullptr; }

        Maraton &operator+=(Ucesnik &other){
            Ucesnik *temp = new Ucesnik[num+1];
            for(int i=0; i<this->num; i++){ temp[i] = arr[i]; }
            temp[num++] = other; delete[] this->arr; arr = temp;
        }
        float prosecnoVozrast(){ float avg=0; for(int i=0; i<num; i++){ avg+=arr[i].getAge(); } return avg/num; }
        void pecatiPomladi(Ucesnik &u){ for(int i=0; i<num; i++){ if(arr[i].getAge()<u.getAge()){ cout<<arr[i]; } } }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
    	u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
	m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
	return 0;
}
