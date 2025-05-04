#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file;
    file.open("config.txt",ios::in|ios::out);
    file<<"AAAAA";
    file<<"BBBBB";
    file<<"CCCCC";
    file.close();
    
    file.open("config.txt",ios::in|ios::out);
    file.seekp(5);
    file.write("XXXXX",5);
    file.close();
    
    file.open("config.txt",ios::in|ios::out);
    string str;
    file>>str;
    cout<<str;
    file.close();
}