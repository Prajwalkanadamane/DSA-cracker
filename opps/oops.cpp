#include <iostream>
#include <string>
using namespace std;

class gymAchiver{
public:
    gymAchiver(){
        cout << "hi, you chutia" << endl; 
    }
    string gymName = "achiver";
    int fee = 1500;
    string location = "Over vishal mart, torangal";
    string admissionName;
    string Triner1 = "rohit";
    string Trainer2 = "abhishek";

    void changeTrianer1(string Triner1){
        Triner1 = Trainer2;
    }

    void changeTrainer2(string Trainer2){
        Trainer2 = Triner1;
    }
};

int main(){
    gymAchiver g; // object
    g.fee = 3000;
    g.gymName = "SHT gym club";
    cout << g.gymName << endl;
    cout << g.fee << endl;
    cout << g.location << endl;
    cout << "enter your name:";
    cin >> g.admissionName;
    cout << g.admissionName << endl;
    cout << g.Triner1 << endl;
    cout << g.Trainer2 << endl;
   return 0;
}