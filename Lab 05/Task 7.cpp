#include<iostream>
using namespace std;

class Product{
    int id;
    string name;
    int stock;
    public:
    Product(){}
    Product(int a, string b, int c){
        this->id=a;
        this->name=b;
        this->stock=c;
    }
    
    void set_id(int n){
        this->id=n;
    }
    
    int get_id(){
        return this->id;
    }
    
    string get_name(){
        return this->name;
    }
    
    void display(){
        cout<<"\nID: "<<this->id<<endl;
        cout<<"Name: "<<this->name<<endl;
        cout<<"Quantity in Stock: "<<this->stock<<endl;
    }
};

class Inventory{
    int size;
    Product* product;
    public:
    Inventory(int n):size(n){
        product=new Product[size];
        for(int i=0;i<size;i++){
            product[i].set_id(0);
        }
    }
    
    void add_product(Product p){
        bool check=false;
        for(int i=0;i<size;i++){
            if(product[i].get_id()==0){
                product[i]=p;
                check=true;
                cout<<"\nProduct Added"<<endl;
                break;
            }
        }
        if(check==false){
            cout<<"\nNot Enough Space"<<endl;
        }
    }
    
    void display_all_inventory(){
        for(int i=0;i<size;i++){
            if(product[i].get_id()!=0){
                product[i].display();
            }
            else{
                break;
            }
        }
    }
    
    void alphabetical_display(){
        int a=0;
        for(int i=0;product[i].get_id()!=0&&i<size;i++){
            a++;
        }
        Product* product2=new Product[a];
        for(int i=0;i<a;i++){
            product2[i]=product[i];
        }
        for(int j=0;j<a;j++){
            for(int i=0;i+1<a;i++){
                if(product2[i].get_name()>product2[i+1].get_name()){
                    Product temp=product2[i];
                    product2[i]=product2[i+1];
                    product2[i+1]=temp;
                }
            }
        }
        for(int i=0;i<a;i++){
            product2[i].display();
        }
        delete[] product2;
    }
    
    void search_product(int id){
        bool check=false;
        for(int i=0;i<size;i++){
            if(id=product[i].get_id()){
                product[i].display();
                check=true;
                break;
            }
        }
        if(check==false){
            cout<<"Product with this ID does not Exist"<<endl;
        }
    }
    
    ~Inventory(){
        delete[] product;
    }
};

int main(){
    int p,in;
    
    cout<<"Enter the total number of products: ";
    cin>>p;
    Product pro[p];
    cout<<"\n--- Products Data ---"<<endl;
    for(int i=0;i<p;i++){
        string a;
        int b;
        cout<<"\nEnter the Product "<<i+1<<" name: ";
        cin>>a;
        cout<<"Enter the number of product in stock: ";
        cin>>b;
        pro[i]=Product(i+1,a,b);
    }
    
    Inventory inventory(p);
    
    while(1){
        int n;
        cout<<"\n1. Display all Products\n2. Display Inventory Products\n3. Search Inventory Product by id\n4. Display Inventory Product in Alphabetical Order\n5. Add a Product\n6. Exit\nEnter the Corresponding Number: ";
        cin>>n;
        if(n==1){
            for(int i=0;i<p;i++){
                pro[i].display();
            }
        }
        else if(n==2){
            inventory.display_all_inventory();
        }
        else if(n==3){
            int id;
            cout<<"Enter the ID of the Product: ";
            cin>>id;
            inventory.search_product(id);
        }
        else if(n==4){
            inventory.alphabetical_display();
        }
        else if(n==5){
            int id;
            bool check=false;
            cout<<"Enter the ID of the Product: ";
            cin>>id;
            for(int i=0;i<p;i++){
                if(id==pro[i].get_id()){
                    inventory.add_product(pro[i]);
                    check=true;
                    break;
                }
            }
            if(check==false){
                cout<<"\nNo Product of this id exist"<<endl;
            }
        }
        else if(n==6){
            break;
        }
        else{
            cout<<"Enter a valid option"<<endl;
        }
    }
    
}