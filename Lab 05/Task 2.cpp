#include<iostream>
using namespace std;

class Student{
    int id;
    string name;
    int* scores;
    public:
    Student(int a, string b):id(a),name(b){
        scores=new int[3];
        for(int i=0;i<3;i++){
            cout<<"Enter the Marks of Subject "<<i+1<<": ";
            cin>>scores[i];
        }
    }
    
    Student(const Student& s){
        this->id=s.id;
        this->name=s.name;
        for(int i=0;i<3;i++){
            this->scores=new int[3];
            for(int i=0;i<3;i++){
                this->scores[i]=s.scores[i];
            }
        }
    }
    
    void display(){
        cout<<"\nID: "<<this->id<<endl;
        cout<<"Name: "<<this->name<<endl;
        for(int i=0;i<3;i++){
            cout<<"Subject "<<i+1<<": "<<scores[i]<<endl;
        }
    }
    
};

int main(){
    Student s1(1000,"Ali");
    s1.display();
    Student s2(s1);
    s1.display();
    s2.display();
}