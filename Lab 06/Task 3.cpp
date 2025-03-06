#include<iostream>
using namespace std;

class Person{
    string name;
    int age;
    public:
    Person(string a, int b):name(a),age(b){}
    void display_Person(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"Age: "<<this->age<<endl;
    }
};

class Teacher:public Person{
    string subject;
    public:
    Teacher(string a , int b, string c):Person(a,b),subject(c){}
    void display_Teacher(){
        this->display_Person();
        cout<<"Subject: "<<this->subject<<endl;
    }
};

class Researcher: public Person{
    string researchArea;
    public:
    Researcher(string a, int b, string c):Person(a,b),researchArea(c){}
    void display_Researcher(){
        cout<<"Research Area: "<<this->researchArea<<endl;
    }
};

class Professor: public Teacher, public Researcher{
    int publications;
    public:
    Professor(string a, int b , string c, string d, int e):Teacher(a,b,c),Researcher(a,b,d),publications(e){}
    void display_Professor(){
        this->display_Teacher();
        this->display_Researcher();
        cout<<"Publications: "<<this->publications<<endl;
    }

};

int main(){
    Professor p("Ahmed",65,"CS","Nano Technology",10);
    p.display_Professor();
}