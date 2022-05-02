#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    protected:
        char name[50]; int age{0}, experience{0};
    public:
        Employee(char *n, int a, int e){ strcpy(this->name,n); this->age = a; this->experience = e; }
        virtual double bonus() = 0; virtual double plata() = 0;
        bool operator==(Employee &other){ return age == other.age && bonus() == other.bonus(); }
};

class SalaryEmployee : public Employee{
    private:
        int basicSalary{0};
    public:
        SalaryEmployee(char *n, int a, int e, int b) : Employee(n,a,e){ this->basicSalary = b; }
        double bonus(){ return (basicSalary * experience) / 100.00; } 
        double plata(){ return basicSalary + bonus(); }
};

class HourlyEmployee : public Employee{
    private:
        int workHours{0}, hourlyWage{0};
    public:
        HourlyEmployee(char *n, int a, int e, int h, int w) : Employee(n, a, e){ 
            this->workHours = h; this->hourlyWage = w;
        }
        double bonus(){ return workHours>320?(workHours - 320) * hourlyWage * 0.5:0; }
        double plata(){ return workHours * hourlyWage + bonus(); }
};

class Freelancer : public Employee{
    private:
        int projectNum{0}; double salary[50];
    public:
        Freelancer(char *n, int a, int e, int p, double *s) : Employee(n, a, e){
            this->projectNum = p; for(int i=0; i<projectNum; i++){ this->salary[i] = s[i]; }
        }
        double bonus(){ return projectNum>5?(projectNum - 5) * 1000:0; }
        double plata(){ double sum = bonus(); for(int i=0; i<projectNum; i++){ sum+=salary[i]; } return sum;}
};

class Company{
    private:
        char name[50]; int employees{0}; Employee **e;
    public:
        Company(char *n){ strcpy(this->name,n); this->e = new Employee*[employees]; }
        ~Company(){ delete[] this->e; }
        Company &operator+=(Employee *emp){
            Employee **temp = new Employee *[employees + 1];
            for(int i=0; i<employees; i++){ temp[i] = e[i]; }
            temp[employees] = emp; delete[] e; e = temp; employees++; return *this;
        }
        double vkupnaPlata(){ double sum=0; for(int i=0; i<employees; i++){ sum+= e[i]->plata(); } return sum; }
        double filtriranaPlata( Employee *emp){ double sum=0; 
        for(int i=0; i<employees; i++){ if(*e[i] == *emp ){ sum+=e[i]->plata(); } } return sum; }
        void pecatiRabotnici(){
            int salaryNum=0, hourlyNum=0, freelancerNum=0;
            for(int i=0; i<employees; i++){
                SalaryEmployee *salary = dynamic_cast<SalaryEmployee*>(e[i]);
                HourlyEmployee *hourly = dynamic_cast<HourlyEmployee*>(e[i]);
                Freelancer *free = dynamic_cast<Freelancer*>(e[i]);

                if(dynamic_cast<SalaryEmployee*>(e[i])){ salaryNum++; }
                else if(dynamic_cast<HourlyEmployee*>(e[i])){ hourlyNum++; }
                else if(dynamic_cast<Freelancer*>(e[i])){ freelancerNum++; }
            }
            cout << "Vo kompanijata " << name << " rabotat: " << endl;
            cout << "Salary employees: " << salaryNum << endl;
            cout << "Hourly employees: " << hourlyNum << endl;
            cout << "Freelancers: " << freelancerNum <<endl;
        }
};

int main() {
    char name[50]; cin >> name; Company c(name);
    int n; cin >> n; char employeeName[50]; int age, experience, type;

    for (int i=0; i <n; ++i) {
        cin >> type >> employeeName >> age >> experience;

        if (type == 1) {
            int basicSalary; cin >> basicSalary;
            c += new SalaryEmployee(employeeName, age, experience, basicSalary);
        }
        else if (type == 2) {
            int hoursWorked, hourlyPay; cin >> hoursWorked >> hourlyPay;
            c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
        }
        else {
            int numProjects; cin >> numProjects; double projects[10];
            for (int i=0; i < numProjects; ++i) { cin >> projects[i]; }
            c += new Freelancer(employeeName, age, experience, numProjects, projects);
        }
    }

    c.pecatiRabotnici(); cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
    Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
    cout << "Filtriranata plata e: " << c.filtriranaPlata(emp); delete emp; return 0;
}