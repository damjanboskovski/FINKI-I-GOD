#include<string.h>
#include<iostream>

using namespace std;

class User {
    char *username;
    char *companyName;
    int position;

    void copy(const User &u) {
        this->username = new char[strlen(u.username) + 1];
        strcpy(this->username, u.username);
        this->companyName = new char[strlen(u.companyName) + 1];
        strcpy(this->companyName, u.companyName);
        this->position = u.position;
    }

public:
    User(char *username = "", char *companyName = "", int position = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
        this->position = position;
    }

    User(const User &u) {
        copy(u);
    }

    User &operator=(const User &u) {
        if (this != &u) {
            delete[] username;
            delete[] companyName;
            copy(u);
        }
        return *this;
    }

    ~User() {
        delete[] username;
        delete[] companyName;
    }

    char *getUsername() const {
        return username;
    }

    void setUsername(char *username) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
    }

    char *getCompanyName() const {
        return companyName;
    }

    void setCompanyName(char *companyName) {
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
    }

    int getPosition() const {
        return position;
    }

    void setPosition(int position) {
        this->position = position;
    }


    friend ostream &operator<<(ostream &os, const User &user) {
        return os << "Username: " << user.username
                  << " Company name: " << user.companyName
                  << " Position: " << user.position;
    }

    friend istream &operator>>(istream &in, User &user) {
        return in >> user.username >> user.companyName >> user.position;
    }

    bool operator==(User &u) {
        return strcmp(this->username, u.username) == 0;
    }
};

class OperationNotSupported{
    private:
        char *msg{nullptr};
    public:
        OperationNotSupported(char *m){ this->msg = new char[strlen(m)]; strcpy(this->msg,m); }
        void showMessage(){ cout<<msg<<endl; }
};

class Group{
    protected:    
        User *arr{nullptr}; int num{0}; char groupName[50];
    public:
        Group(){ this->arr = new User[num]; }
        Group(char *gn){ strcpy(this->groupName,gn); }
        Group(const Group &other){
            if (this != &other){
                this->num = other.num; strcpy(this->groupName,other.groupName);
                this->arr = new User[other.num]; for(int  i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
            }
        }
        Group &operator=(const Group &other){
            if (this != &other){
                this->num = other.num; strcpy(this->groupName,other.groupName);
                delete[] this->arr; this->arr = new User[other.num];
                for(int  i=0; i<other.num; i++){ this->arr[i] = other.arr[i]; }
            } return *this;
        }
        ~Group(){ delete[] this->arr; this->arr = nullptr; }

        virtual void addMember(User &other){
            for(int i=0; i<num; i++){
                if(arr[i] == other){ throw OperationNotSupported("Username already exists"); }
            }
            User *temp = new User[this->num + 1];
            for(int i=0; i<this->num; i++){ temp[i] = this->arr[i]; }
            temp[num++] = other; delete[] arr; arr = temp;       
        }

        double avgPos() const{
            double sum = 0; for(int i=0; i<num; i++){ sum += arr[i].getPosition(); }
            if(num == 0){ return 0; } return sum / num;
        }

        virtual double rating() const{ return (10 - avgPos()) * num / 100.0; }

        friend ostream &operator<<(ostream &out, const Group &other){
            out << "Group: "<<other.groupName<<endl << "Members: "<<other.num<<endl;
            out << "Rating: "<< other.rating()<<endl << "Members list: "<<endl;
            if(other.num == 0){ return out << "EMPTY"<<endl; }
            for(int i=0; i<other.num; i++){ out<<i+1<<". "<<other.arr[i]<<endl; } return out;
        }
};

class PrivateGroup : public Group{
    private:
        static int capacity; const static double coefficient;
    public:
        PrivateGroup(char *n):Group(n){ }

        static void setCapacity(int c){ capacity = c; }
        static int getCapacity(){ return capacity; }

        void addMember(User &other){
            if(this->num == capacity){ throw OperationNotSupported("The group’s capacity has been exceeded."); }
            Group::addMember(other);
        } 

        double rating() const{ return (10 - avgPos()) * ((double)this->num / capacity) * coefficient; }

        friend ostream &operator<<(ostream &out, const PrivateGroup &other){ out<<"Private "; Group arr(other); return out << arr; }
};

int PrivateGroup::capacity = 10;
const double PrivateGroup::coefficient = 0.8;

int main() {
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR AND OPERATOR <<" << endl;
        Group g("test");
        cout << g;
    } else if (testCase == 2) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR AND OPERATOR <<" << endl;
        PrivateGroup pg("private test");
        cout << pg;
    } else if (testCase == 3) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND OPERATOR <<" << endl;
        Group *g = new Group("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << *g;
        delete g;
    } else if (testCase == 4) {
        cout << "TESTING CLASS PRIVATE_GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND OPERATOR <<" << endl;
        Group *g = new PrivateGroup("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << *g;
        delete g;
    } else if (testCase == 5) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND OPERATOR <<" << endl;
        Group *g = new Group("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            } catch (OperationNotSupported &e) {
                e.showMessage();
            }
        }
        cout << *g;
        delete g;
    } else if (testCase == 6) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND OPERATOR <<" << endl;
        Group *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            } catch (OperationNotSupported e) {
                e.showMessage();
            }
        }
        cout << *g;
        delete g;
    } else if (testCase == 7) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND CHANGE OF STATIC MEMBER"
             << endl;
        Group *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << "RATING BEFORE CHANGE" << endl;
        cout << g->rating();
        PrivateGroup::setCapacity(20);
        cout << "RATING AFTER CHANGE" << endl;
        cout << g->rating();
        delete g;
    }
    else if (testCase==8) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND CHANGE OF STATIC MEMBER"
             << endl;

        Group *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            } catch (OperationNotSupported & e) {
                int capacity = PrivateGroup::getCapacity();
                cout<<"Increasing capacity from "<<capacity<<" to "<<capacity+1<<endl;
                PrivateGroup::setCapacity(capacity+1);
                g->addMember(u);
                cout<<g->rating()<<endl;
            }
        }

    }else {
        cout<<"INTEGRATION TEST"<<endl;
        char name [50];
        int nGroups;
        cin>>nGroups;
        Group ** groups = new Group * [nGroups];
        for (int i=0;i<nGroups;i++) {
            int type;
            cin>>type;
            cin>>name;
            if (type==1) { //normal group
                groups[i] = new Group(name);
            } else { //private group
                groups[i] = new PrivateGroup(name);
            }
            int nUsers;
            cin>>nUsers;
            for (int j=0;j<nUsers;j++) {
                User u;
                cin>>u;
                try {
                    groups[i]->addMember(u);
                } catch (OperationNotSupported e) {
                    e.showMessage();
                }
            }
        }

        cout<<"BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT"<<endl;
        for (int i = 0; i < nGroups; ++i) {
            cout<<*groups[i];
        }
        PrivateGroup::setCapacity(15);
        cout<<"AFTER CHANGE OF PRIVATE GROUP COEFFICIENT"<<endl;
        for (int i = 0; i < nGroups; ++i) {
            cout<<*groups[i];
        }
    }
}