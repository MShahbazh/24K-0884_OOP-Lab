#include<iostream>
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
        cout<<str<<endl;
    }
    input.close();
}
