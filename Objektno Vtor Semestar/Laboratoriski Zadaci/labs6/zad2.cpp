#include <iostream>
#include <math.h>
using namespace std;

class Kvadrat {
    protected:
        double a{0};
    public:
        Kvadrat(){}
        Kvadrat(double a){ this->a = a; }
        Kvadrat(const Kvadrat &other){ this->a = other.a; }

        double perimetar() const { return 4*this->a; }
        double plostina() const { return pow(this->a,2); }
        void pecati(){ cout<<"Kvadrat so dolzina a="<<this->a<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl; }
};

class Pravoagolnik : Kvadrat { 
    private:
        double x{0}, y{0};
    public:
        Pravoagolnik():Kvadrat(){}
        Pravoagolnik(const Kvadrat &k, double x, double y) : Kvadrat(k){ this->x = x; this->y = y; }
        Pravoagolnik(const Pravoagolnik &other):Kvadrat(other){ this->x = other.x; this->y = other.y; }

        double perimetar(){
            if(x == y){ return Kvadrat::perimetar(); }
            else return 2*(x + a) + 2*(y + a);
        }
        double plostina(){
            if(x == y){ a+=x; return Kvadrat::plostina(); }
            else return (x + a) * (y + a);
        }
        void pecati(){
            if(x == y){ a+=x; Kvadrat::pecati(); }
            else{ cout<<"Pravoagolnik so strani: "<<x+a<<" i "<<y+a<<" ima plostina P="<<plostina()<<" i perimetar L="<<perimetar()<<endl; }
        }
};

int main() {
	int n; cin>>n; double a,x,y; Kvadrat * kvadrati; Pravoagolnik * pravoagolnici;
    kvadrati = new Kvadrat [n]; pravoagolnici = new Pravoagolnik [n];
    
	for (int i=0;i<n;i++){ cin>>a; kvadrati[i] = Kvadrat(a); }
	for (int i=0;i<n;i++){ cin>>x>>y; pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y); }
	
	int testCase; cin>>testCase;
    
	if (testCase==1){
		cout<<"===Testiranje na klasata Kvadrat==="<<endl;
		for (int i=0;i<n;i++) { kvadrati[i].pecati(); } }
	else {
		cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
		for (int i=0;i<n;i++) { pravoagolnici[i].pecati(); } }
}