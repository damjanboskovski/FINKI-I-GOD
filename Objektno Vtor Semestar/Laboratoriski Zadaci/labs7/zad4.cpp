#include <iostream>
using namespace std;

class Vozilo{
    protected:
        double mass{0}; int width{0},height{0};
    public:
        Vozilo(double m, int w, int h){ this->mass = m; this->width = w; this->height = h; }
        virtual int vratiDnevnaCena() = 0; double getMass(){ return mass; }
        int getWidth(){ return width; } int getHeight(){ return height; }
};

class Avtomobil : public Vozilo{
    private:
        int doors{0};
    public:
        Avtomobil(double m, int w, int h, int d):Vozilo(m,w,h){ this->doors = d;}
        int vratiDnevnaCena(){ return doors<5?100:130; } int getDoors(){ return doors; }
};

class Avtobus : public Vozilo{
    private:
        int passengers{0};
    public:
        Avtobus(double m, int w, int h, int p):Vozilo(m,w,h){ this->passengers = p; }
        int vratiDnevnaCena(){ return 5*passengers; } int getPassengers(){ return passengers; }
};

class Kamion : public Vozilo{
    private:
        double maxMass{0};
    public:
        Kamion(double m, int w, int h, double mm):Vozilo(m,w,h){ this->maxMass = mm; }
        int vratiDnevnaCena(){ return (mass + maxMass) * 0.02; } int getMax(){ return maxMass; }
};

class ParkingPlac{
    private:
        Vozilo **arr; int num{0};
    public:
        ParkingPlac(){ arr = new Vozilo *[num]; }
        ~ParkingPlac(){ delete[] arr; }

        ParkingPlac &operator+=(Vozilo *v){
            Vozilo **temp = new Vozilo *[num+1];
            for(int i=0; i<num; i++){ temp[i] = arr[i]; }
            temp[num] = v; delete[] arr; arr = temp; num++; return *this;
        }

        double presmetajVkupnaMasa(){
            double sum=0; for(int i=0; i<num; i++){ sum+=arr[i]->getMass(); } return sum;
        }
        int brojVozilaPoshirokiOd(int l){ 
            int sum=0; for(int i=0; i<num; i++){ if(arr[i]->getWidth() > l){ sum++; } } return sum;
        }
        int pogolemaNosivostOd(Vozilo &other){
            int sum=0; 
            for(int i=0; i<num; i++){ 
                if(dynamic_cast<Kamion*>(arr[i]) && arr[i]->getMass() > other.getMass()){ sum++; } 
            } return sum;
        }
        int vratiDnevnaZarabotka(){
            int sum=0; for(int i=0; i<num; i++){ sum+=arr[i]->vratiDnevnaCena(); } return sum;
        }

        void pecati(){
            int carsCnt=0, busCnt=0, trucksCnt=0;
            for(int i=0; i<num; i++){
                if(dynamic_cast<Avtomobil*>(arr[i])){ carsCnt++; }
                else if(dynamic_cast<Avtobus*>(arr[i])){ busCnt++; }
                else if(dynamic_cast<Kamion*>(arr[i])){ trucksCnt++; }
            }
            cout<<"Brojot na avtomobili e "<<carsCnt<<", brojot na avtobusi e "<<busCnt<<" i brojot na kamioni e "<<trucksCnt<<"."<<endl;
        }
};

int main(){
    ParkingPlac p; int n; cin>>n; int shirina,visina, broj; float masa,nosivost;

    for (int i=0;i<n;i++){
        int type; cin>>type;
        if(type==1){
            cin>>masa>>shirina>>visina>>broj;
            Avtomobil *a=new Avtomobil(masa,shirina,visina,broj); p+=a;
        }
        if(type==2){
            cin>>masa>>shirina>>visina>>broj;
            p+=new Avtobus(masa,shirina,visina,broj);
        }
        if(type==3){
            cin>>masa>>shirina>>visina>>nosivost;
            p+=new Kamion(masa,shirina,visina,nosivost);
        }
    }
    p.pecati(); cout<<"\nZarabotkata e "<<p.vratiDnevnaZarabotka()<<endl;
    cout<<"Vkupnata masa e "<<p.presmetajVkupnaMasa()<<endl;
    cout<<"Brojot poshiroki od 5 e "<<p.brojVozilaPoshirokiOd(5)<<endl;
    Avtomobil a(1200,4,3,5);
    cout<<"Brojot na kamioni so nosivost pogolema od avtomobilot e "<<p.pogolemaNosivostOd(a)<<endl; return 0;
}