#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main(){
    ifstream input("vehicles.txt");
    string str,str2,info;
    while(getline(input,str)){
        istringstream iss(str);
        while(getline(iss,str2,',')){
            if(str2=="HybridTruck"){
                for(int i=0;i<4;i++){
                    getline(iss,info,',');
                }
                size_t firstcolon=info.find(':');
                size_t bar=info.find('|');
                string cargo_str=info.substr(firstcolon+1,bar);
                int cargo=stoi(cargo_str);
                cout<<"Cargo: "<<cargo<<endl;

                string second_colon=info.substr(bar);
                size_t secondcolon=second_colon.find(':');
                string battery_str=second_colon.substr(secondcolon+1);
                int battery=stoi(battery_str);
                cout<<"Battery: "<<battery<<endl;
            }
            else{
                cerr<<"Unknown Vehicle Type"<<endl;
            }
        }
    }

    input.close();
}