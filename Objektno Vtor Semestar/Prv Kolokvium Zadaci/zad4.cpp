#include <iostream>
#include <cstring>
using namespace std;

class Patnik{
    private:
        char name[100]; int type; bool bike;
    public:
    Patnik(){}; 
    Patnik(char *n1,int t1, bool b1){ strcpy(this->name,n1); this->type=t1; this->bike=b1; }
    ~Patnik(){};

    Patnik &operator=(const Patnik &other){ strcpy(this->name, other.name); this->type = other.type; this->bike=other.bike; }
    
    friend ostream &operator<<(ostream &out,const Patnik &other){ out<<other.name<<endl<<other.type<<endl<<other.bike<<endl; return out<<endl; }

    int getType()const{return this->type;} bool getBike()const{return this->bike;} char *getName(){return this->name;}
};

class Voz{
    private:
        char destination[100]; Patnik *arr; int num=0, bikes=0,cnt1=0,cnt2=0;
    public:
        Voz(){arr = nullptr;}
        Voz(char *d1, int b1){ strcpy(this->destination,d1); this->bikes=b1; arr = new Patnik[100];} 
        ~Voz(){delete[] arr;};

        Voz &operator+=(Patnik &other){this->arr[this->num++]=other;}

        friend ostream &operator<<(ostream &out, Voz &other){
            out << other.destination<<endl;
            
            if(other.bikes == 0){ for(int i=0;i<other.num;i++) { if(!other.arr[i].getBike()){ out<<other.arr[i]; } } }

            else{ for(int i=0;i<other.num;i++) {
                    if(other.arr[i].getBike()){ 
                        if(other.arr[i].getType()==1){ other.bikes>0?other.bikes--:other.cnt1++; } } }

                for(int i=0;i<other.num;i++) {
                    if(other.arr[i].getBike()){ 
                        if(other.arr[i].getType()==2){ other.bikes>0?other.bikes--:other.cnt2++; } } }   

                for(int i=0;i<other.num;i++){out<<other.arr[i];}
            } return out;
        }
        
    void patniciNemaMesto(){ cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<< cnt1 << endl <<"Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<< cnt2 << endl; }
};

int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n,klasa,maxv; bool velosiped;
	cin >> destinacija >> maxv >> n;
	Voz v(destinacija, maxv); //cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
		/*cout<<p<<endl;*/ v += p;
	}
	cout << v; v.patniciNemaMesto();
	return 0;
}
