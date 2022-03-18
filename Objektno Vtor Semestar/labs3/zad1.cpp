#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char name[20],lastName[20];
    public:
        Person(){strcpy(name,"not specified"); strcpy(lastName,"not specified");}
        Person(char *n, char *l){strcpy(name,n); strcpy(lastName,l);}
        ~Person(){};
        
        void print() const {cout<<name<<" "<<lastName<<endl;}
};

class Date{
    private:
        int year, month, day;
    public:
        Date(){year = 0; month = 0; day = 0;}
        Date(int y, int m, int d){year = y; month = m; day = d;}
        ~Date(){};
        
        void print() const {cout<<year<<"."<<month<<"."<<day<<endl;}
};

class Car{
    private:
        Person p; Date d; float price;
    public:
        Car(){price = 0;}
        Car(Person p1, Date d1, float pr){p = p1; d = d1; price = pr;}
        ~Car(){};

        void print(){ p.print(); d.print(); cout<<"Price: "<<price<<endl; }

        float getPrice() const {return price;}
};

void cheaperThan(Car *car, int carNum, float price){
    for(int i=0;i<carNum;i++){
        if(car[i].getPrice()<price){ car[i].print(); }
    }
}

int main() {
	char name[20], lastName[20];
	int year, month, day, testCase; float price;
	cin >> testCase;

	if (testCase == 1) {
		cin >> name >> lastName; Person lik(name, lastName);
		cin >> year >> month >> day; Date date(year, month, day);
		cin >> price; Car car(lik, date, price);
		car.print();
	}

	else if (testCase == 2) {
		cin >> name >> lastName; Person lik(name, lastName);
		cin >> year >> month >> day; Date date(Date(year, month, day));
		cin >> price; Car car(lik, date,  price);
		car.print();
	}

	else {
		int numCars; cin >> numCars;
		Car cars[10];

		for (int i = 0; i < numCars; i++) {
			cin >> name >> lastName; Person lik(name, lastName);
			cin >> year >> month >> day; Date date(year, month, day);
			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperThan(cars, numCars, priceLimit);
	}
	return 0;
}