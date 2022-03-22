#include <iostream>
#include <cstring>
using namespace std;

class Masa{
    private:
        int length, width;
    public:
        Masa(){length = 0; width = 0;}
        Masa(int l, int w){this->length = l; this->width = w;}
        ~Masa(){};

        void pecati(){cout<<"Masa: "<<length<<" "<<width<<endl;}
};

class Soba{
    private:
        Masa m; int roomLength = 0,roomWidth = 0;
    public:
        Soba(){};
        Soba(int r, int r2, Masa m1){this->m = m1; this->roomLength = r; this->roomWidth = r2;}
        ~Soba(){};

        void pecati(){ cout<<"Soba: "<<roomLength<<" "<<roomWidth<<" "; m.pecati();}
};

class Kukja{
    private:
        Soba s; char address[50];
    public:
        Kukja(){};
        Kukja(Soba s1, char *a){this->s = s1; strcpy(this->address,a);}
        ~Kukja(){};

        void pecati(){cout<<"Adresa: "<<address<<" "; s.pecati();}
};

int main(){
    int n; cin >> n;

    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin >> masaSirina >>masaDolzina;
    	Masa m(masaSirina,masaDolzina);

    	int sobaSirina,sobaDolzina;
        cin >> sobaSirina >> sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);

    	char adresa[30]; cin >> adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}
    
    return 0;
}