#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream input;
    input.open("Large_log.txt");
    string str;
    getline(input,str);
    cout<<"Position of the get pointer: "<<input.tellg()<<endl;
    getline(input,str);
    cout<<"Position of the get pointer: "<<input.tellg()<<endl;
    input.close();
}