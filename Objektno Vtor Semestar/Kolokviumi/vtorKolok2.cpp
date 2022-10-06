#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

class WrongLabelsFormatException{
    private:
        char *msg{nullptr};
    public:
        WrongLabelsFormatException(){}
        WrongLabelsFormatException(char* msg){
            this->msg = new char[strlen(msg)]; strcpy(this->msg, msg);
        }
        void error(){ cout<<msg<<endl;}
};

class Evaluator{
    protected:
        char trueCategory[100], predictedCategory[100];
    public:
        Evaluator(char* tC, char *pC){
            strcpy(this->trueCategory, tC); strcpy(this->predictedCategory, pC);
        }
        virtual double evaluate() = 0;
        virtual void print() = 0;
        char *getTrue(){ return trueCategory; }
        char *getPredicted(){ return predictedCategory; }
        bool operator>=(Evaluator &other){ return evaluate() >= other.evaluate(); }
};

class AccuracyEvaluator : public Evaluator{
    private:
        int num{0};
    public:
        AccuracyEvaluator(char *tc, char *pc):Evaluator(tc, pc){}
        double evaluate(){
            double cntTrue = 0, cntPlus=0, cntMin=0;
            for(int i=0; i<num; i++){
                if(Evaluator::getTrue()){ cntTrue++; }
                if(Evaluator::getTrue() == "+"){ cntPlus++; }
                else if(Evaluator::getTrue() == "-") { cntMin++; }
            }
            return cntTrue / (cntPlus + cntMin);
        }

        int cntElements(){
            int cnt = 0;
            for(int i=0; i<num; i++){ if(Evaluator::getTrue()){ cnt++; } }
            return cnt;
        }
        void print(){
            cout<<"Number of data points: "<<cntElements()<<" Prediction Accuracy:"<<evaluate()<<endl;
        }
};

class SensitivityEvaluator : public Evaluator{
    public:
        SensitivityEvaluator(char* tc, char* pc):Evaluator(tc,pc){}

        int cntElements(){

        }

        void print(){ cout<<"Number of data points: "<<cntElements()<<" Prediction Sensitivity: "<<evaluate()<<endl; }
};

Evaluator * highestScore(Evaluator **evaluators, int n){
    int max=0;
    for(int i=0; i<n; i++){
        Evaluator *ae = dynamic_cast<AccuracyEvaluator *>(evaluators[i]);
        Evaluator *se = dynamic_cast<SensitivityEvaluator *>(evaluators[i]);

        if(ae[i] >= se[i]){ max = ae[i]; pos = i; }
        else if(se[i] >= ae[i]) { max = se[i]; pos = i; }
    }
}

int main() {
    int testCase;
    char trueLabels[100];
    char predictedLabels[100];
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        Evaluator *evaluator = new AccuracyEvaluator(trueLabels, predictedLabels);
        cout << evaluator->evaluate() << endl;
        evaluator->print();

    } else if (testCase == 2) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        Evaluator *evaluator = new SensitivityEvaluator(trueLabels, predictedLabels);
        cout << evaluator->evaluate() << endl;
        evaluator->print();

    } else if (testCase == 3) {
        cout << "TESTING CREATION OF BOTH EVALUATORS. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;

        Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
        accuracy->print();
        sensitivity->print();

    } else if (testCase == 4) {
        cout << "TESTING OPERATOR >=" << endl;
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy1 = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity1 = new SensitivityEvaluator(trueLabels, predictedLabels);

        accuracy->print();
        cout << (((*accuracy) >= (*sensitivity)) ? ">=" : "<") << endl;
        sensitivity->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*accuracy)) ? ">=" : "<") << endl;
        accuracy->print();
        cout << endl;

        accuracy->print();
        cout << (((*accuracy) >= (*accuracy1)) ? ">=" : "<") << endl;
        accuracy1->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*sensitivity1)) ? ">=" : "<") << endl;
        sensitivity1->print();
        cout << endl;
    } else {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION. EXCEPTION CAN HAPPEN HERE!" << endl;
        int n;
        cin >> n;
        Evaluator **evaluators = new Evaluator *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            cin >> trueLabels >> predictedLabels;

            if (type == 1) { //accuracy
                evaluators[i] = new AccuracyEvaluator(trueLabels, predictedLabels);
            } else { //sensitivity
                evaluators[i] = new SensitivityEvaluator(trueLabels, predictedLabels);
            }

        }

        cout << "PRINT ALL EVALUATORS FIRST!" << endl;
        for (int i = 0; i < n; i++) {
            evaluators[i]->print();
        }

        cout << "RESULT FROM HIGHEST SCORE METHOD" << endl;
        highestScore(evaluators, n)->print();
    }

}
