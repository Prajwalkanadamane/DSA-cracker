#include <iostream>
#include <string>
using namespace std;

class Teacher{
private:

    double salary; // hidden or not accesable outside class

public:

    string name;
    string subject;
    string dept;

    Teacher(string n, string s, string d, double sal){ // parametarized constructor
        name = n;
        subject = s;
        dept = d;
        salary = sal;

    }

    void changeDept(string newDept){
        dept = newDept;
    }
    
    void getInfo(){
        cout << endl << "Name: " << name << endl;
        cout << "subject: " << subject << endl;
        cout << "Department: " << dept << endl;
        cout << "Salary: " << salary << endl;
        
    }
};

int main(){
    Teacher t1("Swamy", "Maths", "Mathematics", 50000);
    t1.getInfo();
    t1.changeDept("Physics");
    t1.getInfo();


    return 0;
}