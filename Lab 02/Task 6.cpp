#include<iostream>
using namespace std;

int main(){
    int n,i;
    cout<<"Enter the number of students: ";
    cin>>n;
    
    string* names=new string[n];
    string* rollNumber=new string[n];
    int* marks1=new int[n];
    int* marks2=new int[n];
    int* marks3=new int[n];

    cout<<"\n--- Input Data ---"<<endl;
    for(i=0;i<n;i++){
        cout<<"\nStudent "<<i+1<<": "<<endl;
        cout<<"Enter the name of the student: ";
        cin>>names[i];
        cout<<"Enter the roll number of the student: ";
        cin>>rollNumber[i];
        cout<<"Enter the marks of Subject 1: ";
        cin>>marks1[i];
        cout<<"Enter the marks of Subject 2: ";
        cin>>marks2[i];
        cout<<"Enter the marks of Subject 3: ";
        cin>>marks3[i];
    }
    cout<<"\n--- Display Data ---"<<endl;
    for(i=0;i<n;i++){
        cout<<"\nStudent "<<i+1<<": "<<endl;
        cout<<" Name: "<<names[i]<<endl;
        cout<<" Roll Number: "<<rollNumber[i]<<endl;
        cout<<" Subject 1 Marks: "<<marks1[i]<<endl;
        cout<<" Subject 2 Marks: "<<marks2[i]<<endl;
        cout<<" Subject 3 Marks: "<<marks3[i]<<endl;
    }
    cout<<"\n--- Average Marks of each student ---\n"<<endl;
    for(i=0;i<n;i++){
        cout<<"Student "<<i+1<<": "<<(marks1[i]+marks2[i]+marks3[i])/3<<endl;
    }
    
    delete[] names;
    delete[] rollNumber;
    delete[] marks1;
    delete[] marks2;
}