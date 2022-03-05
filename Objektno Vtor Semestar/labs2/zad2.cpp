#include <iostream>
using namespace std;

class Krug{
    private:
        float rad; const float pi=3.14;
    public:
        Krug(){}; Krug(float r){rad=r;} ~Krug(){};
        
        float plostina(){return (rad*rad)*pi;}float perimetar(){return (2*rad)*pi;}
        float ednakvi(){
            if(plostina()==perimetar()){return 1;}
            else return 0;}
};

int main(){
    float r;cin >> r; Krug k(r);
	cout << k.perimetar() << endl << k.plostina() << endl << k.ednakvi() <<endl;
    Krug k1;
	return 0;
}