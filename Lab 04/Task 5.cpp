#include<iostream>
using namespace std;

class Car{
    int ID;
    string brand;
    string model;
    float rental_price;
    bool availibility;
    float revenue;
    public:
    Car(){
        this->ID=0;
        this->brand="Unknown";
        this->model="Generic";
        this->rental_price=0.0;
        this->availibility=true;
        this->revenue=0;
    }
    
    Car(int d, string a, string b, float c):ID(d){
        this->brand=a;
        this->model=b;
        this->rental_price=c;
        this->availibility=true;
        this->revenue=0;
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
            this->revenue=this->rental_price*day;
        }
        else{
            cout<<"\nYou have already rented the car | Discount applies before renting"<<endl;
        }
    }

    float get_revenue(){
       return this->revenue;
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
    cout<<"\nCar ID: "<<this->ID<<endl;
    cout<<"Car Brand: "<<this->brand<<endl;
    cout<<"Car Model: "<<this->model<<endl;
    cout<<"Rental Price: "<<this->rental_price<<endl;
    cout<<"Total Revenue: "<<this->revenue<<endl;
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
    int day;
    Car c1;
    c1.display_details();
    Car c2(1000,"Honda","2023",1200);
    cout<<"\nFor how many days you want to rent the vehicle: ";
    cin>>day;
    c2.apply_discount(day);
    c2.rent_car();
    c2.display_details();


}