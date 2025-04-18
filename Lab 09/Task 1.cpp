#include<iostream>
using namespace std;

class Patient{
    string name;
    int id;
    public:
    Patient(){}
    Patient(string n,int i):name(n),id(i){}
    virtual void displayTreatment()=0;
    virtual int calculateCost()=0;
    string getName(){
        return name;
    }
    int getID(){
        return id;
    }
};

class InPatient:public Patient{
    public:
    InPatient(){}
    InPatient(string n,int i):Patient(n,i){}
    void displayTreatment(){
        cout<<"InPatient ID: "<<this->getID()<<endl;
        cout<<"Name: "<<this->getName()<<endl;
    }
    int calculateCost(){
        int j;
        cout<<"Enter the number of days you spend in hospital: ";
        cin>>j;
        return j*1000;
    }
};

class OutPatient:public Patient{
    public:
    OutPatient(){}
    OutPatient(string n,int i):Patient(n,i){}
    void displayTreatment(){
        cout<<"OutPatient ID: "<<this->getID()<<endl;
        cout<<"Name: "<<this->getName()<<endl;
    }
    int calculateCost(){
        int j;
        cout<<"Enter the number of days you spend in hospital: ";
        cin>>j<<endl;
        return j*500;
    }
};

int main(){
    Patient *p=new InPatient("Ali",2000);
    p->displayTreatment();
    cout<<p->calculateCost()<<endl;
    Patient *q=new OutPatient("Ahmed",5000);
    q->displayTreatment();
    cout<<q->calculateCost()<<endl;
    delete p;
    delete q;
    return 0;  
}
