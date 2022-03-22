#include <iostream>
#include <cstring>
using namespace std;

class StockRecord{
    private:
        char id[12] = {'\0'}, company[50] = {'\0'};
        double price = 0.00,currentPrice = 0.00; int stocks = 0;
    public:
        StockRecord(){};
        StockRecord(char *i, char *c,double p, int s){strcpy(id,i); strcpy(company,c); price = p; stocks = s;}
        ~StockRecord(){};

        StockRecord &operator=(const StockRecord &other){ 
            strcpy(id, other.id); strcpy(company,other.company); price = other.price; stocks = other.stocks; currentPrice = other.currentPrice; 
        }

        friend ostream &operator<<(ostream &out, const StockRecord &other){ 
            out<<other.company<<" "<<other.stocks<<" "<<other.price<<" "<<other.currentPrice<<" "<<other.profit()<<endl; return out; 
        }

        double getPrice(){return price;} double getCurrentPrice(){return currentPrice;}
        int getStocks(){return stocks;} void setNewPrice(double c){currentPrice = c;}
        double value(){return stocks * currentPrice;} double profit()const{return stocks * (currentPrice - price);}
        char *getCompany(){return company;}      
};

class Client{
    private:
        char name[60] = {'\0'}; int id = 0,num=0; StockRecord *companies;
    public:
        Client(){}; 
        Client(char *n,int id1){strcpy(name,n);id=id1;num=0;companies = new StockRecord[50];} 
        ~Client(){};

        Client operator+=(StockRecord &other){companies[num]=other; num++;}
        friend ostream &operator<<(ostream &out, Client &other){
            out << other.id << " " << other.totalValue() << endl;
            for(int i=0;i<other.num;i++){ 
                out << other.companies[i].getCompany()<<" "<<other.companies[i].getStocks()
                <<" "<<other.companies[i].getPrice()<<" "<<other.companies[i].getCurrentPrice()<<" "<<other.companies[i].profit() <<endl; } 
            return out;
        }
        
        double totalValue(){double sum=0; for(int i=0;i<num;i++){sum+=companies[i].value();} return sum;}
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