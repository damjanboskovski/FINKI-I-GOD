#include <iostream>
#include <cstring>
using namespace std;

class Pica{
    private:
        char name[15], *ingredients{nullptr}; int price{0}, discount{0};
    public:
        Pica(){ this->ingredients = nullptr; }
        Pica(char *n, int p, char *i, int d){
            strcpy(this->name,n); this->price = p; this->discount = d;
            this->ingredients = new char[strlen(i)+1]; strcpy(this->ingredients,i);
        }
        ~Pica(){}

        void pecati(){ cout<<this->name<<" - "<<this->ingredients<<", "<<this->price; }
        bool istiSe(Pica p){ return (!strcmp(ingredients,p.ingredients));}
        int getDiscount(){ return this->discount; } int getPrice(){ return this->price; }
};

class Picerija{
    private:
        char name[15]; Pica *arr{nullptr}; int num{0};
    public:
        Picerija(){ arr = nullptr; }
        Picerija(char *n){
            strcpy(this->name,n); arr = new Pica[this->num];
        }
        Picerija(const Picerija &other){
            if(this != &other){
                strcpy(this->name,other.name); this->num = other.num;
                delete[] arr; arr = new Pica[other.num]; for(int i=0; i<num; i++){ arr[i] = other.arr[i];}
            }
        }
        ~Picerija(){ delete[] arr; arr = nullptr; }
        Picerija &operator+=(const Pica &p){
            bool isEqual = false; for(int i=0; i<num; i++){ if(arr[i].istiSe(p)){ isEqual = true; break; } }
            if(!isEqual){ Pica *temp = new Pica[num+1]; for(int i=0; i<num; i++){ temp[i] = arr[i]; }
            temp[num++] = p; delete[] arr; arr = temp; } return *this;
        }
        void piciNaPromocija(){
            for(int i=0; i<num; i++){
                if(arr[i].getDiscount() != 0){ arr[i].pecati();
                cout<<" "<<arr[i].getPrice()*(1 - arr[i].getDiscount()/100.00)<<endl; } }
        }
        void setIme(char *n){ strcpy(name,n); } char *getIme(){ return this->name; }
};

int main() {

	int n; char ime[15]; cin >> ime >> n; Picerija p1(ime);
	for (int i = 0; i < n; i++){
		char imp[100], sostojki[100];; int cena, popust;
		cin.get(); cin.getline(imp, 100); cin >> cena;
		cin.get(); cin.getline(sostojki, 100); cin >> popust;
		Pica p(imp, cena, sostojki, popust); p1+=p;
	}
	
	Picerija p2 = p1; char imp[100], sostojki[100]; int cena, popust;
	cin >> ime; p2.setIme(ime); cin.get(); cin.getline(imp, 100);
	cin >> cena; cin.get(); cin.getline(sostojki, 100); cin >> popust;
	Pica p(imp, cena, sostojki, popust); p2+=p;
	cout << p1.getIme() << endl << "Pici na promocija:" << endl; p1.piciNaPromocija();
	cout << p2.getIme() << endl << "Pici na promocija:" << endl; p2.piciNaPromocija();

	return 0;
}
