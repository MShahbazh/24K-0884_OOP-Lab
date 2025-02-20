#include<iostream>
using namespace std;

class Car{
    string brand;
    string model;
    float rental_price;
    bool availibility;
    public:
    Car(){
        this->brand="Unknown";
        this->model="Generic";
        this->rental_price=0.0;
        this->availibility=true;
    }
   void update_brand(string a){
    this->brand=a;
   }
   void update_model(string b){
    this->model=b;
   }
   void update_price(float c){
    this->rental_price=c;
   }

    void display_details(){
    cout<<"\nCar Brand: "<<this->brand<<endl;
    cout<<"Car Model: "<<this->model<<endl;
    cout<<"Rental Price: "<<this->rental_price<<endl;
    if(this->availibility==true){
        cout<<"Availibility: Yes"<<endl;
    }
    else{
        cout<<"Availibility: No"<<endl;
    }
   }

   void rent_car(){
    if(this->availibility==true){
        cout<<"\nYou got the Car"<<endl;
        this->availibility=false;
    }
    else{
        cout<<"\nSorry you can't get the car | It is already rented"<<endl;
    }
   }

};

int main(){
    Car c1;
    cout<<"\n --- Default Vehicles ---"<<endl;
    c1.display_details();
    c1.update_brand("Honda");
    c1.update_model("2023");
    c1.update_price(1200);
    cout<<"\n --- Details After setting up values ---"<<endl;
    c1.display_details();
    cout<<"\n--- After Renting a Car ---"<<endl;
    c1.rent_car();
    c1.display_details();
    cout<<"\n --- Renting again ---"<<endl;
    c1.rent_car();
}