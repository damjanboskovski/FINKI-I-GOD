#include <iostream>
#include <cstring>
using namespace std;

class Task{
    protected:
        char id[5];
    public:
        Task( char *i){ strcpy(this->id,i); }
        ~Task(){}

        virtual int getOrder() = 0; virtual void print() = 0;
        char *getID(){ return id; }
};

bool operator==(Task *task1, Task &task2){ return !strcmp(task1->getID(),task2.getID()) && task1->getOrder() == task2.getOrder(); }

class TimedTask : public Task{
    private:
        int time{0};
    public:
        TimedTask(char *id, int t):Task(id){ this->time = t; }
        int getOrder(){ return time; } void print(){ cout<<"TT->"<<id<<":"<<getOrder()<<endl; }
};

class PriorityTask : public Task{
    private:
        int priority{0};
    public:
        PriorityTask(char *id, int p):Task(id){ this->priority = p; }
        int getOrder(){ return priority; } void print(){ cout<<"PT->"<<id<<":"<<getOrder()<<endl; }
};

void scheduleTimedTasks(Task **tasks, int n, int t){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(tasks[i]->getOrder() > tasks[j]->getOrder()){
                Task *temp = tasks[i]; tasks[i] = tasks[j]; tasks[j] = temp; } } }
    
    for(int i=0; i<n; i++){
        if(dynamic_cast<TimedTask*>(tasks[i])){ if(tasks[i]->getOrder() < t){ tasks[i]->print(); } }
    }
}

void schedulePriorityTasks(Task **tasks, int n, int p){
    for(int i=0; i<n; i++){ 
        if(dynamic_cast<PriorityTask*>(tasks[i])){ if(tasks[i]->getOrder() < p){ tasks[i]->print(); } }
    }
}

int main () {
    int testCase, n; cin>>testCase;
    
    if (testCase==0){
        cin>>n; Task ** tasks = new Task * [n];
    	for (int i=0;i<n;i++){
            char id [5]; int timeOrPriority, type; cin >> type >>id >> timeOrPriority;
            if (type==0){ tasks[i] = new TimedTask(id,timeOrPriority); }
            else{ tasks[i] = new PriorityTask(id,timeOrPriority); }
    	}
    	cout<<"SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10"<<endl;
    	schedulePriorityTasks(tasks,n,10);    
    }
    else if (testCase==1) {
        cin>>n; Task ** tasks = new Task * [n];
    	for (int i=0;i<n;i++){
            char id [5]; int timeOrPriority, type; cin >> type >>id >> timeOrPriority;
            if (type==0){ tasks[i] = new TimedTask(id,timeOrPriority); }
            else{ tasks[i] = new PriorityTask(id,timeOrPriority); }
    	}  	
        cout<<"SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50"<<endl;
        scheduleTimedTasks(tasks,n,50);
    }
    else {
        TimedTask * tt1 = new TimedTask("11",10); 
        TimedTask * tt2 = new TimedTask("11",11); 
        TimedTask * tt3 = new TimedTask("11",11);
        PriorityTask * pp1 = new PriorityTask("aa",10); 
        PriorityTask * pp2 = new PriorityTask("11",10);
        cout << (tt1==(*tt2))<<endl << (tt2==(*tt3))<<endl << (pp1==(*pp2))<<endl << (pp2==(*tt1))<<endl;
    } 
	return 0;
}