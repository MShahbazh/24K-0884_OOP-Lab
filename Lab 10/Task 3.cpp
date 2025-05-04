#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    ifstream input("vehicles.txt");
    string str;
    int number;
    while(getline(input,str)){
        istringstream iss(str);
        for(int i=0;i<4;i++){
            getline(iss,str,',');
        }
        if(str.size()!=0){
            number=stoi(str);
            cout<<number<<endl;
        }
    }
    input.close();
}