#include <iostream>
#include <cstring>
using namespace std;

struct Player{ char playerName[15]; int level, points; };
struct ComputerGame{ char gameName[20]; Player arr[30]; int playerNum; };

void bestPlayer(ComputerGame *array, int num){
    int max=0;
    for(int i=0;i<num;i++){ array[i].playerNum > array[max].playerNum? max = i:0;}

    ComputerGame mostPopular = array[max]; int max2=0;

    for(int i=0;i<mostPopular.playerNum;i++){
        if(mostPopular.arr[i].points > mostPopular.arr[max2].points){ max2 = i; }
        else if(mostPopular.arr[i].points == mostPopular.arr[max2].points){
            mostPopular.arr[i].level > mostPopular.arr[max2].level?max2 = i:0;
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime "<<mostPopular.arr[max2].playerName<<" koj ja igra igrata "<<mostPopular.gameName;
}

int main() {
    int n; char ime[20]; cin>>n;

    ComputerGame gamePool[100];
    for (int i=0; i<n; i++) {
        ComputerGame n; Player pool[30];
        cin>>n.gameName>>n.playerNum;

        for (int j=0; j<n.playerNum; j++) {
            Player newer;
            cin >> newer.playerName >> newer.level >> newer.points;
            n.arr[j]=newer;
        }
        gamePool[i]=n;
    }
    bestPlayer(gamePool,n);
    return 0;
}