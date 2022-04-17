#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber{
    private:
        double real{0}, imaginary{0};
    public:
        explicit ComplexNumber(double r=0, double i=0){ this->real = r; this->imaginary = i; }
        ComplexNumber (const ComplexNumber &other){ if(this != &other){ this->real = other.real; this->imaginary = other.imaginary; } }
        ComplexNumber &operator=(const ComplexNumber &other){if(this != &other){ this->real = other.real; this->imaginary = other.imaginary; } return *this; }
        
        ComplexNumber operator+(const ComplexNumber &other) const { return ComplexNumber(real + other.real, imaginary + other.imaginary); }
        ComplexNumber operator-(const ComplexNumber &other) const { return ComplexNumber(real - other.real, imaginary - other.imaginary); }
        ComplexNumber operator*(const ComplexNumber &other) const { return ComplexNumber(real * other.real, imaginary * other.imaginary); }
        ComplexNumber operator/(const ComplexNumber &other) const { return ComplexNumber(real / other.real, imaginary / other.imaginary); }

        bool operator==(const ComplexNumber &other) const { if( real == other.real && imaginary == other.imaginary ){ return true; } return false; }

        bool operator<(const ComplexNumber &other) const{ 
            if(real < other.real){ return true; }
            else if( real > other.real){ return false; }
            else {
                if(imaginary < other.imaginary){ return true;}
                else return false;
            }
        }

        bool operator>(const ComplexNumber &other) const{ 
            if(real > other.real){ return true; }
            else if( real < other.real){ return false; }
            else {
                if(imaginary > other.imaginary){ return true;}
                else return false; }
        }

        friend ostream &operator<<(ostream &out, const ComplexNumber &other){
            if(other.real > 0 && other.imaginary > 0){ out<<other.real<<"+"<<other.imaginary<<"i"<<endl; }
            else if(other.real > 0 && other.imaginary == 0){ out<<other.real<<endl; }
            else if(other.real == 0 && other.imaginary > 0){ out<<other.imaginary<<"i"<<endl; } return out;
        }

        double module(){ return sqrt(pow(real,2) + pow(imaginary,2)); }
};

class Equation{
    private:
        ComplexNumber *arr{nullptr}; char *operators{nullptr}; int num{0};
    public:
        explicit Equation(int n = 0){ arr = new ComplexNumber[1024]; operators = new char[1024]; this->num = n; }
        
        friend istream &operator>>(istream &in, Equation &other){
            int cnt=0; double a[2]; char op;
            while(other.operators[cnt] != '='){
                in>>a[0]>>a[1]>>op;
                other.arr[cnt] = ComplexNumber(a[0], a[1]); other.operators[cnt] = op;
                cnt++; if(op == '='){ break; }
            } other.num = cnt; return in;
        }

        ComplexNumber result(){
            ComplexNumber cn = arr[0];
            for(int i=0; i<num; i++){
                if(operators[i] == '+'){ cn = cn + arr[i+1]; }
                else if(operators[i] == '-'){ cn = cn - arr[i+1]; }
                else if(operators[i] == '*'){ cn = cn * arr[i+1]; }
                else if(operators[i] == '/'){ cn = cn / arr[i+1]; }
                else if(operators[i] == '='){ break; }
            } return cn;
        }

        double sumModules(){ double sum=0; for(int i=0; i<num; i++){ sum+= arr[i].module(); } return sum; }
};

int main() {
	int testCase; double real, imaginary;
	ComplexNumber first, second, result; cin >> testCase;

	if (testCase <= 8) {
		cin >> real >> imaginary; first = ComplexNumber(real, imaginary);
		cin >> real >> imaginary; second = ComplexNumber(real, imaginary);
	}

	if (testCase == 1) {
		cout << "===== OPERATOR + =====" << endl;
		result = first + second; cout << result;
	}
	else if (testCase == 2) {
		cout << "===== OPERATOR - =====" << endl;
		result = first - second; cout << result;
	}
	else if (testCase == 3) {
		cout << "===== OPERATOR * =====" << endl;
		result = first * second; cout << result;
	}
	else if (testCase == 4) {
		cout << "===== OPERATOR / =====" << endl;
		result = first / second; cout << result;
	}
	else if (testCase == 5) {
		cout << "===== OPERATOR == =====" << endl << first << second;
		if (first == second) { cout << "EQUAL" << endl; }
		else{ cout << "NOT EQUAL" << endl; }
	}
	else if (testCase == 6) {
		cout << "===== OPERATOR > =====" << endl << first << second;
		if (first > second){ cout << "FIRST GREATER THAN SECOND" << endl; }
		else{ cout << "FIRST LESSER THAN SECOND" << endl; }
	}
	else if (testCase == 7) {
		cout << "===== OPERATOR < =====" << endl << first << second;
		if (first < second){ cout << "FIRST LESSER THAN SECOND" << endl; }
		else{ cout << "FIRST GREATER THAN SECOND" << endl; }
	}
	else if (testCase == 8) {
		cout << "===== MODULE =====" << endl;
		double module = first.module(); cout << first;
		cout << "Module: " << module << endl; cout << second;
		module = second.module(); cout << "Module: " << module << endl;
	}
	else if (testCase == 9) {
		cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
		Equation equation; cin >> equation; cout << equation.sumModules();
	}
	else if (testCase == 10) {
		cout << "===== EQUATION RESULT =====" << endl;
		Equation equation; cin >> equation; result = equation.result(); cout << result;
	}
	return 0;
}