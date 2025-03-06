#include<iostream>
using namespace std;

class AlarmSystem{
    string level="NULL";
    public:
    AlarmSystem(string a){
        if(!(a=="High"||a=="Medium"||a=="Low")){
            cout<<"\nSecurity Level can either be high, medium or low"<<endl;
        }
        else{
            this->level=a;
        }
    }
    void display(){
        cout<<"\nSecurity Level: "<<this->level<<endl;
    }
};

class SmartHome{
    AlarmSystem alarm;
    public:
    SmartHome(string a):alarm(a){}
    void display(){
        alarm.display();
    }
};

int main(){
    SmartHome h1("High");
    h1.display();
}