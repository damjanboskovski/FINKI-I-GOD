#include <iostream>
#include <cstring>
using namespace std;

class InvalidPassword{
    private:
        char error[50];
    public:
        InvalidPassword(char *e){ strcpy(this->error,e); } void message(){ cout<<error<<endl; }
};

class InvalidMail{
    private:
        char error[50];
    public:
        InvalidMail(char *e){ strcpy(this->error, e); } void message(){ cout<<error<<endl; }
};

class MaximumSizeLimit{
    private:
        int num;
    public:
        MaximumSizeLimit(int n){ this->num = n; } void message(){ cout<<"You can't add more than "<<num<<" users."<<endl; }
};

class User{
    protected:
        char username[50], password[50], email[50];

        void setPassword(char *pass)
        {
            bool isLowercase = false, isUppercase = false, isNumber = false;
            for(int i=0; i<strlen(pass); i++){
                if(isupper(pass[i])){ isUppercase = true; }
                else if(islower(pass[i])){ isLowercase = true; }
                else if(isdigit(pass[i])){ isNumber = true; }
            } 
            if(isLowercase && isUppercase && isNumber){ strcpy(this->password,pass); }
            else throw InvalidPassword("Password is too weak.");
        }

        void setEmail(char *em){
            int cnt=0;
            for(int i=0; i<strlen(em); i++){ if(em[i] == '@'){ cnt++; } }
            if(cnt == 1){ strcpy(this->email,em); }
            else throw InvalidMail("Mail is not valid.");
        }
    public:
        User(char *un, char *pw, char *em){ strcpy(this->username,un); setPassword(pw); setEmail(em); }
        virtual double popularity() = 0;
};

class FacebookUser : public User{
    private:
        int friendsNum{0}, likesNum{0}, commentNum{0};
    public:
        FacebookUser(char *un, char *pw, char *em, int f, int l, int c) : User(un,pw,em){
            this->friendsNum = f; this->likesNum = l, this->commentNum = c;
        }
        double popularity(){ return friendsNum +  (likesNum * 0.1) + (commentNum * 0.5); }
};

class TwitterUser : public User{
    private:
        int followersNum{0}, tweetNum{0};
    public:
        TwitterUser(char *un, char *pw, char *em, int f, int t) : User(un,pw,em){
            this->followersNum = f; this->tweetNum = t;
        }
        double popularity(){ return followersNum + (tweetNum * 0.5); }
};

class SocialNetwork{
    private:
        User **arr{nullptr}; int num{0}; int max{ 5 };
    public:
        SocialNetwork(){ this->arr = new User *[num]; this->num = 0;}
        ~SocialNetwork(){ delete[] this->arr; }

        SocialNetwork &operator+=(User *user){
            if(num == max){ throw MaximumSizeLimit(max); }
            User **temp = new User *[num+1];
            for(int i=0; i<num; i++){ temp[i] = arr[i]; }
            temp[num++] = user; delete[] arr; arr = temp; return *this; 
        }

        void changeMaximumSize(int number){ max = number; }
        double avgPopularity(){ 
            double sum=0; for(int i=0; i<num; i++){ sum+= arr[i]->popularity(); } return sum/num;
        }
};

int main() {

    SocialNetwork network = SocialNetwork();
    int n, userType; cin >> n; char username[50], password[50], email[50];

    for (int i=0; i < n; ++i) {
        cin >> username >> password >> email >> userType;
        if (userType == 1) {
            int friends, likes, comments;
            cin >> friends >> likes >> comments;  
            try{
                User * u = new FacebookUser(username,password,email,friends,likes,comments);
                network += u; 
            }
            catch(InvalidPassword &ip){ ip.message(); }
            catch(InvalidMail &im){ im.message(); }
            catch(MaximumSizeLimit &msl){ msl.message(); }   
        }
        else {
            int followers, tweets; cin >> followers >> tweets;
            try{  
                User * u= new TwitterUser(username,password,email,followers,tweets);
                network += u;
            }
            catch(InvalidPassword &ip){ ip.message(); }
            catch(InvalidMail &im){ im.message(); }
            catch(MaximumSizeLimit &msl){ msl.message(); }   
        }
    }
    network.changeMaximumSize(6); cin >> username >> password >> email;
    int followers, tweets; cin >> followers >> tweets;
    
    try{
        User * u= new TwitterUser(username,password,email,followers,tweets);
        network += u;
    }
    catch(InvalidPassword &ip){ ip.message(); }
    catch(InvalidMail &im){ im.message(); }
    catch(MaximumSizeLimit &msl){ msl.message(); } 

    cout << network.avgPopularity(); return 0;
}