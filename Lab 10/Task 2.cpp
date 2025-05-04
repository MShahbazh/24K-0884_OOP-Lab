#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int main(){
    string str;
    ifstream input("vehicles.txt");
    if(!input){
        cerr<<"File Not Oppened"<<endl;
    }
    else{
        cout<<"File Opened"<<endl;
    }

    while(getline(input,str)){
        istringstream iss(str);
        string type,id,name,year,extra,certi;
        getline(iss,type,',');
        getline(iss,id,',');
        getline(iss,name,',');
        getline(iss,year,',');
        getline(iss,extra,',');
        getline(iss,certi,',');
        cout<<"Type: "<<type<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Extra Data: "<<extra<<endl;
        cout<<"Certification: "<<certi<<endl;
    }

    input.close();
}