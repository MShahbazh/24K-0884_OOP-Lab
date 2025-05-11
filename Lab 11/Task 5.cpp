#include<iostream>
#include<exception>
using namespace std;

class NegativeStockException: public exception{
    public:
    const char* what() const noexcept override{
        return "Negative Stock Value";
    }
};
class OverCapacityException: public exception{
    public:
    const char* what() const noexcept override{
        return "Stock Exceeds Maximum Capacity";
    }
};

template<typename T>
class InventoryItem{
    T stock;
    T capacity;
    public:
    InventoryItem(){}
    InventoryItem(T s, T c):stock(s),capacity(c){}
    void set_stock(T s){
        if(s<0){
             throw NegativeStockException();
        }
        if(s>capacity){
            throw OverCapacityException();
        }
        stock=s;
    }
};

int main(){
    InventoryItem<int> t(10,2000);
    try{
        t.set_stock(3000);
    }
    catch(const NegativeStockException& e){
        cout<<"Caught NegativeStockException - what(): "<<e.what()<<endl; 
    }
    catch(const OverCapacityException& e){
        cout<<"Caught OverCapacityException - what(): "<<e.what()<<endl; 
    }
}