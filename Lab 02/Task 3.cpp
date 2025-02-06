#include<iostream>
using namespace std;

struct Employees{
    string name;
    int hoursWorked;
    int hourlyRate;
};

Employees* Input(Employees* data, int num){
    int i;
    cout<<"\n--- Input Data ---"<<endl;
    for(i=0;i<num;i++){
        cout<<"\nEnter the Data of Employee "<<i+1<<":"<<endl;
        cout<<"Enter the Employee name: ";
        cin>>data[i].name;
        cout<<"Enter the number of hours the employee worked: ";
        cin>>data[i].hoursWorked;
        cout<<"Hourly Rate of the employee: ";
        cin>>data[i].hourlyRate;
    }
    return data;
}

void Display(Employees* data, int num){
    int i;
    cout<<"\n--- Display Data ---"<<endl;
    for(i=0;i<num;i++){
        cout<<"\nEmployee "<<i+1<<":"<<endl;
        cout<<"  Name: "<<data[i].name<<endl;
        cout<<"  Hours Worked: "<<data[i].hoursWorked<<endl;
        cout<<"  Hourly Rate: "<<data[i].hourlyRate<<endl;
    }
}

void Salary_Calculate(int* salary, int num, Employees* data){
    int i;
    cout<<"\n--- Salaries of each Employee ---"<<endl;
    for(i=0;i<num;i++){
        salary[i]=data[i].hoursWorked*data[i].hourlyRate;
        cout<<"Employee "<<i+1<<" Salary: "<<salary[i]<<endl;
    }
}

void Free(Employees* data, int* salary){
    delete[] data;
    delete[] salary;
}

int main(){
    int n,i;
    cout<<"Enter the number of Employees whose data you want to store: ";
    cin>>n;
    Employees* Data=new Employees[n];
    int* Salary=new int[n];
    Input(Data,n);
    Display(Data,n);
    Salary_Calculate(Salary,n,Data);
    Free(Data,Salary);
}