#include<iostream>
#include"Course.h"
#include"LectureCourse.h"
using namespace std;

int main(){
    Course* course=new LectureCourse("EE1004",3);
    course->calculateGrade();
    course->displayInfo();
}
