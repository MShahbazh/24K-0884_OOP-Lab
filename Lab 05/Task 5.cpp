#include<iostream>
using namespace std;

class Doctor{
    string name;
    string specialization;
    int years;
    public:
    Doctor(){}
    Doctor(string a,string b, int c):name(a),specialization(b),years(c){}
    void display(){
        cout<<"\nName: "<<this->name<<endl;
        cout<<"Specialization: "<<this->specialization<<endl;
        cout<<"Years: "<<this->years<<endl;
    }
    string get_name(){
        return this->name;
    }
};

class Hospital{
    int size;
    Doctor* doctors;
    public:
    Hospital(int n){
        this->size=n;
        doctors=new Doctor[size];
        for(int i=0;i<size;i++){
            doctors[i]=Doctor("NULL","NULL",0);
        }
    }
    void add_doctor(Doctor c){
        bool check=false;
        for(int i=0;i<size;i++){
            if(doctors[i].get_name()=="NULL"){
                doctors[i]=c;
                check=true;
                cout<<"\nDoctor Added to List"<<endl;
                break;
            }
        }
        if(check==false){
            cout<<"\nSpace not available"<<endl;
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            doctors[i].display();
        }
    }
    ~Hospital(){
        delete[] doctors;
    }
};

int main(){
    Doctor d1("Ali","Doctor",2);
    Doctor d2("Ahmed","Doctor1",3);
    Hospital h1(2);
    h1.add_doctor(d1);
    h1.add_doctor(d2);
    h1.display();
}