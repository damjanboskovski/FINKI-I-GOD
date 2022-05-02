#include <iostream>
#include <math.h>
using namespace std;

class Shape{
    protected:
        int side{0};
    public:
        Shape(int s){ this->side = s; }
        virtual double plostina() = 0; virtual void pecati() = 0; virtual int getType() = 0;
};

class Square : public Shape{
    public:
        Square(int side):Shape(side){}
        double plostina(){ return pow(side,2); } int getType(){ return 1; }
        void pecati(){ cout<<"Kvadrat so plostina = "<<plostina()<<endl; }
};

class Circle : public Shape{
    public:
        Circle(int side):Shape(side){}
        double plostina(){ return 3.14 * pow(side,2); } int getType(){ return 2; }
        void pecati(){ cout<<"Krug so plostina = "<<plostina()<<endl; }
};

class Triangle : public Shape{
    public:
        Triangle(int side):Shape(side){}
        double plostina(){ return sqrt(3)/4 * pow(side,2); } int getType(){ return 3; }
        void pecati(){ cout<<"Triagolnik so plostina = "<<plostina()<<endl;}
};

void checkNumTypes(Shape **arr, int n){
    int triangleCnt=0, circleCnt=0, squareCnt=0;
    for(int i=0; i<n; i++){
        if(arr[i]->getType() == 1){ squareCnt++; }
        else if(arr[i]->getType() == 2){ circleCnt++; }
        else if( arr[i]->getType() == 3){ triangleCnt++; }
    }
    cout<<"Broj na kvadrati vo nizata = "<<squareCnt<<endl;
    cout<<"Broj na krugovi vo nizata = "<<circleCnt<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<triangleCnt<<endl;
}

int main(){
	int n; cin >> n; int classType, side; Shape **shape = new Shape *[n];

	for(int i = 0; i < n; ++i){ 
        cin >> classType >> side;
        if(classType == 1){ shape[i] = new Square(side); }
        else if(classType == 2){ shape[i] = new Circle(side); }
        else if(classType == 3){ shape[i] = new Triangle(side); }
    }
    
	for(int i = 0; i < n; ++i){ shape[i]->pecati(); }
	checkNumTypes(shape, n); return 0;
}