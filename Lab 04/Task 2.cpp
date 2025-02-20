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
    
    Car(string a, string b, float c){
        this->brand=a;
        this->model=b;
        this->rental_price=c;
        this->availibility=true;
    }

    void apply_discount(int day){
        if(this->availibility==true){
            if(day>5&7&day<=10){
                this->rental_price-=0.05*this->rental_price;
                cout<<"\nYou got 5% discount on renting the vehicle for more than 5 days"<<endl;
            }
            else if(day>10){
                this->rental_price-=0.1*this->rental_price;
                cout<<"\nYou got 10% discount on renting the vehicle for more than 10 days"<<endl;
            }
            else{
                cout<<"\nNo Discount will be given"<<endl;
            }
        }
        else{
            cout<<"\nYou have already rented the car | Discount applies before renting"<<endl;
        }
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
    int n;  
    cout<<"\n--- Default contructor ---"<<endl;
    c1.display_details();
    Car c2("Honda","2023",1400);
    cout<<"\n --- Parametrized Construtor ---"<<endl;
    c2.display_details();
    cout<<"\n --- Apply for Discount --- "<<endl;
    cout<<"\nFor how many days would you like to rent: ";
    cin>>n;
    c2.apply_discount(n);
    c2.display_details();
    cout<<"\n --- Apply for rent --- "<<endl;
    c2.rent_car();
    c2.display_details();
    cout<<"\n --- Apply for discount after renting | error message expected ---"<<endl;
    cout<<"\nFor how many days would you like to rent: ";
    cin>>n;
    c2.apply_discount(n);
    
}