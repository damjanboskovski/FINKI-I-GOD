#include <iostream>
#include <cstring>
using namespace std;

enum Size{ small, large, family };

class Pizza{
    protected:
        char name[20], ingredients[100]; float inPrice{0};
    public:
        Pizza(){}
        Pizza(const char *n, const char *i, float ip){ strcpy(this->name,n); strcpy(this->ingredients,i); this->ingredients[49]='\0'; this->inPrice = ip; }
        Pizza(const Pizza &other){
            if(this != &other){ 
                strcpy(this->ingredients,other.ingredients); strcpy(this->name,other.name); this->inPrice = other.inPrice;
            }
        }
        Pizza &operator=(const Pizza &other){
            if(this != &other){ 
                strcpy(this->name,other.name); strcpy(this->ingredients,other.ingredients); this->inPrice = other.inPrice;
            } return *this;
        }
        ~Pizza(){}
        virtual float price() = 0; 

        friend ostream &operator<<(ostream &out, Pizza &other);
        bool operator<(Pizza &other);
};

class FlatPizza : public Pizza{
    private:
        Size pizzaSize;
    public:
        FlatPizza(){}
        FlatPizza(const char *n, const char *i, float ip, Size pS = small):Pizza(n,i,ip){ this->pizzaSize = pS; }
        FlatPizza(FlatPizza &other):Pizza(other.name,other.ingredients,other.inPrice){ if(this != &other){ this->pizzaSize = other.pizzaSize; } }
        FlatPizza &operator=(FlatPizza &other){
            if(this != &other){
                strcpy(this->name,other.name); strcpy(this->ingredients,other.ingredients); this->inPrice = other.inPrice; this->pizzaSize = other.pizzaSize; 
            } return *this;
        }
        ~FlatPizza(){}

        float price(){
            if(pizzaSize == small){ return inPrice * 1.1; }
            else if(pizzaSize == large){ return inPrice * 1.5; }
            else return inPrice * 1.3;
        }

        Size getSize()const{ return pizzaSize; }
};

class FoldedPizza : public Pizza{
    private:
        bool whiteFlour{true};
    public:
        FoldedPizza(){}
        FoldedPizza(const char *n, const char *i, float ip):Pizza(n,i,ip){ this->whiteFlour = true; }
        ~FoldedPizza(){}

        void setWhiteFlour(bool wf){ this->whiteFlour = wf; } bool isWhiteFlour()const{ return whiteFlour; }
        float price(){ return (whiteFlour)?inPrice * 1.1:inPrice * 1.3; }
};

void expensivePizza(Pizza **p, int pizzas);

ostream &operator<<(ostream &out, Pizza &other){
    out<<other.name<<": "<<other.ingredients<<", ";
    if(dynamic_cast<FlatPizza *>(&other)){
        if(dynamic_cast<FlatPizza *>(&other)->getSize() == small){ cout<<"small"; }
        else if (dynamic_cast<FlatPizza *>(&other)->getSize() == large){ cout<<"large"; }
        else { cout<<"family"; }
    } 
    else if(dynamic_cast<FoldedPizza *>(&other)){
        if(dynamic_cast<FoldedPizza *>(&other)->isWhiteFlour()){ out<<"wf"; }
        else out<<"nwf";
    }
    out<<" - "<<other.price()<<endl; return out;
}

bool Pizza::operator<(Pizza &other){ return price() < other.price(); }

void expensivePizza(Pizza **p, int pizzas){
    float max = p[0]->price(); int pos=0;
    for(int i=0; i<pizzas; i++){ if(max < p[i]->price()){ max = p[i]->price(); pos = i; } }
    cout<<*p[pos];
}

int main()
{
    int test_case; cin >> test_case; char name[20], ingredients[100]; float inPrice; Size size; bool whiteFlour;

    if (test_case == 1){
        cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice); cout << fp;
    }
    else if (test_case == 2){
        cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice; int s; cin >> s;
        FlatPizza fp(name, ingredients, inPrice, (Size) s); cout << fp;
    }
    else if (test_case == 3){
        cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice); cout << fp;
    }
    else if (test_case == 4){
        cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice); fp.setWhiteFlour(false); cout << fp;
    }
    else if (test_case == 5){
        int s; cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice >> s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size) s); cout << *fp1;

        cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice >> s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size) s); cout << *fp2;

        cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice); cout << *fp3;

        cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice); fp4->setWhiteFlour(false); cout << *fp4;

        cout << "Lower price: " << endl;
        if (*fp1 < *fp2){ cout << fp1->price() << endl; }
        else cout << fp2->price() << endl;

        if (*fp1 < *fp3){ cout << fp1->price() << endl; }
        else cout << fp3->price() << endl;

        if (*fp4 < *fp2){ cout << fp4->price() << endl; }
        else cout << fp2->price() << endl;

        if (*fp3 < *fp4){ cout << fp3->price() << endl; }
        else cout << fp4->price() << endl;
    }
    else if (test_case == 6){
        int num_p, pizza_type; cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j){
            cin >> pizza_type;
            if (pizza_type == 1){
                cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice; int s; cin >> s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size) s); cout << (*fp); pi[j] = fp;
            }
            if (pizza_type == 2){
                cin.get(); cin.getline(name, 20); cin.getline(ingredients, 100); cin >> inPrice;
                FoldedPizza *fp = new FoldedPizza(name, ingredients, inPrice);
                if (j % 2){ (*fp).setWhiteFlour(false); } cout << (*fp); pi[j] = fp;
            }
        }
        cout << endl << "The most expensive pizza:\n"; expensivePizza(pi, num_p);
    } return 0;
}