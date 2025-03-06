#include<iostream>
using namespace std;

class Device{
    int id;
    bool status;
    public:
    Device(int a, bool b):id(a),status(b){}
    void display_Device(){
        cout<<"ID: "<<this->id<<endl;
        if(status==true)
            cout<<"Status: True"<<endl;
        else
            cout<<"Status: False"<<endl;
    }
};

class SmartPhone:public Device{
    float screenSize;
    public:
    SmartPhone(int a, bool b, float c):Device(a,b),screenSize(c){}
    void display_SmartPhone(){
        this->display_Device();
        cout<<"Screen Size: "<<this->screenSize<<endl;
    }
};

class SmartWatch:public Device{
    bool heartRateMonitor;
    public:
    SmartWatch(int a, bool b, bool c):Device(a,b),heartRateMonitor(c){}
    void display_SmartWatch(){
        if(heartRateMonitor==true)
        cout<<"Heart Rate Monitor: True"<<endl;
        else
        cout<<"Heart Rate Monitor: False"<<endl;
    }
};

class SmartWearable:public SmartPhone, public SmartWatch{
    int stepCounter;
    public:
    SmartWearable(int a, bool b, float c, bool d, int e):SmartPhone(a,b,c),SmartWatch(a,b,d),stepCounter(e){}
    void display_SmartWearable(){
        this->display_SmartPhone();
        this->display_SmartWatch();
        cout<<"Step Counter: "<<this->stepCounter<<endl;
    }
};

int main(){
    SmartWearable s(1001,1,1280,1,10);
    s.display_SmartWearable();
}