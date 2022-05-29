#include <iostream>
#include <cstring>
using namespace std;

class Exception{ 
    public: 
        static void message(){ cout << "Ne moze da se vnese dadeniot trud" << endl; } 
};

class Trud{
    private:
        char type{0}; int year{0};
    public:
        Trud(){}
        Trud(char t, int y) { this->type = t; this->year = y; }
        ~Trud(){}

        friend istream &operator>>(istream &in, Trud &other){ return in >> other.type >> other.year; }
        char getType() const{ return type; } int getYear() const { return year; }
};

class Student
{
    private:
        char name[30]; int index{0}, registration{0}, grades[50], num{0};
public:
    Student(){}
    Student(const char *n, int i, int r, int *g, int num){
        strcpy(this->name, n); this->index = i; this->registration = r;
        for (int i = 0; i < num; ++i){ this->grades[i] = g[i]; } this->num = num;
    }
    ~Student(){}

    friend ostream &operator<<(ostream &out, const Student &other){ return out << other.index << " " << other.name << " " << other.registration << " " << other.rank() << endl; }
    virtual double rank() const { double sum = 0; for (int i = 0; i < num; i++) { sum += grades[i]; } return sum / num; }
    int getReg() const { return registration; } int getIndex() const { return index; }
};

class PhDStudent : public Student{
    private:
        Trud *arr{nullptr}; int numArr{0}; static int c, j;
    public:
        PhDStudent(const char *n, int i, int r, int *g, int num, Trud *arr, int numArr) : Student(n, i, r, g, num){
            this->arr = new Trud[numArr];
            for (int i = 0; i < numArr; ++i)
                try {
                    if (arr[i].getYear() < r) { throw Exception(); }
                    else{ this->arr[i] = arr[i]; }
                }
                catch (Exception) { Exception::message(); }
            this->numArr = numArr;
        }

        ~PhDStudent(){ delete[] arr; }

        PhDStudent &operator+=(Trud &other) {
            if (other.getYear() < getReg()){ throw Exception(); }
            Trud *temp = new Trud[numArr + 1];
            for (int i = 0; i < numArr; ++i){ temp[i] = arr[i]; }
            temp[numArr++] = other; delete[] arr; arr = temp; return *this; 
        }

        static void setC(int a){ c = a; } static void setJ(int a){ j = a; }

        double rank() const {
            double suma = Student::rank(); double sum=0;
            for (int i = 0; i < numArr; i++){
                if (arr[i].getType() == 'j' || arr[i].getType() == 'J'){ sum += j; }
                else if (arr[i].getType() == 'c' || arr[i].getType() == 'C'){ sum += c; }
            } return sum+suma;
        }
};

int PhDStudent::c = 1;
int PhDStudent::j = 3;

int main()
{
    int testCase; cin >> testCase; int god, indeks, n, god_tr, m, n_tr, izbor, oceni[50]; char ime[30],  tip;Trud trud[50];

    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime >> indeks >> god >> n; for (int j = 0; j < n; j++){ cin >> oceni[j]; }
        Student s(ime, indeks, god, oceni, n); cout << s;

        cin >> ime >> indeks >> god >> n; for (int j = 0; j < n; j++){ cin >> oceni[j]; } 

        cin >> n_tr; for (int j = 0; j < n_tr; j++) { cin >> tip >> god_tr; Trud t(tip, god_tr); trud[j] = t; }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr); cout << phd;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl; Student **niza; cin >> m; niza = new Student *[m];
        for (int i = 0; i < m; i++){
            cin >> izbor >> ime >> indeks >> god >> n;
            for (int j = 0; j < n; j++){ cin >> oceni[j]; }

            if (izbor == 0){ niza[i] = new Student(ime, indeks, god, oceni, n); }
            else{ cin >> n_tr;
                for (int j = 0; j < n_tr; j++){ cin >> tip >> god_tr; Trud t(tip, god_tr); trud[j] = t; }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }

        // dodavanje nov trud za PhD student spored indeks
        Trud t; cin >> indeks >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
        bool found = false;
        for (int i = 0; i < m; ++i){ if (dynamic_cast<PhDStudent *>(niza[i]) && niza[i]->getIndex() == indeks){ *dynamic_cast<PhDStudent *>(niza[i]) += t; found = true; } }

        if (!found){ cout << "Ne postoi PhD student so indeks " << indeks << endl; }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }
    }
    if (testCase == 3){
        cout << "===== Testiranje na operatorot += ======" << endl; Student **niza; cin >> m; niza = new Student *[m];
        for (int i = 0; i < m; i++){
            cin >> izbor >> ime >> indeks >> god >> n;
            for (int j = 0; j < n; j++){ cin >> oceni[j]; }

            if (izbor == 0){ niza[i] = new Student(ime, indeks, god, oceni, n); }
            else { cin >> n_tr;
                for (int j = 0; j < n_tr; j++){ cin >> tip >> god_tr; Trud t(tip, god_tr); trud[j] = t; }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }

        // dodavanje nov trud za PhD student spored indeks
        Trud t; cin >> indeks >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2
        for (int i = 0; i < m; ++i){ if (dynamic_cast<PhDStudent *>(niza[i]) && niza[i]->getIndex() == indeks) { *dynamic_cast<PhDStudent *>(niza[i]) += t; } }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }
    }
    if (testCase == 4){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> ime >> indeks >> god >> n; for (int j = 0; j < n; j++){ cin >> oceni[j]; }

        cin >> n_tr; for (int j = 0; j < n_tr; j++){ cin >> tip >> god_tr; Trud t(tip, god_tr); trud[j] = t; }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr); cout << phd;
    }
    if (testCase == 5)
    {
        cout << "===== Testiranje na isklucoci ======" << endl; Student **niza; cin >> m; niza = new Student *[m];
        for (int i = 0; i < m; i++){
            cin >> izbor >> ime >> indeks >> god >> n; for (int j = 0; j < n; j++) { cin >> oceni[j]; }

            if (izbor == 0){ niza[i] = new Student(ime, indeks, god, oceni, n); }
            else { cin >> n_tr;
                for (int j = 0; j < n_tr; j++){ cin >> tip >> god_tr; Trud t(tip, god_tr); trud[j] = t; }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }

        // dodavanje nov trud za PhD student spored indeks
        Trud t; cin >> indeks >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot
        try { for (int i = 0; i < m; ++i){ if (dynamic_cast<PhDStudent *>(niza[i]) && niza[i]->getIndex() == indeks){ *dynamic_cast<PhDStudent *>(niza[i]) += t; } } }
        catch (Exception){ Exception::message(); }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }
    }
    if (testCase == 6){
        cout << "===== Testiranje na static clenovi ======" << endl; Student **niza; cin >> m; niza = new Student *[m];
        for (int i = 0; i < m; i++){
            cin >> izbor >> ime >> indeks >> god >> n; for (int j = 0; j < n; j++) { cin >> oceni[j]; }

            if (izbor == 0){ niza[i] = new Student(ime, indeks, god, oceni, n); }
            else { cin >> n_tr;
                for (int j = 0; j < n_tr; j++){ cin >> tip >> god_tr; Trud t(tip, god_tr); trud[j] = t; }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }

        int conf, journal; cin >> conf; cin >> journal;
        //postavete gi soodvetnite vrednosti za statickite promenlivi
        PhDStudent::setC(conf);  PhDStudent::setJ(journal);

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++){ cout << *niza[i]; }
    } return 0;
}