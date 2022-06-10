#include <iostream>
#include <cstring>
using namespace std;

class Koncert{
    protected:
        char name[20], location[20]; float ticketPrice{0}; static float discount;
    public:
        Koncert(){}
        Koncert(char *n, char *l, float t){ strcpy(this->name,n); strcpy(this->location,l); this->ticketPrice = t; }
        Koncert(const Koncert &other){
            if(this != &other){
                strcpy(this->name, other.name); strcpy(this->location, other.location); this->ticketPrice = other.ticketPrice;
            }
        }
        Koncert &operator=(const Koncert &other){
            if(this != &other){
                strcpy(this->name, other.name); strcpy(this->location, other.location); this->ticketPrice = other.ticketPrice;
            } return *this;
        }
        ~Koncert(){}
        virtual float cena(){ return this->ticketPrice * (1.0 - discount); }
        char *getNaziv(){ return this->name;}
        float getSezonskiPopust(){ return discount; }
        void setSezonskiPopust(float n){ discount = n; }
};

class ElektronskiKoncert : public Koncert{
    private:
        char *djName{nullptr}; float hours{0}; bool isDaily{false};
    public:
        ElektronskiKoncert(){}
        ElektronskiKoncert(char *n, char *l, float t, char *d, float h, bool id) : Koncert(n,l,t){
            this->djName = new char[strlen(d)]; strcpy(this->djName, d); this->hours = h; this->isDaily = id;
        }
        ~ElektronskiKoncert(){}
        
        float cena(){
            int sum = 0;  
            if(hours > 7){ sum += 360; } else if(hours > 5){ sum += 150; }
            if(isDaily){ sum -= 50;} else sum += 100;
            return this->ticketPrice * (1.0 - discount) + sum;
        }
};

void najskapKoncert(Koncert **k, int n){
    float max = 0; int pos = 0, sum = 0;
    for(int i=0; i<n; i++){
        if(max <= k[i]->cena()){
            max = k[i]->cena(); pos = i;
        }
        if(dynamic_cast<ElektronskiKoncert *>(k[i])){ sum++; }
    }
    cout<<"Najskap koncert: "<<k[pos]->getNaziv()<<" "<<k[pos] ->cena()<<endl;
    cout<<"Elektronski koncerti: "<<sum<<" od vkupno "<<n<<endl;
}

bool prebarajKoncert(Koncert **k, int n, char *name, bool e){
    for(int i=0; i<n; i++){
        if(!e || dynamic_cast<ElektronskiKoncert *>(k[i])){
            if(!strcmp(name, k[i]->getNaziv())){
                cout<<k[i]->getNaziv()<<" "<<k[i]->cena()<<endl;
                return true;
            }
        }
    }
    return false;
}

float Koncert::discount = 0.2;

int main(){

    int tip,n,novaCena; char naziv[100], lokacija[100], imeDJ[40]; bool dnevna; float cenaBilet, novPopust, casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5]; int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100]; najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	Koncert ** koncerti = new Koncert *[5]; int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100]; bool elektronski; cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski)){ cout<<"Pronajden"<<endl; }
            else{ cout<<"Ne e pronajden"<<endl; }

            if(prebarajKoncert(koncerti,5, "Area",!elektronski)){ cout<<"Pronajden"<<endl; }
            else{ cout<<"Ne e pronajden"<<endl; }
        }
        else if (tip==8){//smeni cena
        	Koncert ** koncerti = new Koncert *[5]; int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(0.9); najskapKoncert(koncerti,4);
        }
    return 0;
}
