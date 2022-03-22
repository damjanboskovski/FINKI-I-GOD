#include <iostream>
#include <cstring>
using namespace std;

class Potpisuvac {
    private:
        char name[20], lastName[20], embg[14];
    public:
        Potpisuvac(){*name = '\0'; *lastName = '\0'; *embg = '\0';}
        Potpisuvac(const char *n, const char *l, const char *e){
            strcpy(name,n); 
            strcpy(lastName,l);
            strcpy(embg,e);
        }
        ~Potpisuvac(){};
    
    const char *getEmbg(){return embg;}
    Potpisuvac(const Potpisuvac &p) : Potpisuvac(p.name,p.lastName,p.embg){}
};

class Dogovor {
    private:
        int num; char category[50]; Potpisuvac p[3];
    public:
        Dogovor(){};
        Dogovor(int n, char *c, Potpisuvac *p1){
            num = n; strcpy(category,c);
            for(int i=0;i<3;i++){p[i]=p1[i];}
        }

        bool proverka() {
            for (int i = 0; i < 3; i++){
                if (strcmp(p[i].getEmbg(), p[i+1].getEmbg()) == 0){return true;}
            }
            return false;
        }
};

int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime; Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime; Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime; Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija; Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl; 
    	
        if(d.proverka() == true){cout << "Postojat potpishuvaci so ist EMBG" << endl;}
    	else{cout << "Ne postojat potpishuvaci so ist EMBG" << endl;}
    }
    return 0;
}