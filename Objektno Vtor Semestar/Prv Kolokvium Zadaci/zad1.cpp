#include <iostream>
#include <string.h>
using namespace std;

enum tip{pop, rap, rok};

class Pesna{
    private:
        char *songName{nullptr}; int time{0}; tip kojtip{(tip)0};
    public:
        Pesna(){ this->songName = nullptr; }
        Pesna(char *n, int t, tip k):Pesna(){
            this->songName = new char[strlen(n)+1]; strcpy(this->songName,n);
            this->time = t; this->kojtip = k;
        }
        Pesna(Pesna &other){
            if(this != &other){
                this->songName = new char[strlen(other.songName)+1];
                strcpy(this->songName,other.songName); this->time = other.time; this->kojtip = other.kojtip;
            }
        }
        ~Pesna(){ delete[] this->songName; this->songName = nullptr; }

        void pecati(){ cout<<"\""<<this->songName<<"\"-"<<this->time<<"min"<<endl; }
        int getTime(){ return this->time; } tip getTip(){ return this->kojtip; }
};

class CD{
    private:
        Pesna arr[10]; int songNum, maxTime;
    public:
        CD(){};
        CD(int t){ this->maxTime = t; this->songNum = 0; }
        ~CD(){};
        
        void dodadiPesna(Pesna p){
            int temp = 0; for(int i = 0; i<this->songNum; i++){ temp += arr[i].getTime(); }
            if(songNum < 10 && (temp + p.getTime() <= maxTime)){ arr[songNum++] = p; }
        }

        void pecatiPesniPoTip(tip t){ for(int i=0; i<this->songNum; i++){ if(arr[i].getTip() == t) { arr[i].pecati(); } }}
        Pesna getPesna(int i){ return this->arr[i]; } int getBroj(){ return this->songNum; }
};

int main()
{
    int testCase; cin >> testCase;
    int n, minuti, kojtip; char ime[50];

    if (testCase == 1){
        cout << "===== Testiranje na klasata Pesna ======";
        cin >> ime >> minuti >> kojtip;
        Pesna p(ime, minuti, (tip) kojtip); p.pecati();
    }
    else if (testCase == 2){
        cout << "===== Testiranje na klasata CD ======";
        CD omileno(20); cin >> n;
        for (int i = 0; i < n; i++){
            cin >> ime >> minuti >> kojtip;
            Pesna p(ime, minuti, (tip) kojtip);  omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++) (omileno.getPesna(i)).pecati();
    }
    else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======";
        CD omileno(20); cin >> n;
        for (int i = 0; i < n; i++){
            cin >> ime >> minuti >> kojtip;
            Pesna p(ime, minuti, (tip) kojtip); omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++) (omileno.getPesna(i)).pecati();
    }
    else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======";
        CD omileno(20); cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime >> minuti >> kojtip;
            Pesna p(ime, minuti, (tip) kojtip); omileno.dodadiPesna(p);
        }
        cin >> kojtip; omileno.pecatiPesniPoTip((tip) kojtip);
    }
    else if (testCase == 5)
    {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======";
        CD omileno(20); cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime >> minuti >> kojtip;
            Pesna p(ime, minuti, (tip) kojtip); omileno.dodadiPesna(p);
        }
        cin >> kojtip; omileno.pecatiPesniPoTip((tip) kojtip);
    }
    return 0;
}
