#include<iostream>
#include"Course.h"
#include"LabCourse.h"
using namespace std;

int main(){
    Course* course=new LabCourse("CS1004",1);
    course->calculateGrade();
    course->displayInfo();
}
