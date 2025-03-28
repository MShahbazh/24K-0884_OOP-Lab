#include<iostream>
using namespace std;

class Product{
    int productID;
    string productName;
    int stockQuantity;
    protected:
    float price;
    public:
    Product(){}
    Product(int a, string  b, float c , int d):productID(a),productName(b),price(c),stockQuantity(d){}
    virtual void applyDiscount(float a){
        price-=(a/100)*price;
    }
    virtual void calculateTotalPrice(int a){
        cout<<"Total Price is: "<<a*price<<endl;
    }
    virtual void displayProductInfo(){
        cout<<"\nProduct ID: "<<productID<<endl;
        cout<<"Product Name: "<<productName<<endl;
        cout<<"Price of one Item: "<<price<<endl;
        cout<<"Stock Quantity: "<<stockQuantity<<endl;
    }
    float operator+(const Product& p){
        return this->stockQuantity*this->price+p.stockQuantity*p.price;
    }
    void operator<<(const Product &p){
        cout<<"\nProduct ID: "<<p.productID<<endl;
        cout<<"Product Name: "<<p.productName<<endl;
        cout<<"Stock Quantity: "<<p.stockQuantity<<endl;
        cout<<"Price per piece: "<<p.price<<endl;
    }
};

class Electronics: public Product{
    int warrantyPeriod;
    string brand;
    public:
    Electronics(){}
    Electronics(int a, string  b, float c , int d, int e, string f):Product(a,b,c,d),warrantyPeriod(e),brand(f){}
    void displayProductInfo() override{
        Product::displayProductInfo();
        cout<<"Warranty Period: "<<warrantyPeriod<<endl;
        cout<<"Brand Name: "<<brand<<endl;
    }
};

class Clothing: public Product{
    int size;
    string color;
    string fabricMaterial;
    public:
    Clothing(){}
    Clothing(int a, string  b, float c , int d, int e, string f, string g):Product(a,b,c,d),size(e),color(f),fabricMaterial(g){}
    void applyDiscount(float a) override{
        price-=(a/100)*price;
        cout<<"Seasonal Discount Applied"<<endl;
    }
};

class FoodItem:public Product{
    string expirationDate;
    int calories;
    public:
    FoodItem(){}
    FoodItem(int a, string  b, float c , int d, string e, int f):Product(a,b,c,d),expirationDate(e),calories(f){}
    void calculateTotalPrice(int a) override{
        if(a>=10)
        price-=price*a*0.9;
        else
        Product::calculateTotalPrice(a);
    } 
};

class Book: public Product{
    string author;
    string genre;
    public:
    Book(){}
    Book(int a, string  b, float c , int d, string e, string f):Product(a,b,c,d),author(e),genre(f){}
    void displayProductInfo() override{
        Product::displayProductInfo();
        cout<<"Author: "<<author<<endl;
        cout<<"Genre: "<<genre<<endl;
    }
};


int main(){
    Product* p1=new Electronics(100,"Lights",200.10,25,100,"Brand 1");
    Product* p2=new Electronics(101,"Lights 2",50,45,200,"Brand 2");

    p1->applyDiscount(24);
    p2->displayProductInfo();
    (*p1)<<(*p2);
    cout<<(*p1)+(*p2);

    p1=new Clothing(102,"CLoth 1",140,15,7,"Blue","Cotton");
    p1->applyDiscount(34);
    p1->displayProductInfo();

    p2=new FoodItem(103,"Cakes",120,10,"23-09-2025",200);
    p2->calculateTotalPrice(34);
    p2->displayProductInfo();

    p1=new Book(104,"Book 1",30,5,"Author 1","Action");
    p1->displayProductInfo();

}