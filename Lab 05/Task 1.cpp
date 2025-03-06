#include<iostream>
using namespace std;

class Apartment{
    int id;
    string address;
    string* name;
    public:
    Apartment(int a, string b, string c):id(a),address(c){
        this->name=new string(b);
    }
    
    Apartment(const Apartment& a){
        this->id=a.id;
        this->address=a.address;
        name=a.name;
    }
    
    void set_owner(string a){
        this->name=&a;
    }
    
    void display(){
        cout<<"\nID: "<<this->id<<endl;
        cout<<"Name: "<<*name<<endl;
        cout<<"Address: "<<this->address<<endl;
    }
};

int main(){
    Apartment room(1000,"Ali","Karachi");
    room.display();
    Apartment room2(room);
    room2.display();
    room.set_owner("Ahmed");
    room.display();
    room2.display();
}