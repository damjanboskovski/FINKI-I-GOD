#include <iostream>
using namespace std;

class Matrica{
    private:
        float arr[10][10]={0}; int rows{0},columns{0};
    public:
        explicit Matrica(int r = 0, int c = 0){ this->rows = r; this->columns = c; }
        Matrica operator+(float n){
            Matrica m; m.rows = rows; m.columns = columns;
            for(int i=0; i<rows; i++){ for(int j=0; j<columns; j++){ m.arr[i][j]+=arr[i][j]+n; } } 
            return m;
        }
        Matrica operator-(const Matrica &other){ 
            Matrica m; m.rows = rows; m.columns = columns;
            for(int i=0; i<rows; i++){ 
                for(int j=0; j<columns; j++){ m.arr[i][j]+=arr[i][j] - other.arr[i][j]; } } 
            return m;
        }
        Matrica operator*(const Matrica &other){ 
            Matrica m; m.rows = rows; m.columns = columns;
            for(int i=0; i<rows; i++){ for(int j=0; j<columns; j++){ 
                for(int k=0; k<columns; k++){ m.arr[i][j]+=arr[i][k] * other.arr[k][j]; } } } 
            return m;
        }

        friend ostream &operator<<(ostream &out, const Matrica &other){
            for(int i=0; i<other.rows; i++){
                for(int j=0; j<other.columns; j++){ out<<other.arr[i][j]<<" "; } out<<endl; } return out;
        }

        friend istream &operator>>(istream &in, Matrica &other){
            in >> other.rows >> other.columns;
            for(int i=0; i <other.rows; i++){
                for(int j=0; j<other.columns; j++){ in >> other.arr[i][j]; } } return in;
        }
};

int main() { Matrica A,B,C; cin>>A>>B>>C; Matrica D=B*C; Matrica R=A-D+2; cout<<R; return 0; }