#include <iostream>
#include <cstring>
using namespace std;

class Rabotnik{
    private:
        char name[30] = {'\0'}, lastName[30] = {'\0'}; int salary = 0;
    public:
        Rabotnik(){*name = '\0'; *lastName = '\0'; salary = 0;}
        Rabotnik(char *n, char *l, int n1){
            strcpy(this->name,n); strcpy(this->lastName,l); salary = n1;
        }
        ~Rabotnik(){};
        
        int getPlata() const {return salary;}
        void pecati(){cout<<name<<" "<<lastName<<" "<<salary<<endl;}
};

class Fabrika{
    private:
        Rabotnik r[100]; int num;
    public:
        Fabrika(){};
        Fabrika(Rabotnik *r1, int n){
            this->num = n; for(int i=0;i<num;i++){ this->r[i] = r1[i];}
        }
        ~Fabrika(){};

        void pecatiVraboteni(){
            cout<<"Site vraboteni:"<<endl;
            for(int i=0;i<num;i++){ r[i].pecati(); }
        }

        void pecatiSoPlata(int plata){
            cout<<"Vraboteni so plata povisoka od "<<plata<<" :"<<endl;
            for(int i=0;i<num;i++){
                if(r[i].getPlata() > plata){ r[i].pecati(); }
            }
        }
};

int main(){
    int num, salary, minSalary;
    char name[30],lastName[30];
    Rabotnik r[100];

    cin>>num;
    for(int i=0;i<num;i++){
        cin >> name >> lastName >>salary;
        r[i] = Rabotnik(name, lastName, salary);
    }
    
    cin >> minSalary; Fabrika f(r,num);

    f.pecatiVraboteni();
    f.pecatiSoPlata(minSalary);

    return  0;
}