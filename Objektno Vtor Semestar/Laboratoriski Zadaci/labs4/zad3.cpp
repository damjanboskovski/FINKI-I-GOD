#include <iostream>
#include <string.h>
using namespace std;

class Avtomobil{
    private:
        char color[20], brand[20], model[20];
    public:
        Avtomobil(){};
        Avtomobil(char *c, char *b, char *m){ strcpy(this->color,c); strcpy(this->brand,b); strcpy(this->model,m); }
		Avtomobil(const Avtomobil &other){ strcpy(this->color,other.color); strcpy(this->brand,other.brand); strcpy(this->model,other.model); }
        Avtomobil &operator=(const Avtomobil &other){
            if(this != &other){ strcpy(this->color,other.color);  strcpy(this->brand,other.brand); strcpy(this->model,other.model);}
			return *this; }
        ~Avtomobil(){};

        char *getColor() {return this->color;} char *getBrand() {return this->brand;} char *getModel() {return this->model;} 
};

class ParkingPlac{
    private:
        char address[50], *id{nullptr}; int price{0}, earning{0}, num{0}; Avtomobil *arr{nullptr};
    public:
        ParkingPlac(){ this->id=nullptr; this->arr=nullptr; this->num=0; }

    	ParkingPlac(char *address, char *id, int price):ParkingPlac(){
    		strcpy(this->address,address); this->price=price;
    		this->id = new char[strlen(id)+1]; strcpy(this->id,id);  }

    	ParkingPlac(const ParkingPlac &other){
			strcpy(this->address,other.address);
    		delete[] id; this->id = new char[strlen(other.id)+1]; strcpy(this->id,other.id);
    		this->price=other.price; this->earning=other.earning; this->num=other.num;
    		delete[] this->arr; this->arr = new Avtomobil[this->num]; 
			for(int i=0; i<this->num; i++){ this->arr[i] = other.arr[i]; } }

		ParkingPlac &operator = (const ParkingPlac &other){ 
			if(this != &other){
   				delete[] this->id; this->id = new char[strlen(other.id)+1]; strcpy(this->id,other.id);
    			this->price=other.price; this->earning=other.earning; this->num=other.num; strcpy(this->address,other.address);
    			delete[] this->arr; this->arr = new Avtomobil[this->num]; for(int i=0; i<this->num; i++){ this->arr[i] = other.arr[i]; } } return *this; }

    	~ParkingPlac(){ delete[] this->id; id = nullptr; delete[] this->arr; arr = nullptr; }

    	void platiCasovi(int hours){ this->earning += this->price * hours; }
    	bool daliIstaAdresa(ParkingPlac &other) { return (strcmp(this->address,other.address)==0); }
		void parkirajVozilo(Avtomobil &other){
			Avtomobil *tmp = new Avtomobil[this->num+1];
    		for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
    		tmp[this->num++] = other; delete[] this->arr; this->arr = tmp;
		}
    	void pecati(){ cout<<this->id<<" "<<this->address; if(earning){ cout<<" - "<<this->earning<<" denari"; } cout<<endl; }
    	void pecatiParkiraniVozila(){ cout<<"Vo parkingot se parkirani slednite vozila:"<<endl;
    	for(int i=0; i<this->num; i++){ cout<<i+1<<"."<<this->arr[i].getColor()<<" "<<this->arr[i].getBrand()<<" "<<this->arr[i].getModel()<<endl; } }
		char *getId(){ return this->id; }
};

int main(){

	ParkingPlac p[100];
	int n, m, brojcasovi,cenacas; cin>>n; char adresa[50],id[50];

	if(n > 0){
		for (int i=0;i<n;i++){
	        cin.get(); cin.getline(adresa,50); cin>>id>>cenacas;
			ParkingPlac edna(adresa,id,cenacas);  p[i]=edna; }

		cin>>m;
		for (int i=0;i<m;i++){
			cin>>id>>brojcasovi; int findId=false;
	        for (int j=0;j<n;j++){
	            if (strcmp(p[j].getId(),id)==0){ p[j].platiCasovi(brojcasovi); findId=true; }
	        }
			if (!findId) cout<<"Ne e platen parking. Greshen ID."<<endl;
		}

	    cout<<"========="<<endl;
	    ParkingPlac pCentar("Cvetan Dimov","C10",80);
		for (int i=0;i<n;i++){ if (p[i].daliIstaAdresa(pCentar)) {p[i].pecati();}}
	} 
	else {
		ParkingPlac najdobarPlac("Mars", "1337", 1); int brVozila; cin >> brVozila;
	    for(int i = 0; i < brVozila; ++i){
	    	char boja[20], brend[20], model[20];
	    	cin >> boja >> brend >> model;
	    	Avtomobil novAvtomobil(boja, brend, model);
	    	najdobarPlac.parkirajVozilo(novAvtomobil);
	    }
	    if(brVozila != 0) {najdobarPlac.pecatiParkiraniVozila();}
	}  
}