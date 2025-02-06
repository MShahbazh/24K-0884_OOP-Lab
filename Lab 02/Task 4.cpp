#include<iostream>
using namespace std;

string* Input(string* array, int n){
    int i;
    cout<<"\n--- String Entry ---"<<endl;
    for(i=0;i<n;i++){
        cout<<"String "<<i+1<<": ";
        cin>>array[i];
    }
    return array;    
}

void Display(string* array, int n){
    int i;
    for(i=0;i<n;i++){
        cout<<"String "<<i+1<<": "<<array[i]<<endl;
    }
}

string* Sorting(string* array, int n){
    int i,j,k;
    string temp;
    for(k=0;k<n;k++){
        for(i=0;i+1<n;i++){
            j=0;
            while(array[i][j]==array[i+1][j]){
                j++;
            }
            if(array[i][j]>array[i+1][j]){
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
    return array;
}

int main(){
    int n,i,j,k;
    string temp;
    cout<<"Enter the Size of string array: ";
    cin>>n;
    string* array=new string[n];
    Input(array,n);
    cout<<"\n--- Display Strings ---"<<endl;
    Display(array,n);
    Sorting(array,n);
    cout<<"\n--- Sorted Display Strings ---"<<endl;
    Display(array,n);
    
}