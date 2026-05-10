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

    Teacher(string name, string subject, string dept, double salary){ // parametarized constructor
    //  property of a object : parameter of function
        this-> name = name;
        this-> subject = subject;
        this-> dept = dept;
        this-> salary = salary;

    }

    void changeDept(string newDept){
        dept = newDept;
    }
    
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "subject: " << subject << endl;
        cout << "Department: " << dept << endl;
        cout << "Salary: " << salary << endl;
        
    }
};

int main(){
    Teacher t1("Swamy", "Maths", "Mathematics", 50000);
    // t1.getInfo();
    Teacher t2(t1); // default copy constructor invoked
    t2.getInfo();


    return 0;
}