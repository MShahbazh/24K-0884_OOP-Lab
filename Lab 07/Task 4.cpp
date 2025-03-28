#include<iostream>
using namespace std;

class Person{
    string name;
    int age;
    string contactNumber;
    string address;
    public:
    Person(){}
    Person(string a, int b, string c, string d):name(a),age(b),contactNumber(c),address(d){}
    virtual void displayInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact Number: "<<contactNumber<<endl;
        cout<<"Address: "<<address<<endl;
    }
    virtual void updateInfo(){
        cout<<"Person Info Updated"<<endl;
    }
};

class Patient: public Person{
    int patientID;
    string medicalHistory;
    string doctorAssigned;
    public:
    Patient(){}
    Patient(string a, int b, string c, string d, int e, string f, string g):Person(a,b,c,d),patientID(e),medicalHistory(f),doctorAssigned(g){}
    void displayInfo() override{
        Person::displayInfo();
        cout<<"Patient ID: "<<patientID<<endl;
        cout<<"Medical History: "<<medicalHistory<<endl;
        cout<<"Doctor Assigned: "<<doctorAssigned<<endl;
    }
};

class Doctor: public Person{
    string specialization;
    int consultationFee;
    string patientsList;
    public:
    Doctor(){}
    Doctor(string a, int b, string c, string d, string e, int f, string g):Person(a,b,c,d),specialization(e),consultationFee(f),patientsList(g){}
    void displayInfo() override{
        Person::displayInfo();
        cout<<"Specialization: "<<specialization<<endl;
        cout<<"Consultaion Fee: "<<consultationFee<<endl;
        cout<<"Patients List: "<<patientsList<<endl;
    }
};

class Nurse:public Person{
    string assignedWard;
    string shiftTimings;
    public:
    Nurse(){}
    Nurse(string a, int b, string c, string d,string e, string f):Person(a,b,c,d),assignedWard(e),shiftTimings(f){}
     void displayInfo() override{
        Person::displayInfo();
        cout<<"Assigned Ward: "<<assignedWard<<endl;
        cout<<"Shift Timings: "<<shiftTimings<<endl;
    }
};

class Administrator: public Person{
    string department;
    int salary;
    public:
    Administrator(){}
    Administrator(string a, int b, string c, string d,string e, int f):Person(a,b,c,d),department(e),salary(f){}
    void updateInfo() override{
        cout<<"Staff Info Updated"<<endl;
    }   
};

int main(){
    Person* p=new Patient("Patient 1",23,"1001","China",101,"Had Cancer","Doctor 1, Doctor 2");
    p->displayInfo();

    p=new Doctor("Doctor 1",29,"1002","USA","MBBS",2000,"Patient 1, Patient 2, Patient 3");
    p->displayInfo();

    p=new Nurse("Nurse 1",28,"1003","Germany","Mental Health","8:00am-6:00pm");
    p->displayInfo();

    p=new Administrator("Admin 1",40,"1004","Canada","IT",50000);
    p->updateInfo();
    p->displayInfo();
}