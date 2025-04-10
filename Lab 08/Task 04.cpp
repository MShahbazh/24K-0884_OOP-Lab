#include<iostream>
using namespace std;

class Car{
    string model;
    double price;
    public:
    Car(){}
    Car(string a, double b):model(a),price(b){}
    friend class InventoryManager;
    friend void comparePrice(Car& a,Car& b);
};

class InventoryManager{
    public:
    void display(Car& c){
        cout<<"\nModel Name: "<<c.model<<endl;
        cout<<"Price: "<<c.price<<endl;
    }
    void update_price(Car& c, double a){
        c.price=a;
    }
};

void comparePrice(Car& a,Car& b){
    if(a.price==b.price) cout<<a.model<<" and "<<b.model<<" have same Price"<<endl;
    else if(a.price<b.price) cout<<b.model<<"(Price: "<<b.price<<")is more expensive than "<<a.model<<"(Price: "<<a.price<<endl;
    else  cout<<a.model<<"(Price: "<<a.price<<")is more expensive than "<<b.model<<"(Price: "<<b.price<<")"<<endl;
}

int main(){
    Car c1("Honda",25000);
    Car c2("Toyota",35000);
    InventoryManager m1;
    m1.update_price(c2,50000);
    m1.display(c1);
    m1.display(c2);
    comparePrice(c1,c2);
}