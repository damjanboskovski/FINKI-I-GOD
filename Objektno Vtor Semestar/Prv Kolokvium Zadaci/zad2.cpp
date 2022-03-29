#include <iostream>
using namespace std;

class List{
    private: int *arr; int num;
    public:
        List(){arr = nullptr; num=0;}
        List(int *a1,int n1) {
            arr = new int[n1]; this->num = n1;
            for(int i=0;i<n1;i++) {this->arr[i] = a1[i];}
        }
        ~List(){}

        List &operator=(const List &other){
            this->arr = new int[other.num];this->num = other.num;
            for(int i=0;i<other.num;i++){arr[i]=other.arr[i];} return *this;
        }

        void pecati(){
            cout<<num<<": ";
            for(int i=0;i<num;i++){ cout<<arr[i]<<" "; }
            cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
        }

        int sum(){int sum1=0; for(int i=0;i<num;i++){sum1+=arr[i];}return sum1;}
        double average(){return (double)sum()/num;} int getNum()const{return num;}
};

class ListContainer{
    private: List *array; int num=0,tries=0;
    public:
        ListContainer(){ array = nullptr; }

        ListContainer (const ListContainer &other){
            if(this != &other){
                delete[] array; array = new List[num];
                for(int i=0;i<other.num;i++){array[i]=other.array[i];}
                num = other.num; tries = other.tries;
            }
        }

        ListContainer &operator=(const ListContainer &other){
            if(this != &other){
                delete[] array; array = new List[num];
                for(int i=0;i<other.num;i++){array[i]=other.array[i];}
                num = other.num; tries = other.tries;
            } return *this;
        }

        ~ListContainer(){if(this->array != nullptr){ array = nullptr; delete[] array;}};

        void print(){
            if(num == 0){cout << "The list is empty" << endl;}
            else{
                for(int i=0;i<num;i++){ cout<<"List number: "<<i+1<<" List info: "; array[i].pecati(); }
            cout << "Sum: "<<sum()<<" Average: "<<average()<<endl << "Successful attempts: "<<num<<" Failed attempts: "<<tries-num<<endl;
            }
        }

        void addNewList(List array1){ tries++;
            for(int i=0;i<num;i++){ if(array[i].sum()==array1.sum()){ return;} }
            List *temp = new List[num+1]; for(int i = 0;i<num;i++){if(array[i].sum()!=array1.sum()){ temp[i]=array[i];}}
            temp[num++] = array1; delete[] this->array; this->array = temp; 
        }

        int sum(){ int sum1=0; for(int i=0;i<num;i++){sum1+=array[i].sum();}return sum1; }
        double average(){ int sum2=0; for(int i=0;i<num;i++){sum2+=array[i].getNum();} return (double) sum()/sum2; }

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