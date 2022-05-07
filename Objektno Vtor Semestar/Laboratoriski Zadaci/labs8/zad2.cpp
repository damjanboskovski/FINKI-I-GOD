#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

class Igrachka {
    public:
        virtual float getVolumen() = 0;
        virtual float getMasa() = 0;
        virtual float getPlostina() = 0;
};

class Forma {
    protected: char color[100]; int density{0};
    public: Forma(char *c, int d){ strcpy(this->color,c); this->density = d; }
};

class Kocka : public Igrachka, public Forma{
    private:
        int height{0}, width{0}, depth{0};
    public:
        Kocka(int h, int w, int d,  char *c, int de) : Igrachka(),Forma(c,de){ this->height = h; this->width = w; this->depth = d; }
        float getVolumen(){ return (float) height * (float) width * (float) depth; }
        float getMasa(){ return density * getVolumen(); }
        float getPlostina(){ return 2 * height * width + 2 * height * depth + 2 * width * depth; }
};

class Topka : public Igrachka, public Forma{
    private:
        int radius{0};
    public:
        Topka(int r, char *c, int d) : Igrachka(),Forma(c,d){ this->radius = r; }
        float getVolumen(){ return (4.0/3.0) * (3.14 * pow(radius,3)); }
        float getMasa(){ return (float)density * getVolumen(); }
        float getPlostina(){ return 4.0 * 3.14 * pow(radius,2); }
};

int main(){
	int num, shape, density, radius, height, width, depth; char color[30];
    cin >>num; Igrachka **arr = new Igrachka *[num];

    for(int i=0; i<num; i++){
        cin>>shape;
        if(shape == 1){
            cin >> color >> density >> radius;
            arr[i] = new Topka(radius, color, density);
        }
        else{
            cin >> color >> density >> height >> width >> depth;
            arr[i] = new Kocka(height, width, depth, color, density);
        }
    }
    
    cin >> color >> density >> height >> width >> depth;
    Kocka petra(height, width, depth, color, density);
    float mass=0, max = arr[0]->getVolumen(), min = arr[0]->getVolumen();
    
    for(int i=0; i<num; i++){
        mass+= arr[i]->getMasa();
        if(max < arr[i]->getVolumen()){ max = arr[i]->getVolumen(); }
        if(min > arr[i]->getPlostina()){ min = arr[i]->getPlostina(); }
    }

    if(petra.getMasa() < mass){ cout<<"DA"<<endl; }
    else { cout<<"NE"<<endl; }
    cout<<"Razlikata e: "<<abs(max - petra.getVolumen())<<endl;
    cout<<"Razlikata e: "<<abs(min - petra.getPlostina())<<endl;
    delete[] arr;

	return 0;
}