#include <iostream>
#include <cstring>
using namespace std;

class Patnik{
    private:
        char name[100]; int trainClass; bool bike;
    public:
        Patnik(){};
        Patnik(char *n, int c, bool b){ strcpy(this->name,n); this->trainClass = c; this->bike = b; }
        friend ostream &operator<<(ostream &out, const Patnik &other){ out<<other.name<<endl<<other.trainClass<<endl<<other.bike<<endl; return out; }
        Patnik &operator=(const Patnik &other){ if(this != &other){ strcpy(this->name,other.name); this->trainClass = other.trainClass; this->bike = other.bike; }return *this; }
        ~Patnik(){};

        bool getBike()const{ return this->bike; } int getType() const{ return this->trainClass; }
};
class Voz{
    private:
        char destination[100]; Patnik *arr{nullptr}; int num=0, allowedBikes=0, cnt1=0,cnt2=0;
    public:
        Voz(){ this->arr = nullptr; }
        Voz(char *d, int a){ strcpy(this->destination,d); this->allowedBikes = a; }
        Voz &operator+=(const Patnik &other){
            Patnik *temp = new Patnik[this->num+1];
            for(int i=0; i<this->num; i++){ temp[i] = this->arr[i]; }
            temp[this->num++] = other; delete[] this->arr; this->arr = temp;
        }
        ~Voz(){delete[] this->arr; arr = nullptr;}

        friend ostream &operator<<(ostream &out, Voz &other){
            out<<other.destination<<endl;
            if(other.allowedBikes == 0){ for(int i=0; i<other.num; i++){ if(!other.arr[i].getBike()){ out<<other.arr[i]; } } }
            else{
                for(int i=0; i<other.num; i++){ if(other.arr[i].getBike() && other.arr[i].getType()==1){ other.allowedBikes>0?other.allowedBikes--:other.cnt1++; } }
                for(int i=0; i<other.num; i++){ if(other.arr[i].getBike() && other.arr[i].getType()==2){ other.allowedBikes>0?other.allowedBikes--:other.cnt2++; } }
                for(int i=0; i <other.num; i++){ out<<other.arr[i]; }
            } return out;
        }

        void patniciNemaMesto(){ cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<cnt1<<endl<<"Brojot na patnici od 2-ra klasa koi ostanele bez mesto e: "<<cnt2<<endl; }
};

int main()
{
	Patnik p; char ime[100], destinacija[100]; int n, klasa, maxv; bool velosiped;
	cin >> destinacija >> maxv >> n; Voz v(destinacija, maxv);
	
	for (int i = 0; i < n; i++){ cin >> ime >> klasa >> velosiped; Patnik p(ime, klasa, velosiped); v += p; }
	
	cout << v; v.patniciNemaMesto();
	return 0;
}
