#include<iostream>
using namespace std;

struct Inventory{
    int product_ID;
    string name;
    int quantity;
    int price;
};

Inventory* Input(Inventory* data, int num){
    int i;
    cout<<"\n--- Input Data ---"<<endl;
    for(i=0;i<num;i++){
        cout<<"\nProduct "<<i+1<<" Data: "<<endl;
        cout<<"Enter the Product ID: ";
        cin>>data[i].product_ID;
        cout<<"Enter the Product name: ";
        cin>>data[i].name;
        cout<<"Enter the quantity of this product present in inventory: ";
        cin>>data[i].quantity;
        cout<<"Enter the price of 1 piece of this product: ";
        cin>>data[i].price;
    }
    return data;
}

void Display(Inventory* data, int num){
    int i;
    cout<<"\n--- Display Data ---"<<endl;;
    for(i=0;i<num;i++){
        cout<<"\nProduct "<<i+1<<" Data: "<<endl;
        cout<<"   Product ID: "<<data[i].product_ID<<endl;
        cout<<"   Name: "<<data[i].name<<endl;
        cout<<"   Quantity: "<<data[i].quantity<<endl;
        cout<<"   Price: "<<data[i].price<<endl;
    }
}

void Value(Inventory* data, int num){
    int i,value=0;
    for(i=0;i<num;i++){
        value=value+data[i].quantity*data[i].price;
    }
    cout<<"\nTotal Value of the Inventory is "<<value<<endl;
}

void Free(Inventory* data){
    delete[] data;
}

int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    Inventory* Data= new Inventory[n];
    Input(Data,n);
    Display(Data,n);
    Value(Data,n);
    Free(Data);
}