#include <iostream>
#include <cstring>
using namespace std;

class Category{
    private:
        char name[20];
    public:
        Category(){strcpy(name,"unnamed");}
        Category(char *n){strcpy(name,n);}
        ~Category(){};

        void print(){cout<<"Category: "<<name<<endl;}
};

class NewsArticle{
    private:
        Category c; char title[30] = "untitled";
    public:
        NewsArticle(){};
        NewsArticle(Category c1, char *t = "untitled"){c = c1; strcpy(title,t);}
        ~NewsArticle(){};

        void print(){cout<<"Article title: "<<title<<endl; c.print();}
};

class FrontPage{
    private:
        NewsArticle n; float price = 0; int editorNumber = 0;
    public:
        FrontPage(){};
        FrontPage(NewsArticle n1, float p = 0, int n = 0){this->n = n1; price = p; editorNumber = n;}
        ~FrontPage(){};
        void print(){
            cout<<"Price: "<<price<<", Edition number: "<<editorNumber<<endl; n.print();
        }
};

int main() {
	char categoryName[20], articleTitle[30];
	float price; int editionNumber, testCase;
	cin >> testCase;

	if (testCase == 1) {
		int iter; cin >> iter;
		while (iter > 0) {
			cin >> categoryName >> articleTitle >> price >> editionNumber;
			Category category(categoryName);
			NewsArticle article(category, articleTitle);
			FrontPage frontPage(article, price, editionNumber);
			frontPage.print();
			iter--;
		}
	}

	else if (testCase == 2) {
		cin >> categoryName >> price >> editionNumber;
		Category category(categoryName);
		NewsArticle article(category);
		FrontPage frontPage(article, price, editionNumber);
		frontPage.print();
	}

	else if (testCase == 3) {
		cin >> categoryName >> articleTitle >> price;
		Category category(categoryName);
		NewsArticle article(category, articleTitle);
		FrontPage frontPage(article, price);
		frontPage.print();
	}

    else { FrontPage frontPage = FrontPage(); frontPage.print();}

	return 0;
}