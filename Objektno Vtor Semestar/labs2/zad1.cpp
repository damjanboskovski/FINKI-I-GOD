#include <iostream>
using namespace std;

class Agol{
    private:
        int deg,min,sec;
    public:
    int getSec(){return sec;}
    void set_stepeni(int d){deg=d;} void set_minuti(int m){min=m;} void set_sekundi(int d){sec=d;}
    int to_sekundi(){return (3600*deg)+(min*60)+sec;}
};

int proveri(int deg, int min, int sec){
    if(deg>360 || min>=60 || min<0 || sec>=60 || sec<0){return 0;}
    else return 1;
}
bool changeOfSeconds(Agol n,int sec){
    return n.getSec() != sec;
}

int main() {
    Agol a1; int deg, min, sec; cin >> deg >> min >> sec;
    
    if (proveri(deg, min, sec)) {
    	a1.set_stepeni(deg); a1.set_minuti(min); a1.set_sekundi(sec); 
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1,sec))
			cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;
    }
    else cout<<"Nevalidni vrednosti za agol";
    return 0;
}