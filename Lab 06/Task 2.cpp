#include<iostream>
using namespace std;

class Vehicle{
    string brand;
    int speed;
    public:
    Vehicle(string a, int b):brand(a),speed(b){}
    void display_Vehicle(){
        cout<<"Brand: "<<this->brand<<endl;
        cout<<"Speed: "<<this->speed<<endl;
    }
};

class Car:public Vehicle{
    int seats;
    public:
    Car(string a, int b, int c):Vehicle(a,b),seats(c){};
    void display_Car(){
        this->display_Vehicle();
        cout<<"Seats: "<<this->seats<<endl;
    }
};

class ElectricCar: public Car{
    int batteryLife;
    public:
    ElectricCar(string a, int b , int c, int d):Car(a,b,c),batteryLife(d){}
    void display_ElectricCar(){
        this->display_Car();
        cout<<"Battery Life: "<<this->batteryLife<<endl;
    }
};

int main(){
    ElectricCar Tesla("Model S",200,4,50);
    Tesla.display_ElectricCar();
}