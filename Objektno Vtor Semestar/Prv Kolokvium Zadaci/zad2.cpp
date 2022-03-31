#include <iostream>
using namespace std;

class List{
    private:
       int *arr{nullptr},num{0};
    public:
        List(){ this->arr = nullptr; this->num = 0;}
        List(int *a, int n) : List(){
            this->arr = new int[n]; this->num = n;
            for(int i=0; i<this->num; i++){ this->arr[i] = a[i];}
        }

        List(const List &other){
            if(this != &other){
                this->arr = new int[other.num]; this->num = other.num;
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; } }
        }

        List &operator=(const List &other){
            if(this != &other){
                this->arr = new int[other.num]; this->num = other.num;
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i];}
            } return *this;
        }

        ~List(){ delete[] this->arr; this->arr = nullptr;}

        void pecati(){
            cout<<this->num<<": "; for(int i=0; i<this->num; i++){ cout<<arr[i]<<" ";}
            cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
        }

        int sum(){ int sum=0; for(int i=0; i<this->num; i++){ sum += arr[i]; } return sum;}
        double average(){ return (double) sum()/this->num; } int getNum(){ return this->num;}
};

class ListContainer{
    private:
        List *arr{nullptr}; int num{0}, tries{0};
    public:
        ListContainer(){ arr = nullptr; }

        ListContainer(const ListContainer &other):ListContainer(){
            if(this != &other){
                delete[] this->arr; this->arr = new List[other.num];
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
                this->num = other.num; this->tries = other.tries; }
        }

        ListContainer &operator=(const ListContainer &other){
            if(this != &other){
                delete[] this->arr; this->arr = new List[other.num];
                for(int i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
                this->num = other.num; this->tries = other.tries;
            } return *this;
        }

        ~ListContainer(){ delete[] this->arr; arr = nullptr;}

        void addNewList(List l){ tries++;
            for(int i=0; i<this->num;i++){ if(arr[i].sum() == l.sum()){ return; } }
            List *temp = new List[this->num+1]; for(int i=0; i<this->num;i++){ if(arr[i].sum() != l.sum()){ temp[i] = arr[i]; } }
            temp[num++] = l; delete[] this->arr; this->arr = temp;
        }

        int sum(){int sum=0; for(int i=0; i<this->num; i++){ sum+=arr[i].sum();} return sum;}
        double average(){int sum1=0; for(int i=0; i<this->num; i++){ sum1+= arr[i].getNum(); } return (double) sum()/sum1;}

        void print(){
            if(this->num == 0){ cout<<"The list is empty"<<endl; }
            else{ for(int i=0; i<this->num; i++){ cout<<"List number: "<<i+1<<" List info: "; arr[i].pecati();}
            cout<<"Sum: "<<sum()<<" Average: "<<average()<<"\nSuccessful attempts: "<<this->num<<" Failed attempts: "<<tries-num<<endl; }
        }
};

int main() {

	ListContainer lc; int N; cin>>N;

	for (int i=0;i<N;i++) {
		int n, niza[100]; cin>>n;
		for (int j=0;j<n;j++){ cin>>niza[j]; }
		List l=List(niza,n);lc.addNewList(l);
	}
	 int testCase; cin>>testCase;
    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1; lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;  lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum(); lc1.average();
    }
    else { lc.print();}
}
