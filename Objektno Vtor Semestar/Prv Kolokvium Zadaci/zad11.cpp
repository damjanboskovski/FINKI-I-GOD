#include <iostream>
#include <cstring>
using namespace std;

class Ucesnik{
    private:
        char *name; bool gender; int age;
    public:
        Ucesnik(){ name = nullptr; };
        Ucesnik(char *n, bool g, int a){
            name = new char[100];
            strcpy(name, n); gender = g; age = a;
        }
        ~Ucesnik(){};

        Ucesnik &operator>(const Ucesnik &other){
            if(this->age > other.age){this->age;}
            else {other.age;}
            return *this;
        }

        friend ostream &operator<<(ostream &output, Ucesnik &other){
            string genderConv;
            if(other.gender == 0){genderConv = "zhenski";}
            else {genderConv = "mashki";}
            output<<other.name<<endl<<genderConv<<endl<<other.age<<endl;
        }

        int getAge(){return age;}
};

class Maraton{
    private:
        char location[100]; Ucesnik *arr; int num = 0;
    public:
        Maraton(){ arr = nullptr; };
        Maraton(char l[100]){strcpy(location,l); arr = new Ucesnik[1024];}
        ~Maraton(){};

        Maraton &operator+=(Ucesnik &add){ arr[num] = add; num++; }

        float prosecnoVozrast(){
            float avg = 0; 
            for(int i=0;i<num;i++){ avg+=arr[i].getAge(); } 
            return avg/num; 
        }
        void pecatiPomladi(Ucesnik &p){
            for(int i=0;i<num;i++){
                if(arr[i].getAge()<p.getAge()){ cout<<arr[i]; }
            }
        }
};

int main() {
    char ime[100]; bool maski;
    int vozrast, n; cin >> n;
    char lokacija[100]; cin >> lokacija;

    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
    	u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }

	m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) { delete u[i]; }
    delete [] u;

	return 0;
}