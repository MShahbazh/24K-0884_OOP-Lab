#include<iostream>
using namespace std;

class Employee{
    string name;
    float salary;
    public:
    Employee(string a, float b):name(a),salary(b){}
    void displayDetails(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"Salary: "<<this->salary<<endl;
    }
};

class Manager:public Employee{
    float bonus;
    public:
    Manager(string a, float b, float c):Employee(a,b),bonus(c){}
    void displayDetails_manager(){
        this->displayDetails();
        cout<<"Bonus: "<<this->bonus<<endl;
    }
};

int main(){
    Manager m("Ali",2500,1000);
    m.displayDetails_manager();
}