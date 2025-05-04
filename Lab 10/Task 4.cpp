#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
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
        string type,extra;
        if(str.size()!=0){
            for(int i=0;i<5;i++){
                if(i==0){
                    getline(iss,type,',');
                }
                else{
                    getline(iss,extra,',');
                }
            }
        }
        if(type=="AutonomousCar"||type=="ElectricVehicle"){
            size_t n=extra.find(':');
            string extracted=extra.substr(n+1);
            if(n!=-1){
                float version=stof(extracted);
                if(type=="AutonomousCar")
                cout<<"Software Version is: "<<version<<endl;
                else
                cout<<"Battery is: "<<version<<endl;
            }
        }
    }

    input.close();
}