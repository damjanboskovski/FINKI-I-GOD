#include <iostream>
#include <cstring>
using namespace std;

enum Extension{ pdf, txt, exe }; char extConv[3][4] = {"pdf","txt","exe"};

class File{
    private:
        char *fileName{nullptr}, *ownerName; Extension ext{(Extension)0}; int fileSize{0};
    public:
        File(){ this->fileName = nullptr; this->ownerName = nullptr; }
        File(char *n, char *o, int f, Extension e){
            this->fileName = new char[strlen(n)+1]; strcpy(this->fileName,n);
            this->ownerName = new char[strlen(o)+1]; strcpy(this->ownerName,o);
            this->fileSize = f; this->ext = e;
        }
        File(const File &other){
            if(this != &other){
                this->fileName = new char[strlen(other.fileName)+1]; strcpy(this->fileName,other.fileName);
                this->ownerName = new char[strlen(other.ownerName)+1]; strcpy(this->ownerName,other.ownerName);
                this->fileSize = other.fileSize; this->ext = other.ext;
            }
        }
        File &operator=(const File &other){
            if(this != &other){
                delete[] this->fileName; this->fileName = new char[strlen(other.fileName)+1]; strcpy(this->fileName,other.fileName);
                delete[] this->ownerName; this->ownerName = new char[strlen(other.ownerName)+1]; strcpy(this->ownerName,other.ownerName);
                this->fileSize = other.fileSize; this->ext = other.ext;
            } return *this;
        }
        ~File(){ delete[] this->fileName; this->fileName = nullptr; delete[] this->ownerName; this->ownerName = nullptr; }

        void print(){ cout<<"File name: "<<this->fileName<<"."<<extConv[this->ext]<<endl<<"File owner: "<<this->ownerName<<endl<<"File size: "<<this->fileSize<<endl; }

        bool equals(const File &other){
            if ( (strcmp(this->fileName,other.fileName)==0) && (strcmp(this->ownerName,other.ownerName)==0) && (this->ext == other.ext)){ return true; }
            else return false;
        }

        bool equalsType(const File &other){
            if ( (strcmp(this->fileName,other.fileName)==0) && (this->ext == other.ext) ) { return true; }
            else return false;
        }
};

class Folder{
    private:
        char *folderName{nullptr}; int num{0}; File *arr{nullptr};
    public:
        Folder(){ this->folderName = nullptr; this->arr = nullptr; }
        Folder(const char *name){
            delete[] this->folderName; this->folderName = new char[strlen(name)+1]; strcpy(this->folderName,name);
            this->arr = new File[this->num];
        }
        ~Folder(){ delete[] this->folderName; this->folderName = nullptr; delete[] this->arr; this->arr = nullptr; }

        void print(){ cout<<"Folder name: "<<this->folderName<<endl; for(int i=0; i<this->num; i++){ this->arr[i].print(); } }

        void add(const File &other){
            File *temp = new File[this->num+1];
            for(int i=0; i<this->num; i++){ temp[i] = this->arr[i]; }
            temp[num++] = other; delete[] this->arr; this->arr = temp;
        }

        void remove(const File &other){
            for(int i=0; this->num; i++){ if(this->arr[i].equals(other)){ --this->num;
                for(int j=i; j<this->num; j++){ this->arr[j] = this->arr[j+1]; } break; } }
        }
};

int main() {
	char fileName[20],  fileOwner[20];
	int ext, fileSize, testCase;cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName >> fileOwner >> fileSize >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created); File assigned = created;

		cout << "======= CREATED =======" << endl; created.print(); cout << endl;
        cout << "======= COPIED =======" << endl; copied.print(); cout << endl;
        cout << "======= ASSIGNED =======" << endl; assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName >> fileOwner >> fileSize >> ext;
		File first(fileName, fileOwner, fileSize, (Extension) ext); first.print();

		cin >> fileName >> fileOwner >> fileSize >> ext;
		File second(fileName, fileOwner, fileSize, (Extension) ext);second.print();

		cin >> fileName >> fileOwner >> fileSize >> ext;
		File third(fileName, fileOwner, fileSize, (Extension) ext); third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals) {cout << "TRUE" << endl;}
		else {cout << "FALSE" << endl;}

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals) {cout << "TRUE" << endl;}
		else {cout << "FALSE" << endl;}

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType) {cout << "TRUE" << endl;}
		else {cout << "FALSE" << endl;}

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType) {cout << "TRUE" << endl;}
		else {cout << "FALSE" << endl;}

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName; Folder folder(fileName);folder.print();
	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20]; cin >> name; Folder folder(name);
		int iter; cin >> iter;

		while (iter > 0) {
			cin >> fileName >> fileOwner >> fileSize >> ext;
			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20]; cin >> name; Folder folder(name);
		int iter;cin >> iter;

		while (iter > 0) {
			cin >> fileName >> fileOwner >> fileSize >> ext;
			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file); iter--;
		}
		cin >> fileName >> fileOwner >> fileSize >> ext;
		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file); folder.print();
	}
	return 0;
}