#include<iostream>
using namespace std;

class Shipment{
    string trackingNumber;
    double weight;
    public:
    Shipment(){}

    Shipment(string a, double b):trackingNumber(a),weight(b){}

    string get_number(){
        return trackingNumber;
    }

    double get_weight(){
        return weight;
    }

    virtual void estimateDeliveryTime()=0;
    virtual void showDetails()=0;
};

class AirFreight:public Shipment{
    public:
    AirFreight(){}
    AirFreight(string a, double b):Shipment(a,b){}

    void estimateDeliveryTime(){
        cout<<"Estimating Delivery time by Air "<<endl;
    }

    void showDetails(){
        cout<<"Tracking ID: "<<this->get_number()<<endl;
        cout<<"Weight: "<<this->get_weight()<<endl;
    }
};

class GroundShipment: public Shipment{
    public:
    GroundShipment(){}
    GroundShipment(string a, double b):Shipment(a,b){}

    void estimateDeliveryTime(){
        cout<<"Estimating Delivery time by Ground "<<endl;
    }

    void showDetails(){
        cout<<"Tracking ID: "<<this->get_number()<<endl;
        cout<<"Weight: "<<this->get_weight()<<endl;
    }
};


int main(){
    Shipment* ship;
    AirFreight Air("1004",20);
    GroundShipment Ground("1005",50);

    ship=&Air;
    ship->estimateDeliveryTime(); 
    ship->showDetails();

    ship=&Ground;
    ship->estimateDeliveryTime(); 
    ship->showDetails();

}
