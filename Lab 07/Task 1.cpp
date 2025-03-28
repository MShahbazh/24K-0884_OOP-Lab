#include<iostream>
using namespace std;

class Device{
      int deviceID;
      string deviceName;
      bool status;
      string location;
      public:
      Device(){}
      Device(int a, string b, bool c, string d):deviceID(a),deviceName(b),status(c),location(d){}
      virtual void turnOn(){
          this->status=true;
      }
      virtual void turnOff(){
          this->status=false;
      }
      virtual void getStatus(){
          if(this->status==false)
              cout<<"Status : Off";
          else 
              cout<<"Status : On";
      }
      virtual void displayInfo(){
          cout<<"\nDevice ID: "<<this->deviceID<<endl;
          cout<<"Device Name: "<<this->deviceName<<endl;
          if(this->status==false)
              cout<<"Status : Off"<<endl;
          else 
              cout<<"Status : On"<<endl;
          cout<<"Device Location: "<<this->location<<endl;
      }
};

class Light: public Device{
    int brightnessLevel;  
    string colorMode;
    public:
    Light(){}
    Light(int a, string b, bool c, string d, int e, string f):Device(a,b,c,d),brightnessLevel(e),colorMode(f){}
    void displayInfo() override{
        Device::displayInfo();
        cout<<"Brightness Level: "<<this->brightnessLevel<<endl;
        cout<<"Color Mode: "<<this->colorMode<<endl;
    }
};

class Thermostat:public Device{
    float temperature;
    string mode;
    float targetTemperature;
    public:
    Thermostat(){};
    Thermostat(int a, string b, bool c, string d,float e, string f, float g):Device(a,b,c,d),temperature(e),mode(f),targetTemperature(g){};
    void getStatus() override{
        cout<<"Current Temperature: "<<this->temperature<<endl;
    }
};

class SecurityCamera: public Device{
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;
    public:
    SecurityCamera(){}
    SecurityCamera(int a, string b, bool c, string d, string e, bool f, bool g):Device(a,b,c,d),resolution(e), recordingStatus(f),nightVisionEnabled(g){}
    void turnOn() override{
        this->recordingStatus=true;
    }
};

class SmartPlug:public Device{
    int powerConsumption;
    int timerSetting;
    public:
    SmartPlug(){}
    SmartPlug(int a, string b, bool c, string d, int e, int f):Device(a,b,c,d),powerConsumption(e),timerSetting(f){}
    void turnOff() override{
        cout<<"Power Consumption: "<<this->powerConsumption<<endl;
    }
};

int main(){

    Device* d=new Light(100,"Light",false,"Room 4",67,"Yellow");
    d->displayInfo();
    d->turnOn();
    d->displayInfo();

    d=new Thermostat(101,"Thermo Stat",true,"Main Hall",17.5,"Cooling Mode",37);
    d->displayInfo();
    d->getStatus();

    d=new SecurityCamera(102,"Camera",true,"Office","1080 px",true,true);
    d->turnOn();
    d->displayInfo();

    d=new SmartPlug(103,"Smart Plug",true,"Main Room",750,100);
    d->displayInfo();
    d->turnOff();

}