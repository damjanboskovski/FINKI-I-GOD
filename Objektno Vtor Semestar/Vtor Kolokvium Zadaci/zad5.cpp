#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50
enum typeC{ standard, loyal, vip };
char type [][9] = {"standard", "loyal", "vip" };

class Customer{
    private:
        char name[MAX], email[MAX]; typeC customerType; int num{0}; static int discount, addDiscount;
    public:
        Customer(){}
        Customer(char *n, char *e, typeC ct, int num){ strcpy(this->name, n); strcpy(this->email,e); this->customerType = ct; this->num = num; }
        Customer(const Customer &other){
            if(this != &other){
                strcpy(this->name,other.name); strcpy(this->email,other.email); this->customerType = other.customerType; this->num = other.num;
            }
        }
        Customer &operator=(const Customer &other){
            if(this != &other){
                strcpy(this->name,other.name); strcpy(this->email,other.email); this->customerType = other.customerType; this->num = other.num;
            } return *this;
        }
        ~Customer(){}
        
        friend ostream &operator<<(ostream &out, const Customer &other){
            out<<other.name<<endl<<other.email<<endl<<other.num<<endl<<type[other.customerType]<<" ";
            if(other.customerType == 0){ out<<"0"; }
            else if(other.customerType == 1){ out<<discount; }
            else { out<<discount + addDiscount; }
            return out<<endl;
        }

        bool operator==(Customer &other){ return !strcmp(email,other.email); }
        static void setDiscount1(int n){ discount = n; } typeC getType()const{ return customerType; }
        int getNum()const{ return this->num; } void setType(typeC customerType){ Customer::customerType = customerType; }
};

class UserExistsException{
    public:
        static void message(){ cout<<"The user already exists in the list!"<<endl; }
};

class FINKI_bookstore{
    private:
        Customer **arr{nullptr}; int num{0};
    public:
        FINKI_bookstore(){ this->arr = new Customer *[num]; }
        FINKI_bookstore &operator+=(Customer &other){
            for(int i=0; i<num; i++){ if(*arr[i] == other){ throw UserExistsException(); } }
            auto temp = new Customer *[num + 1];
            for(int i=0; i<this->num; i++){ temp[i] = this->arr[i]; }
            temp[num++] = &other; delete[] arr; this->arr = temp; return *this;
        }

        friend ostream &operator<<(ostream &out, FINKI_bookstore &other){ for(int i=0; i<other.num; i++){ out<<*other.arr[i]; } return out; }
        void setCustomers(Customer *c, int n){
            this->num = n; delete[] arr; this->arr = new Customer *[n];
            for(int i=0; i<n; i++){ this->arr[i] = &c[i]; }
        }

        void update(){
            for(int i=0; i<num; i++){
                if(arr[i]->getType() == (typeC) 0 && arr[i]->getNum() > 5 ){ this->arr[i]->setType((typeC) 1); }
                else if(arr[i]->getType() == (typeC) 1 && arr[i]->getNum() > 10){ this->arr[i]->setType((typeC) 2); }
            }
        }
};

int Customer::discount = 10;
int Customer::addDiscount = 20;

int main()
{
    int testCase;
    cin >> testCase;

    char name[MAX], email[MAX];
    int tC, discount, numProducts;


    if (testCase == 1)
    {
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2)
    {
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3)
    {
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc << endl;
    }

    if (testCase == 4)
    {
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc += c;

        cout << fc;
    }

    if (testCase == 5)
    {
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;

        try
        {
            Customer c(name, email, (typeC) tC, numProducts);
            fc += c;
        }
        catch (UserExistsException)
        {
            UserExistsException::message();
        }

        cout << fc;
    }

    if (testCase == 6)
    {
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}
