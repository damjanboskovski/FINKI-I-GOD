#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

enum tip{pop, rap, rock};

class Pesna{
    private:
        char ime[50]; int minuti; tip kojtip;
    public:
        Pesna(){};
        Pesna(char ime1[50],int minuti1,tip kojtip1){
            strcpy(ime,ime1); minuti = minuti1; kojtip = kojtip1;
        }
        ~Pesna(){};
        void pecati(){cout<<"\n\""<<ime<<"\"-"<<minuti<<"min";}
        tip getTip(){return kojtip;}
        int getMinuti(){return minuti;}
};

class CD
{
    private:
        Pesna p[10]; int pesni, minuti;
    public:
        CD(){};
        CD(int minuti1){ minuti = minuti1;pesni = 0;}
        ~CD(){};
        void dodadiPesna(Pesna p1){
            int moment = 0;
            for (int i = 0; i < pesni; i++) {moment += p[i].getMinuti();}
            if (pesni < 10 && moment + p1.getMinuti() <= minuti){p[pesni] = p1; pesni++;}
        }

        void pecatiPesniPoTip(tip t){
            for (int i = 0; i < pesni; i++){if (p[i].getTip() == t) p[i].pecati();}
        }
        Pesna getPesna(int i){return p[i];}
        int getBroj(){return pesni;}
};

int main()
{
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1)
    {
        cout << "===== Testiranje na klasata Pesna ======";
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (tip) kojtip);
        p.pecati();
    }
    else if (testCase == 2)
    {
        cout << "===== Testiranje na klasata CD ======";
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if (testCase == 3)
    {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======";
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if (testCase == 4)
    {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======";
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }
    else if (testCase == 5)
    {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======";
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }

    return 0;
}