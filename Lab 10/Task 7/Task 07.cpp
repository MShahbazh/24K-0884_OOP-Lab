#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream output;
    output.open("sensor_log.txt");
    cout<<output.tellp()<<endl;
    output<<"Sensor 1: 25.5 C"<<endl;;
    cout<<output.tellp()<<endl;
    output<<"Sensor 2: 98.1 %RH"<<endl;;
    cout<<output.tellp()<<endl;
    output.close();
}
