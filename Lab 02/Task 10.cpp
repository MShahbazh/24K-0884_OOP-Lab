#include<iostream>
using namespace std;

int*** Input(int*** arr, int x,int y,int z){
    int i,j,k;
        for(i=0;i<z;i++){
        arr[i]= new int*[y];
        for(j=0;j<y;j++){
            arr[i][j]= new int[x];
        }
    }
    
    cout<<"\n--- Input Data ---"<<endl;
    for(i=0;i<z;i++){
        cout<<"\nPlane "<<i+1<<":"<<endl;
        for(j=0;j<y;j++){
            cout<<"  Row "<<j+1<<endl;
            for(k=0;k<x;k++){
                cout<<"    Column "<<k+1<<": ";
                cin>>arr[i][j][k];
            }
        }
    }
    return arr;
}

void Display(int*** arr, int x, int y, int z){
    int i,j,k;
    cout<<"\n--- Display Data ---"<<endl;
    for(i=0;i<z;i++){
        cout<<"\nPlane "<<i+1<<":"<<endl;
        for(j=0;j<y;j++){
            for(k=0;k<x;k++){
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
}

void Free(int*** arr, int x, int y, int z){
    int i,j;
    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}

int main(){
    int a,b,c;
    cout<<"Enter the 1st axis or columns: ";
    cin>>a;
    cout<<"Enter the 2nd axis or rows: ";
    cin>>b;
    cout<<"Enter the 3rd axis: ";
    cin>>c;
    int*** array= new int**[c];
    Input(array,a,b,c);
    Display(array,a,b,c);
    Free(array,a,b,c);
}