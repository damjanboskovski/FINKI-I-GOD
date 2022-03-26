#include <iostream>
using namespace std;

class List{
    private: 
        int *arr{nullptr}, num{0};
    public:
        List(){ this->arr = nullptr; this->num=0; }
        List(int *a1,int n1) : List() {
            this->arr = new int[n1]; this->num = n1;
            for(int i=0;i<num;i++) { this->arr[i] = a1[i]; }
        }
        List(const List &other) : List(){
            if(this != &other){
                this->num = other.num; delete[] arr;this->arr = new int[this->num];
                for(int i=0;i<num;i++){this->arr[i]=other.arr[i];} }
        }
        List &operator=(const List &other){
            if(this != &other){
                this->num = other.num; delete[] arr; this->arr = new int[this->num]; 
                for(int i = 0; i < num; i++){ this->arr[i]=other.arr[i]; } return *this;}
        }
        ~List(){ delete[] arr; arr = nullptr; }

        void pecati(){
            cout<<" List info: "<<num<<": ";
            for(int i=0;i<this->num;i++){ cout<<this->arr[i]<<" "; }
            cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
        }

        int sum(){int sum=0; for(int i = 0; i < num; i++){ sum+=this->arr[i]; } return sum; }
        double average(){return (double)sum()/num;} int getNum(){return num;}
};

class ListContainer{
    private: List *array{nullptr}; int num{0}, tries{0};
    public:
        ListContainer(){ this->array = nullptr; this->num = 0; this->tries = 0;}
        ListContainer(List *array1, int n1) : ListContainer(){
            this->array = new List[n1]; this->num=n1;
            for(int i=0;i<num;i++){ this->array[i] = array1[i]; }
        }
        ListContainer(const ListContainer &other) : ListContainer(){
            if(this != &other){
                this->num=other.num; this->tries = other.tries;
                delete[] array; array = new List[num]; 
                for(int i=0;i<num;i++){ this->array[i] = other.array[i];}}
        }
        ListContainer &operator=(const ListContainer &other){
            if(this != &other){
                this->num = other.num; this->tries = other.tries;
                delete[] array; array = new List[num];
                for(int i=0;i<num;i++){this->array[i]=other.array[i];} } return *this;
        }
        ~ListContainer(){ delete[] array; array = nullptr;};  

        void addNewList(List &l){
            List *temp = new List[num+1];
            for(int i=0;i<num;i++){
                if(l.sum() == this->array[i].sum()){tries++; return;}
                temp[i] = this->array[i];
            }
            temp[num++] = l; delete[] this->array; this->array = temp;
        }

        int sum(){ int sum1=0; for(int i=0;i<num;i++){sum1+=array[i].sum();}return sum1; }
        double average(){ 
            double avg=0.00; int sum=0; 
            for(int i = 0; i < num; i++)
            {
                sum += this->array[i].getNum(); avg += this->array[i].sum();
            } 
            return avg/sum; 
        }

        void print(){
            if(!this->num){cout << "The list is empty" << endl;}
            else{
                for(int i=0;i<num;i++){ cout<<"List number: "<<i+1; array[i].pecati(); }
            cout << "Sum: "<<sum()<<" Average: "<<average()<<endl << "Successful attempts: "<<num<<" Failed attempts: "<<tries<<endl;
            }
        }
};

int main() {
	
	ListContainer lc;
	int N;	
	cin>>N;	
    
	for (int i=0;i<N;i++) {
		int n;
		int niza[100];
		
		cin>>n;
       
		for (int j=0;j<n;j++){
			cin>>niza[j];
            
		}
       
		List l=List(niza,n);
	
		lc.addNewList(l);
	}	
	
    
    int testCase;
    cin>>testCase;
    
    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();
        
    }
    else {
        lc.print();
    }
}