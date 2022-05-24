#include <iostream>
#include <cstring>
using namespace std;

class Book{
    protected:
        char ISBN[20], bookTitle[50], author[30]; double price{0};
    public:
        Book(){}
        Book(char *i, char *b, char *a, double p){ strcpy(this->ISBN,i); strcpy(this->bookTitle,b); strcpy(this->author,a); this->price = p; }
        Book(const Book &other){
			if(this != &other){
             	strcpy(this->ISBN,other.ISBN); strcpy(this->bookTitle,other.bookTitle); strcpy(this->author,other.author); this->price = other.price;
			}
		}
		Book &operator=(const Book &other){
			if(this != &other){
             	strcpy(this->ISBN,other.ISBN); strcpy(this->bookTitle,other.bookTitle); strcpy(this->author,other.author); this->price = other.price;
			} return *this;
		}
		~Book(){}
		friend ostream &operator<<(ostream &out, Book &other){ out<<other.ISBN<<": "<<other.bookTitle<<", "<<other.author<<" "<<other.bookPrice()<<endl; return out; }
        virtual double bookPrice() = 0; void setISBN(char *isbn){ strcpy(this->ISBN,isbn); }
};

class OnlineBook : public Book{
    private:
        char *url{nullptr}; int size{0}; 
    public:
        OnlineBook(){}
		OnlineBook(char *i, char *b, char *a, double p, char *u, int s):Book(i,b,a,p){ this->url = new char[strlen(u)+1]; strcpy(this->url,u); this->size = s; }
		OnlineBook(OnlineBook &other):Book(other.ISBN, other.bookTitle, other.author, other.price){ 
			if(this != &other){  
				this->url = new char[strlen(other.url)+1]; strcpy(this->url,other.url); this->size = other.size;
			} 
		}
		OnlineBook &operator=(const OnlineBook &other){ 
			if(this != &other){  
				strcpy(this->ISBN,other.ISBN); strcpy(this->bookTitle,other.bookTitle); strcpy(this->author,other.author); this->price = other.price; 
				this->url = new char[strlen(other.url)+1]; (this->url,other.url); this->size = other.size;
			} return *this;
		}
		~OnlineBook(){ delete[] this->url; this->url = nullptr; }
		double bookPrice(){ return this->size > 20?1.2 * price:price; }
};

class PrintBook : public Book{
	private:
		double weight{0}; bool isInStock{false};
	public:
		PrintBook(){}
		PrintBook(char *i, char *b, char *a, double p, double w, bool s) : Book(i,b,a,p) { this->weight = w; this->isInStock = s; }
		PrintBook(PrintBook &other):Book(other.ISBN, other.bookTitle, other.author, other.price){ this->weight = other.weight; this->isInStock = other.isInStock; }
		PrintBook &operator=(const PrintBook &other){
			if(this != &other){
				strcpy(this->ISBN,other.ISBN); strcpy(this->bookTitle,other.bookTitle); strcpy(this->author,other.author); this->price = other.price; this->weight = other.weight; this->isInStock = other.isInStock;
			} return *this;
		}
		~PrintBook(){}
		double bookPrice(){ return this->weight > 0.7?1.15 * price:price; }
};

bool operator>(Book &b1, Book &b2){ return (b1.bookPrice() > b2.bookPrice()); }

void mostExpensiveBook(Book **books, int n){
	int onlineCnt=0, printCnt=0, pos=0; float max = books[0]->bookPrice();

	for(int i=0; i<n; i++){
		if(dynamic_cast<OnlineBook*>(books[i])){ onlineCnt++; }
		else if(dynamic_cast<PrintBook*>(books[i])){ printCnt++; }
	}
	for(int i=0; i<n; i++){ max<books[i]->bookPrice()?max = books[i]->bookPrice(), pos = i: 0; }

	cout<<"FINKI-Education"<<endl;
    cout<<"Total number of online books: "<<onlineCnt<<endl<<"Total number of print books: "<<printCnt<<endl;
    cout<<"The most expensive book is: "<<endl<<*books[pos]<<endl;
}

int main(){

	char isbn[20], title[50], author[30], url[100]; int size, tip, n, testCase;; float price, weight; bool inStock; Book  **books; cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl; cin >> n; books = new Book *[n];
		for (int i = 0; i < n; i++){
			cin >> isbn; cin.get(); cin.getline(title, 50); cin.getline(author, 30); cin >> price >> url  >> size;
			cout << "CONSTRUCTOR" << endl; books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl; cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;

		if (*books[0] > *books[1]) { cout << *books[0]; }
		else { cout << *books[1]; }
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn; cin.get(); cin.getline(title, 50); cin.getline(author, 30); cin >> price >> url >> size;
		cout << "CONSTRUCTOR" << endl; OnlineBook ob1(isbn, title, author, price, url, size); cout << ob1 << endl;

		cout << "COPY CONSTRUCTOR" << endl; OnlineBook ob2(ob1);
		cin >> isbn; ob2.setISBN(isbn); cout << ob1 << endl; cout << ob2 << endl;

		cout << "OPERATOR =" << endl;
		ob1 = ob2; cin >> isbn; ob2.setISBN(isbn); cout << ob1 << endl  << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl; cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn; cin.get(); cin.getline(title, 50); cin.getline(author, 30); cin >> price >> weight >> inStock;
			cout << "CONSTRUCTOR" << endl; books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl << *books[i];
		}
		cout << "OPERATOR >" << endl << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1]){ cout << *books[0]; }
		else { cout << *books[1]; }
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl; cin >> n; books = new Book *[n];

		for (int i = 0; i<n; i++){
			cin >> tip >> isbn; cin.get(); cin.getline(title, 50); cin.getline(author, 30); cin >> price;
			if (tip == 1) { cin >> url >> size; books[i] = new OnlineBook(isbn, title, author, price, url, size); }
			else { cin >> weight >> inStock; books[i] = new PrintBook(isbn, title, author, price, weight, inStock); }
		}
		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) { delete books[i]; } delete[] books; return 0;
}
