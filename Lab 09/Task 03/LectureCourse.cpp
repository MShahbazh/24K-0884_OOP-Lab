#include<iostream>
#include"LectureCourse.h"
using namespace std;

int main(){
    LectureCourse Lec("EE1005",3);
    Lec.calculateGrade();
    Lec.displayInfo();
}
