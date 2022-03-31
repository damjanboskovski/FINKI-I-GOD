#include<iostream>
#include<cstring>
using namespace std;

class StockRecord{
    private:
        char id[12],name[50]; double buyPrice{0.00}, currentPrice{0.00}; int stockNum{0};
    public:
        StockRecord(){};
        StockRecord(char *i, char *n, double p, int s) { strcpy(this->id,i); strcpy(this->name,n); this->buyPrice = p; this->stockNum = s; }
        ~StockRecord(){};

        friend ostream &operator<<(ostream &out, StockRecord &other){
            out<<other.name<<" "<<other.stockNum<<" "<<other.buyPrice<<" "<<other.currentPrice<<" "<<other.profit()<<endl;return out;}

        void setNewPrice(double c){ this->currentPrice = c; }
        double value(){ return this->stockNum * currentPrice; } double profit()const{ return this->stockNum * (this->currentPrice - this->buyPrice); }
};

class Client{
    private:
        char clientName[60]; int id{0}, num{0}; StockRecord *arr{nullptr};
    public:
        Client(){};
        Client(char *n, int i) { strcpy(this->clientName,n); this->id = i; }

        Client &operator+=(const StockRecord &other)
        {
            StockRecord *temp = new StockRecord[this->num+1];
            for(int i=0; i<this->num; i++){ temp[i] = arr[i]; }
            temp[num++] = other; delete[] this->arr; arr = temp;
        }

        friend ostream &operator<<(ostream &out, Client &other){
            out<<other.id<<" "<<other.totalValue()<<endl;
            for(int i=0; i<other.num; i++) { out<<other.arr[i]; } return out; }

        ~Client(){ delete[] this->arr; arr = nullptr; }

        double totalValue(){ double sum=0.00; for(int i=0; i<this->num; i++){ sum+=arr[i].value(); } return sum; }
};

int main(){
    int test; cin >> test;

    if(test == 1){
    	double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl; cin >> price;
        sr.setNewPrice(price); cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
    	char id[12], company[50]; double price, newPrice; int n, shares; cin >> n;
        for(int i = 0; i < n; ++i){
        	cin>>id>>company>>price>>newPrice>>shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout<<sr.value()<<endl<< sr;
        }
    }
    else if(test == 3){
    	cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares; double oldPrice, newPrice; bool flag = true;
        cin>>clientName>>clientID>>n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID>>companyName>>oldPrice>>newPrice>>shares;
        	StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);c += sr;
            if(flag){cout << "Operator += OK" << endl;flag = false;}
        }
        cout<<c<<"Operator << OK"<<endl;
    }
    return 0;
}
