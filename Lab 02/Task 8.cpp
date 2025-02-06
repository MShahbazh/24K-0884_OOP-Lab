#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter the Size of the array: ";
    cin>>n;
    int** array=new int*[n];
    for(i=0;i<n;i++){
        array[i]=new int;
    }
    for(i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" Element: ";
        cin>>array[i][0];
    }
    cout<<"\nThe Array you entered is: "<<endl;
    for(i=0;i<n;i++){
        cout<<array[i][0]<<" ";
    }
    for(i=0;i<n;i++){
        delete[] array[i];
    }
    delete[] array;
}