#include<iostream>
using namespace std;

int main(){
    int n,i,sum=0;
    int* ptr;
    cout<<"Size of the array: ";
    cin>>n;
    int* arr=new int[n];
    for(i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>arr[i];
    }
    ptr=arr;
    cout<<"\nArray: "<<endl;
    for(i=0;i<n;i++){
        cout<<*(ptr+i)<<" ";
        sum=sum+*(ptr+i);
    }
    cout<<"\nThe Sum of array elements is "<<sum;
    delete[] arr,ptr;
}