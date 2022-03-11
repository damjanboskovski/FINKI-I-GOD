#include <iostream>
#include <cstring>
using namespace std;

class Patnik{
    private:
        char name[100]={'\0'}; int type=0; bool bike;
    public:
    Patnik(){}; 
    Patnik(char n1[100],int t1, bool b1){
        strcpy(name,n1); type=t1; bike=b1;
    }
    ~Patnik(){};

    Patnik &operator=(const Patnik &other){ 
        strcpy(name, other.name); type = other.type; bike=other.bike; }
    friend ostream &operator<<(ostream &out,const Patnik &other){
        out<<other.name<<endl<<other.type<<endl<<other.bike<<endl;
        return out<<endl;
    }

    int getType()const{return type;} bool getBike()const{return bike;}
    char *getName(){return name;}
};

class Voz{
    private:
        char destination[100]={'\0'}; Patnik *p;
        int num=0, bikes=0,cnt1=0,cnt2=0;
    public:
        Voz(){};
        Voz(char d1[100], int b1){
            strcpy(destination,d1); bikes=b1; p = new Patnik[100];
        } ~Voz(){};

        Voz &operator+=(Patnik &other){p[num]=other; num++;}

        friend ostream &operator<<(ostream &out, Voz &other){
            out << other.destination<<endl;
            
            if(other.bikes == 0){
                for(int i=0;i<other.num;i++)
                {
                    if(!other.p[i].getBike()){ out<<other.p[i];}
                }
            }
            else{
                for(int i=0;i<other.num;i++)
                {
                    if(other.p[i].getBike()){ 
                        if(other.p[i].getType()==1){
                            (other.bikes>0?other.bikes--:other.cnt1++);
                        } 
                    }
                }

                for(int i=0;i<other.num;i++)
                {
                    if(other.p[i].getBike()){ 
                        if(other.p[i].getType()==2){
                            (other.bikes>0?other.bikes--:other.cnt2++);
                        }
                    }
                }        
                for(int i=0;i<other.num;i++){out<<other.p[i];}
            }
            return out;
        }
        
    
    void patniciNemaMesto(){
        cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<cnt1<<endl;
        cout<<"Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<cnt2<<endl;
    }
};

int main()
{
	Patnik p;
	char ime[100], destinacija[100];
	int n,klasa,maxv; bool velosiped;
	cin>>destinacija>>maxv>>n;
	Voz v(destinacija, maxv);
	//cout<<v<<endl;
	for (int i = 0; i < n; i++){
		cin >> ime >> klasa >> velosiped;
		Patnik p(ime, klasa, velosiped);
		//cout<<p<<endl;
		v += p;
	}
	cout << v;
	v.patniciNemaMesto();

	return 0;
}
