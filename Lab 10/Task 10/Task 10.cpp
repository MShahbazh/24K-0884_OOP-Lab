#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream output("data_records.txt");
    output<<"Record 1\nRecord 2\nRecord 3\nRecord 4\n";
    output.close();

    ifstream file;
    file.open("data_records.txt");
    file.seekg(20);
    string str;
    getline(file,str);
    cout<<str<<endl;
    file.close();
}