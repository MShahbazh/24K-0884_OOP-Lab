#include<iostream>
using namespace std;

class Employee{
    string name;
    string designation;
    public:
    Employee(){}
    
    Employee(string a,string b):name(a),designation(b){}
    
    string get_name(){
        return this->name;
    }
    
    void display(){
        cout<<"\nName: "<<this->name<<endl;
        cout<<"Designation: "<<this->designation<<endl;
    }
};

class Project{
    string title;
    string deadline;
    Employee* employees;
    int size;
    public:
    Project(){}
    
    Project(string a,string b):title(a),deadline(b),size(-1){}
    
    void add_employee(Employee c){
        if(size==-1){
            cout<<"\nEnter the Number of Employees this Project holds: ";
            cin>>size;
            employees=new Employee[size];
            for(int i=0;i<size;i++){
                employees[i]=Employee("NULL","NULL");
            }
        }
        bool check=false;
        for(int i=0;i<size;i++){
            if(employees[i].get_name()=="NULL"){
                employees[i]=c;
                check=true;
                break;
            }
        }
        if(check==false){
            cout<<"\nNot Enough Space"<<endl;
        }
    }
    
    void display(){
        cout<<"\nTitle: "<<this->title<<endl;
        cout<<"Deadline: "<<this->deadline<<endl;
        for(int i=0;i<size;i++){
            employees[i].display();
        }
    }
    
    string get_title(){
        return this->title;
    }
    
    ~Project(){
        delete employees;
    }
};

int main(){
    int p,e;
    cout<<"Enter the number of employees this program holds: ";
    cin>>e;
    cout<<"Enter the number of Project this program holds: ";
    cin>>p;
    Employee emp[e];
    Project pro[p];
    string a,b;
    for(int i=0;i<p;i++){
        cout<<"\nEnter the Employee "<<i+1<<" name: ";
        cin>>a;
        cout<<"Enter the Employee "<<i+1<<" designation: ";
        cin>>b;
        emp[i]=Employee(a,b);
    }
    for(int i=0;i<e;i++){
        cout<<"\nEnter the Project "<<i+1<<" title: ";
        cin>>a;
        cout<<"Enter the Project "<<i+1<<" Deadline: ";
        cin>>b;
        pro[i]=Project(a,b);
    }
    while(1){
        int n;
        cout<<"\n1. Display All Employees\n2. Display all Projects\n3. Add a Employee\n4. Exit\nEnter the Corresponing Number: ";
        cin>>n;
        if(n==1){
            for(int i=0;i<e;i++){
                emp[i].display();
            }
        }
        else if(n==2){
            for(int i=0;i<p;i++){
                pro[i].display();
            }
        }
        else if(n==3){
            int i,j;
            string b;
            cout<<"\nEnter the Project Title: ";
            cin>>b;
            bool present=false;
            for(int j=0;j<p;j++){
                if(b==pro[j].get_title()){
                    present=true;
                    break;
                }
            }
            if(present==true){
            for(j=0;j<p;j++){
                if(b==pro[j].get_title()){
                    break;
                }
            }
                string a;
            cout<<"\nEnter the Employee name: ";
            cin>>a;
            bool check=false;
            for( i=0;i<e;i++){
                if(a==emp[i].get_name()){
                    check=true;
                    break;
                }
            }
            if(check==false){
                cout<<"\nEmployee does not exist";
            }
            else{
                pro[j].add_employee(emp[i]);
            }
            }
            else{
                cout<<"\nProject does not Exist"<<endl;
            }
        }
        else if(n==4){
            break;
        }
    }
    
    
}