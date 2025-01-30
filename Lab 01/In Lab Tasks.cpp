#include<iostream>
#include<cstring>
using namespace std;

void barChart(string arr[5], string arr2[5], int e1, int e2){
    int i;
    cout<<"\n---> Number of Participants in each Event(Bar Chart): "<<endl;
    if(e1!=0){
    cout<<"Event 1: ";
    for(i=0;i<e1;i++){
        if(arr[i]!="NULL"){
            cout<<"*";
        }
    }
    }
    if(e2!=0){
    cout<<"\nEvent 2: ";
    for(i=0;i<e2;i++){
        if(arr2[i]!="NULL"){
            cout<<"*";
        }
    }
    }
}

void reverseOrder(string arr[5], string arr2[5], int e1,int e2){
    int i,j,k;
    string rev[5];
    string rev2[5];
    if(e1!=0){
    for(i=0;i<e1;i++){
        rev[i]=arr[i];
        for(j=0,k=arr[i].size()-1;j<arr[i].size();j++,k--){
            rev[i][j]=arr[i][k];
        }
    }
    cout<<"\n---> Event 1 names Reversed: "<<endl;
    for(i=0;i<e1;i++){
        cout<<rev[i]<<endl;
    }
    }
    if(e2!=0){
    for(i=0;i<e2;i++){
        rev2[i]=arr2[i];
        for(j=0,k=arr2[i].size()-1;j<arr2[i].size();j++,k--){
            rev2[i][j]=arr2[i][k];
        }
    }
    cout<<"\n---> Event 2 names Reversed: "<<endl;
    for(i=0;i<e2;i++){
        cout<<rev2[i]<<endl;
    }
    }
}

int totalDonations(string arr[5],string arr2[5], int e1, int e2){
    int donation;
    donation=e1*10+e2*10;
    return donation;
}

void attendanceChecker(string arr[5], string arr2[5],int e1,int e2){
    string name;
    int i,check=0;
    cout<<"\n---> Attendance Checker"<<endl;
    cout<<"Enter the name to check: ";
    cin>>name;
    for(i=0;i<e1;i++){
           if(arr[i]==name){
               cout<<name<<" is present in Event 1"<<endl;
               check=1;
               break;
           }
    }
    for(i=0;i<e2;i++){
           if(arr2[i]==name){
               cout<<name<<" is present in Event 2"<<endl;
               check=1;
               break;
           }
    }
    if(check==0) cout<<"User of this name not Found"<<endl;
}

void collectingData(string arr[5],string arr2[5], int e1, int e2){
    int i;
    cout<<"\n---> Collecting Data: "<<endl;
    if(e1!=0){
    cout<<"First Event Participants Data: "<<endl;
    for(i=0;i<e1;i++){
        cout<<"Enter the Participant "<<i+1<<" : ";
        cin>>arr[i];
    }
    }
    if(e2!=0){
    cout<<"\nSecond Event Participants Data: "<<endl;
    for(i=0;i<e2;i++){
        cout<<"Enter the Participant "<<i+1<<" : ";
        cin>>arr2[i];
    }
    }
}

void displayData(string arr[5], string arr2[5], int e1, int e2){
    int i,j;
    cout<<"\n---> Display Data: "<<endl;
    if(e1!=0){
        cout<<"Event 1 Data:"<<endl;
        for(i=0;i<e1;i++){
            cout<<arr[i]<<endl;
        }
    }
    if(e2!=0){
        cout<<"\nEvent 2 Data:"<<endl;
        for(i=0;i<e2;i++){
            cout<<arr2[i]<<endl;
        }
    }
}

int main(){
    int e1,e2;
    do{
        cout<<"Enter the number of participants for Event 1: ";
        cin>>e1;
    }while(e1>5);
    do{
        cout<<"Enter the number of participants for Event 2: ";
        cin>>e2;
    }while(e2>5);
    string event1[5];
    string event2[5];
    if(e1==0&&e2==0){
        cout<<"You Entered both as 0, so no data can be entered"<<endl;
    }
    else{
    collectingData(event1,event2,e1,e2);
    displayData(event1,event2,e1,e2); 
    attendanceChecker(event1,event2,e1,e2);
    cout<<"\n---> Total Donation amount collected from both events is "<<totalDonations(event1,event2, e1,e2)<<endl;
    reverseOrder(event1,event2, e1,e2);
    barChart(event1,event2,e1,e2);
    }
}