#include <iostream>
#include <cstring>
using namespace std;

class NBAPlayer{
    protected:
        char *playerName{nullptr}, teamName[40]; double points{0}, assists{0}, rebounds{0};
    public:
        NBAPlayer(){ this->playerName = nullptr; }
        NBAPlayer(char *n, char *t, double p, double a, double r){
            this->playerName = new char[strlen(n)]; strcpy(this->playerName,n);
            strcpy(this->teamName,t); this->points = p; this->assists = a; this->rebounds = r;
        }
        NBAPlayer(const NBAPlayer &other){
            if(this != &other){
                delete[] this->playerName; this->playerName = new char[strlen(other.playerName)+1]; strcpy(this->playerName,other.playerName);
                strcpy(this->teamName,other.teamName); this->points = other.points; this->assists = other.assists; this->rebounds = other.rebounds;
            }
        }
        NBAPlayer &operator=(const NBAPlayer &other){
            if(this != &other){
                delete[] this->playerName; playerName = new char[strlen(other.playerName)+1]; strcpy(this->playerName,other.playerName);
                strcpy(this->teamName,other.teamName); this->points = other.points; this->assists = other.assists; this->rebounds = other.rebounds;
            } return *this;
        }
        ~NBAPlayer(){ delete[] this->playerName; this->playerName = nullptr; }

        double rating(){ return (0.45 * this->points) + (0.30 * this->assists) + (0.25 * this->rebounds); }

        void print(){ 
            cout<<this->playerName<<" - "<<this->teamName<<endl;
            cout<<"Points: "<<this->points<<endl<<"Assists: "<<this->assists<<endl;
            cout<<"Rebounds: "<<this->rebounds<<endl<<"Rating: "<<rating()<<endl;
        }
};

class AllStarPlayer : public NBAPlayer{
    private:
        double avgPoints{}, avgAssists{0}, avgRebounds{0};
    public:
        AllStarPlayer() : NBAPlayer(){ avgPoints = 0; avgAssists = 0; avgRebounds = 0; }
        AllStarPlayer(NBAPlayer &p, double ap, double aa, double ar) : NBAPlayer(p){
            this->avgPoints = ap; this->avgAssists = aa; this->avgRebounds = ar;
        }
        AllStarPlayer(char *playerName, char *teamName, double points, double assists, double rebounds, double ap, double aa, double ar) : NBAPlayer(playerName,teamName,points,assists,rebounds){
            this->avgPoints = ap; this->avgAssists = aa; this->avgRebounds = ar;
        }
        AllStarPlayer( AllStarPlayer &other) : NBAPlayer(other){
            this->avgPoints = other.avgPoints; this->avgAssists = other.avgAssists; this->avgRebounds = other.avgRebounds;
        }
        AllStarPlayer &operator=(const AllStarPlayer &other){
            if(this != &other){
                this->avgPoints = other.avgPoints; this->avgAssists = other.avgAssists; this->avgRebounds = other.avgRebounds;
                delete[] playerName; playerName = new char[strlen(other.playerName)+1]; strcpy(playerName,other.playerName);
                strcpy(teamName,other.teamName); points = other.points; assists = other.assists; rebounds = other.rebounds;
            } return *this;
        }
        ~AllStarPlayer(){}

        double allStarRating(){ return (0.3 * avgPoints) + (0.4 * avgAssists) + (0.3 * avgRebounds); }
        double rating(){ return (NBAPlayer::rating() + allStarRating()) /2; }

        void print(){
            NBAPlayer::print();
            cout<<"All Star Rating: "<<allStarRating()<<endl;
            cout<<"New Rating: "<<rating()<<endl;
        }

};

int main() {

    char name[50], team[40]; double points, assists, rebounds, allStarPoints, allStarAssists, allStarRebounds;

    NBAPlayer * players = new NBAPlayer[5]; AllStarPlayer * asPlayers = new AllStarPlayer[5]; int n; cin >> n;

    if (n == 1) {
        cout << "NBA PLAYERS:" << endl << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds); players[i].print(); }
    }
    else if (n == 2) {
        for (int i=0; i < 5; ++i){
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAPlayer(name,team,points,assists,rebounds);
            asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }
        cout << "NBA PLAYERS:" << endl << "=====================================" << endl;
        for (int i=0; i < 5; ++i) { players[i].print(); }
        
        cout << "ALL STAR PLAYERS:" << endl  << "=====================================" << endl;
        for (int i=0; i < 5; ++i) { asPlayers[i].print(); }
    }

    else if (n == 3) {
        for (int i=0; i < 5; ++i){
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds, allStarPoints,allStarAssists,allStarRebounds);
        }
        cout << "ALL STAR PLAYERS:" << endl << "=====================================" << endl;
        for (int i=0; i < 5; ++i) { asPlayers[i].print(); }
    }
    delete [] players; delete [] asPlayers; return 0;
}
