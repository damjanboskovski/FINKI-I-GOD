#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo{
    private:
        char *name{nullptr}; int touristNumber{0}, memberNumber{0};
    public:
        PlDrustvo(){ this->name = nullptr; }
        PlDrustvo(char *n, int t, int m){ 
            this->name = new char[strlen(n)+1]; strcpy(this->name,n);
            this->touristNumber = t; this->memberNumber = m;
        }
        PlDrustvo operator+(const PlDrustvo &other){
            PlDrustvo p = memberNumber > other.memberNumber?PlDrustvo(name, touristNumber, memberNumber + other.memberNumber):PlDrustvo(other.name, other.touristNumber, memberNumber + other.memberNumber); return p;
        }
        
        bool operator<(const PlDrustvo &other) const {  if(memberNumber < other.memberNumber){ return true; } return false; }
        bool operator>(const PlDrustvo &other) const {  if(memberNumber > other.memberNumber){ return true; } return false; }

        friend ostream &operator<<(ostream &out, const PlDrustvo &other){
            out<<"Ime: " << other.name <<" Turi: "<<other.touristNumber<<" Clenovi: "<<other.memberNumber<<endl; return out;
        }

        int getMembers(){ return this->memberNumber; }
};

void najmnoguClenovi(PlDrustvo pDr[3], int n){
    int pos = 0,max = pDr[0].getMembers();
    for(int i=0; i<n; i++){ if(max < pDr[i].getMembers()){ max = pDr[i].getMembers(); pos = i; } }
    cout<<"Najmnogu clenovi ima planinarskoto drustvo: "<<pDr[pos];
}

int main()
{        		
    PlDrustvo drustva[3]; PlDrustvo pl;
    for (int i=0;i<3;i++) {
    	char ime[100]; int brTuri, brClenovi;
    	cin >> ime >> brTuri >> brClenovi;
    	PlDrustvo p(ime,brTuri,brClenovi); drustva[i] = p;
   	}
    pl = drustva[0] + drustva[1]; cout<<pl; najmnoguClenovi(drustva, 3);
    
    return 0;
}