#include<iostream>
using namespace std;

class WeatherSensor{
    public:
    WeatherSensor(){}

    virtual void readData()=0;
    virtual void displayReport()=0;
};

class Thermometer:public WeatherSensor{
    public:
    Thermometer(){}

    void readData(){
        cout<<"Thermometer reading data"<<endl;
    }

    void displayReport(){
        cout<<"Diplaying temperature: 37C"<<endl;
    }
};

class Barometer:public WeatherSensor{
    public:
    Barometer(){}

    void readData(){
        cout<<"Barometer reading data"<<endl;
    }

    void displayReport(){
        cout<<"Diplaying Pressure: 2atm"<<endl;
    }
};

int main(){
    WeatherSensor* sensor;
    Thermometer therm;
    Barometer baro;

    sensor=&therm;
    sensor->readData();
    sensor->displayReport();

    sensor=&baro;
    sensor->readData();
    sensor->displayReport();

}
