#include<iostream>
using namespace std;

struct books{
    string title;
    string author;
    int year;
};

int main(){
    int n,i,a,year,check;
    cout<<"Input the Number of books whose data you want to store: ";
    cin>>n;
    books* data=new books[n];
    for(i=0;i<n;i++){
        cout<<"\nData for book "<<i+1<<" :"<<endl;
        cout<<"Enter the Title of book: ";
        cin>>data[i].title;
        cout<<"Enter the name of the author of book: ";
        cin>>data[i].author;
        cout<<"Enter the year of publishing of the book: ";
        cin>>data[i].year;
    }
    cout<<"\nNow that you have entered the data for the books you can choose any of the options below:"<<endl;
    do{
        cout<<"\n1. Display the Data\n2. Display all books after a specific year\n3. Exit the Program"<<endl;
        cout<<"Enter the corresponding number (1-3): ";
        cin>>a;
        if(a==1){
            cout<<"\n--- Books Info ---"<<endl;
            for(i=0;i<n;i++){
                cout<<"\nBook "<<i+1<<":"<<endl;
                cout<<"Title: "<<data[i].author<<endl;
                cout<<"Author: "<<data[i].author<<endl;
                cout<<"Year of Publishing: "<<data[i].year<<endl;
            }
        }
        else if(a==2){
            check=0;
            cout<<"Enter the year: ";
            cin>>year;
            for(i=0;i<n;i++){
                if(data[i].year>year){
                    check=1;
                    cout<<"\nBook "<<i+1<<":"<<endl;
                    cout<<"Title: "<<data[i].author<<endl;
                    cout<<"Author: "<<data[i].author<<endl;
                    cout<<"Year of Publishing: "<<data[i].year<<endl;
                }
            }
            if(check==0){
                cout<<"\nNo book is in the record that was published after year "<<year<<endl;
            }
        }
    }while(a!=3);
    delete[] data;
}