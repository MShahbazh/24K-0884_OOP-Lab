#ifndef LabCourse_h
#define LabCourse_h

#include<iostream>
#include"Course.h"
using namespace std;

class LabCourse:public Course{
    public:
    LabCourse(){}

    LabCourse(string a, int b):Course(a,b){}

    void calculateGrade(){
        float i;
        cout<<"Enter your percentage: ";
        cin>>i;
        if(i>100||i<0){
            cout<<"Invalid Marks"<<endl;
        }
        if(i>=90) cout<<"A"<<endl;
        else if(i>=80) cout<<"B"<<endl;
        else if(i>=70) cout<<"C"<<endl;
        else if(i>=60) cout<<"D"<<endl;
        else cout<<"F"<<endl;
    }

    void displayInfo(){
        cout<<"Course Code: "<<this->get_code()<<endl;
        cout<<"Lab Credits: "<<this->get_credits()<<endl;
    }
};




#endif
