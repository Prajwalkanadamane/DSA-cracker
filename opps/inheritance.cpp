#include <iostream>
#include <string>
using namespace std;

class Person{
public:

    string name;
    int age;

    Person() {
        
    }

};

class Student : public Person{
public:

    int rollNO;
    void getInfo(){
        cout << "name of the student: " << name << endl;
        cout << "age of the student: " << age << endl;
        cout << "roll no of the student: " << rollNO << endl;
    }

};


int main(){
    Student s1;
    s1.name = "Prajwal";
    s1.age = 19;
    s1.rollNO = 41;

    s1.getInfo();

    return 0;
}