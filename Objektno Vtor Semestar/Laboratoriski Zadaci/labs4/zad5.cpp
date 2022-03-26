#include <iostream>
#include <cstring>
using namespace std;

class Pica{
    private:
        char pizzaName[15], *ingredients{nullptr}; int price{0}, discount{0};
    public:
        Pica(){this->ingredients = nullptr;}
        Pica(char *pizzaName, int price, char *ingredients, int discount):Pica(){
            strcpy(this->pizzaName,pizzaName); this->price = price; this->discount = discount;
            this->ingredients = new char[strlen(ingredients)+1]; strcpy(this->ingredients,ingredients);
        }
        Pica(const Pica &other){
            if(this != &other){
                strcpy(this->pizzaName,other.pizzaName); this->price = other.price; this->discount = other.discount;
                this->ingredients = new char[strlen(other.ingredients)+1]; strcpy(this->ingredients,other.ingredients);  
            }
        }
        Pica &operator=(const Pica &other){
            if(this != &other){
                strcpy(this->pizzaName,other.pizzaName); this->price = other.price; this->discount = other.discount;
                this->ingredients = new char[strlen(other.ingredients)+1]; strcpy(this->ingredients,other.ingredients);  
            } return *this;
        }        
        ~Pica(){delete[] ingredients; ingredients = nullptr;} 

        void pecati(){cout<<this->pizzaName<<" - "<<this->ingredients<<", "<<this->price;}
        bool istiSe(Pica p){return (!strcmp(this->ingredients,p.ingredients));}
        int getPrice(){return this->price;} int getPopust(){return this->discount;}
};

class Picerija{
    private:
        char name[15]; Pica *arr{nullptr}; int num{0};
    public:
        Picerija(){arr = nullptr;}
        Picerija(char *name){ strcpy(this->name,name);}
        Picerija(const Picerija &other){
            if(this != &other){
                strcpy(this->name,other.name); this->num = other.num;
                delete[] arr; arr = new Pica[this->num];
                for(int i=0; i<this->num; i++){this->arr[i] = other.arr[i];}
            }
        }
        Picerija &operator=(const Picerija &other){
            if(this != &other){
                strcpy(this->name,other.name); this->num = other.num;
                delete[] arr; arr = new Pica[this->num];
                for(int i=0; i<this->num; i++){this->arr[i] = other.arr[i];}
            } return *this;            
        }
        ~Picerija(){delete[] arr; arr = nullptr;}

        void dodadi(Pica &other){
            bool isEqual = false; for(int i=0; i<this->num; i++){ if(arr[i].istiSe(other)){isEqual = true; break;}}
            if(!isEqual){
                Pica *temp = new Pica[this->num+1]; for(int i=0; i<this->num; i++){temp[i] = arr[i];}
                temp[num++] = other; delete[] arr; arr = temp;
            }
        }

        const char *getIme(){return name;} void setIme(const char *n){strcpy(this->name,n);}

        void piciNaPromocija(){
            for(int i=0; i<this->num; i++){
                if(arr[i].getPopust() != 0){
                    arr[i].pecati(); cout<<" "<<arr[i].getPrice()*(1-arr[i].getPopust()/100.0)<<endl; }
            }
        }

};

int main () {
    int n;char ime[15]; cin >> ime >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100]; cin.get(); cin.getline(imp,100);
        int cena; cin >> cena; char sostojki[100]; cin.get();
        cin.getline(sostojki,100); int popust; cin >> popust;
        Pica p(imp,cena,sostojki,popust); p1.dodadi(p);
    }

    Picerija p2 = p1; cin >> ime; p2.setIme(ime);
    char imp[100]; cin.get(); cin.getline(imp,100); int cena; cin >> cena;
    char sostojki[100]; cin.get(); cin.getline(sostojki,100); int popust; cin >> popust;
    Pica p(imp,cena,sostojki,popust); p2.dodadi(p);

    cout<<p1.getIme()<<endl<<"Pici na promocija:"<<endl; p1.piciNaPromocija();
    cout<<p2.getIme()<<endl<<"Pici na promocija:"<<endl; p2.piciNaPromocija();
	return 0;
}