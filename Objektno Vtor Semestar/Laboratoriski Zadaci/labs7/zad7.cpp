#include <iostream>
#include <cstring>
using namespace std;

class Secret{ public: Secret(){} virtual double simpleEntropy() = 0; virtual int total() = 0; };

class DigitSecret : public Secret{
    private:
        int num[100], n{0};
    public:
        DigitSecret(int *num, int n):Secret(){ for(int i=0; i<n; i++){ this->num[i] = num[i]; } this->n = n; }
        double simpleEntropy(){
            int sum=0;
            for(int i=0; i<n; i++){ int sum2=0; 
                for(int j=0; j<n; j++){ if(num[i] == num[j]){ sum2++; } }
                if(sum2==1){ sum++; }    
            }
            return (double)sum/n;
        }
        int total(){ return n; }
        friend ostream &operator<<(ostream &out, DigitSecret &other){
            for(int i=0; i<other.n; i++){ out<<other.num[i]; }
            out<<" Simple entropy: "<<other.simpleEntropy()<<" Total: "<<other.total(); return out;
        }
}; 

class CharSecret : public Secret{
    private:
        char chars[100];
    public:
        CharSecret(char *c):Secret(){ strcpy(this->chars, c); }
        double simpleEntropy(){
            int sum=0;
            for(int i=0; i<strlen(chars); i++){ int sum2=0; 
                for(int j=0; j<strlen(chars); j++){ if(chars[i] == chars[j]){ sum2++; } }
                if(sum2==1){ sum++; }    
            }
            return (double)sum/strlen(chars);
        }
        int total(){ return strlen(chars); }
        friend ostream &operator<<(ostream &out, CharSecret &other){
            out<<other.chars<<" Simple entropy: "<<other.simpleEntropy()<<" Total: "<<other.total(); return out; 
        }
};

bool operator==(Secret &s, Secret &s1){ return ((s.simpleEntropy() == s1.simpleEntropy()) && (s.total() == s1.total())); }
bool operator!=(Secret &s, Secret &s1){ return !((s.simpleEntropy() == s1.simpleEntropy()) && (s.total() == s1.total())); }

void process(Secret **secrets, int n){
    double max = secrets[0]->simpleEntropy(); int pos;
    for(int i=1; i<n; i++){
        if(secrets[i]->simpleEntropy() > max){ max = secrets[i]->simpleEntropy(); pos = i; }
    }
    if(dynamic_cast<DigitSecret*>(secrets[pos])){ cout<<*dynamic_cast<DigitSecret*>(secrets[pos])<<endl; }
    else if(dynamic_cast<CharSecret*>(secrets[pos])){ cout<<*dynamic_cast<CharSecret*>(secrets[pos])<<endl; }
}

void printAll(Secret **secrets, int n){
    for(int i=0; i<n; i++){
        if(dynamic_cast<DigitSecret*>(secrets[i])){ cout<<*dynamic_cast<DigitSecret*>(secrets[i])<<endl; }
        else if(dynamic_cast<CharSecret*>(secrets[i])){ cout<<*dynamic_cast<CharSecret*>(secrets[i])<<endl; }
    }
}

int main() {
    int n; cin >> n;
    if(n == 0) {
		cout << "Constructors" << endl; int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5); CharSecret cs("abcabc"); cout << "OK" << endl;
    } 
    else if(n == 1) {
  		cout << "operator <<" << endl; int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5); CharSecret cs("abcabc");
        cout << ds << endl << cs << endl;
    }  
    else if(n == 2) {
  		cout << "== and !=" << endl; int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5); CharSecret cs("abcabc"); CharSecret css("abcabc");
        cout << (ds == cs) << endl << (cs != ds) << endl << (cs == css) << endl << (cs != css) << endl;
    } 
    else if(n == 3) {
  		cout << "Secret processor" << endl; int numbers1 [] = {1,2,3,4,5,6,4,3,2,1,1,2,3,4,5};
        DigitSecret ds1(numbers1,15); int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
        DigitSecret ds2(numbers2,15); int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
        DigitSecret ds3(numbers3,20); CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw"); CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq"); Secret** s = new Secret*[6];
        s[0] = &ds1; s[1] = &ds2; s[2] = &ds3; s[3] = &cs1; s[4] = &cs2; s[5] = &cs3; process(s,6); delete [] s;
    }
    else if (n==4){
        cout << "Print all secrets" << endl; int numbers1 [] = {1,2,3,4,5,5,4,3,2,1,1,2,3,4,5};
        DigitSecret ds1(numbers1,15); int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
        DigitSecret ds2(numbers2,15); int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
        DigitSecret ds3(numbers3,20); CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw"); CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq"); Secret** s = new Secret*[6];
        s[0] = &ds1; s[1] = &ds2; s[2] = &ds3; s[3] = &cs1; s[4] = &cs2; s[5] = &cs3; printAll(s,6); delete [] s;
    } return 0;
}