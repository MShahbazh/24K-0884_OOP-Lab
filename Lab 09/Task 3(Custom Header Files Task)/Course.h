#ifndef Course_H
#define Course_H

#include<iostream>
using namespace std;

class Course{
    string courseCode;
    int credits;
    public:
    Course(){}

    Course(string a, int b):courseCode(a),credits(b){}

    string get_code(){
        return courseCode;
    }

    int get_credits(){
        return credits;
    }

    virtual void calculateGrade()=0;
    virtual void displayInfo()=0;
};



#endif
