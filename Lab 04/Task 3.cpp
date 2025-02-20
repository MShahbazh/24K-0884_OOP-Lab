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

    Car(Car& c){
        this->brand=c.brand;
        this->model=c.model;
        this->rental_price=c.rental_price;
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

   ~Car(){
    cout<<"Car Object is destroyed"<<endl;
   }

};

int main(){
    Car original("Honda","2029",1200);
    Car copied(original);
    cout<<"\n--- Original Car ---"<<endl;
    original.display_details();
    cout<<"\n--- Copied Car ---"<<endl;
    copied.display_details();
    cout<<"\n --- Updated Original Car Object ---"<<endl;
    original.update_brand("Toyota");
    original.update_model("3000");
    original.update_price(4000);
    original.display_details();
    cout<<"\n --- Copied Object Details after updated original --- "<<endl;
    copied.display_details();
}