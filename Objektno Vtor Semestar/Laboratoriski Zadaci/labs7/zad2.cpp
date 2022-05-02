#include<iostream>
using namespace std;

class Number {
    public:
        virtual double doubleValue() = 0;
        virtual int intValue() = 0;
        virtual void print() = 0;
        Number(){}
        bool operator==(Number &other){
            return doubleValue() == other.doubleValue() && intValue() == other.intValue();
        }
}; 

class Integer : public Number { 
    private:
        int num;
    public:
        Integer(int n) : Number(){ this->num = n; }
        double doubleValue() { return (double) num; }
        int intValue(){ return (int)num; }
        void print(){ cout<<"Integer: "<<num<<endl; }
};

class Double : public Number {
    private:
        double num;
    public:
        Double(double n): Number(){ this->num = n; }
        double doubleValue(){ return (double)num; }
        int intValue(){ return (int)num; }
        void print(){ cout<<"Double: "<<num<<endl; }
};

class Numbers{
    private:
        Number **num; int n{0};
    public:
        Numbers(){ num = new Number *[n]; }
        ~Numbers(){ delete[] num; }
        Numbers &operator+=(Number *other){
            for(int i=0; i<n; i++){ if(*num[i] == *other){ return *this; } }
            Number **temp = new Number*[n+1]; for(int i=0; i<n; i++){ temp[i] = num[i]; }
            temp[n] = other; delete[] num; num = temp; n++; return *this;
        }

        void statistics(){
            cout<<"Count of numbers: "<<n<<endl; double sum=0;
            for(int i=0; i<n; i++){ sum+=num[i]->doubleValue(); }
            cout<<"Sum of all numbers: "<<sum<<endl;

            int sum2=0,sum3=0,sum4=0; double sum5=0;
            for(int i=0; i<n; i++){
                if(dynamic_cast<Integer*>(num[i])){ sum2++; sum3+= num[i]->intValue(); }
                else if(dynamic_cast<Double*>(num[i])){sum4++; sum5+=num[i]->doubleValue(); }
            }
            cout<<"Count of integer numbers: "<<sum2<<endl;
            cout<<"Sum of integer numbers: "<<sum3<<endl;
            cout<<"Count of double numbers: "<<sum4<<endl;
            cout<<"Sum of double numbers: "<<sum5<<endl;
        }

        void integersLessThan(Integer integer){
            bool isTrue = false;
            for(int i=0; i<n; i++){
                if(dynamic_cast<Integer*>(num[i]) && num[i]->intValue() < integer.intValue()){ num[i]->print(); isTrue = true; }
            }
            if(!isTrue){ cout<<"None"<<endl; } 
        }

        void doublesBiggerThan(Double doubles){
            bool isTrue = false;
            for(int i=0; i<n; i++){
                if(dynamic_cast<Double*>(num[i]) && num[i]->doubleValue() > doubles.doubleValue()){ num[i]->print(); isTrue = true; }
            }
            if(!isTrue){ cout<<"None"<<endl; }
        }
};

int main() {
	int n; cin>>n; Numbers numbers;

	for (int i=0;i<n;i++){
		int type; double number; cin>>type>>number;
		if (type==0){
			Integer * integer = new Integer((int) number); numbers+=integer;
		}
		else {
			Double * doublee = new Double(number); numbers+=doublee;
		}
	}
	
	int lessThan; cin>>lessThan; double biggerThan; cin>>biggerThan;
	cout<<"STATISTICS FOR THE NUMBERS\n"; numbers.statistics();
	cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl; numbers.integersLessThan(Integer(lessThan));
	cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl; numbers.doublesBiggerThan(Double(biggerThan));
	return 0;
}