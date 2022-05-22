#include <iostream>
#include <cstring>
using namespace std;

class ArithmeticException{
    public: void message(){ cout<<"Division by zero is not allowed"<<endl; }
};

class NumbersNotDivisibleException{
    public: void message(int n){ cout<<"Division by "<<n<<" is not supported"<<endl; }
};

class ArrayFullException{
    public: void message(){ cout<<"The array is full. Increase the capacity"<<endl; }
};

class IndexOutOfBoundsException{
    public: void message(int n){ cout<<"Index "<<n<<" is out of bounds"<<endl; }
};

class NumberIsNotPositiveException{
    protected:
        bool isTrue{false};
    public:
        void message(int n){ cout<<"Number "<<n<<" is not positive integer"<<endl; }
};

class PositiveIntegers : public NumberIsNotPositiveException{
    private:
        int *arr{nullptr}, num{0}, capacity{0};
    public:
        PositiveIntegers(){}
        PositiveIntegers(int c){ this->capacity = c; }
        PositiveIntegers(const PositiveIntegers &other){
            if(this != &other){
                delete[] this->arr; this-> arr = new int[other.num];
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
                this->num = other.num; this->capacity = other.capacity;
            }
        }
        PositiveIntegers &operator=(const PositiveIntegers &other){
            if(this != &other){
                delete[] this->arr; this-> arr = new int[other.num];
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
                this->num = other.num; this->capacity = other.capacity;
            } return *this;
        }
        ~PositiveIntegers(){ delete[] this->arr; this->arr = nullptr; }

        PositiveIntegers &operator+=(int number){
            try{
                if(this->num + 1 <= this->capacity){
                    try{
                        if(number > 0){
                            int *temp = new int[this->num+1];
                            for(int i=0; i<this->num; i++){ temp[i] = this->arr[i]; }
                            temp[this->num++] = number; delete[] this->arr; this->arr = temp;
                        }
                        else{ throw(number); }
                    }
                    catch(int num){ NumberIsNotPositiveException error; error.message(number); }
                }
                else{ throw(0); }
            }
            catch(int num){ ArrayFullException error; error.message(); } return *this;
        }
        PositiveIntegers operator*(int number){
            PositiveIntegers temp(capacity); for(int i=0; i<this->num; i++){ temp += this->arr[i] * number; } return temp;
        }
        PositiveIntegers operator/(int number){
            PositiveIntegers temp(capacity); bool check = false;
            try{
                if(number != 0){
                    for(int i=0; i<this->num; i++){
                        if((this->arr[i] % number) == 0){ temp += this->arr[i] / number; }
                        else { check =  true; }
                    }
                }
                else{ throw(number); }
            }
            catch(int n){ ArithmeticException error; error.message(); }
            if(check == true){ NumbersNotDivisibleException error; error.message(number); temp.num = 0; }
            return temp;
        }
        int operator[](int number){
            try{
                if(number < this->num && number >= 0){ this->isTrue = false; return this->arr[number]; }
                else{ throw(number); }
            }
            catch(int n){ IndexOutOfBoundsException error; error.message(n); this->isTrue = true; return int(); }
        }
        void increaseCapacity(int c){ this->capacity += c; }
        void print(){
            if(this->num != 0){
                cout<<"Size: "<<this->num<<" Capacity: "<<this->capacity<<" Numbers: ";
                for(int i=0; i<this->num; i++){ cout<<arr[i]<<" "; } cout<<endl;
            }
        }
        bool getCheck(){ return this->isTrue; }
};

int main() {
	
	int n,capacity; cin >> n >> capacity; PositiveIntegers pi (capacity);

	for (int i=0;i<n;i++){ int number; cin>>number; pi+=number; }

	cout<<"===FIRST ATTEMPT TO ADD NUMBERS==="<<endl;
	pi.print(); int incCapacity; cin>>incCapacity; pi.increaseCapacity(incCapacity);

	cout<<"===INCREASING CAPACITY==="<<endl;
	pi.print(); int n1; cin>>n1; for (int i=0;i<n1;i++){ int number; cin>>number; pi+=number; }

	cout<<"===SECOND ATTEMPT TO ADD NUMBERS==="<<endl;	
    pi.print();	PositiveIntegers pi1;
	
	cout<<"===TESTING DIVISION==="<<endl;	
	pi1 = pi/0; pi1.print(); pi1 = pi/1; pi1.print(); pi1 = pi/2; pi1.print();
	
	cout<<"===TESTING MULTIPLICATION==="<<endl;
	pi1 = pi*3; pi1.print();
	
	cout<<"===TESTING [] ==="<<endl;	
	cout<<"PositiveIntegers[-1] = "; pi[-1]; if(pi.getCheck() == false){ cout<<pi[-1]<<endl; }	
	cout<<"PositiveIntegers[2] = ";  pi[2];  if(pi.getCheck() == false){ cout<<pi[2]<<endl;  }	
	cout<<"PositiveIntegers[3] = ";  pi[3];	 if(pi.getCheck() == false){ cout<<pi[3]<<endl;  }	
	cout<<"PositiveIntegers[12] = "; pi[12]; if(pi.getCheck() == false){ cout<<pi[12]<<endl; }	
	
	return 0;
}