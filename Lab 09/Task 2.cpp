#include<iostream>
using namespace std;

class MenuItem{
    string dishname;
    double price;
    public:
    MenuItem(){}
    MenuItem(string a, double b):dishname(a),price(b){}

    string get_dishname(){
        return dishname;
    }

    double get_price(){
        return price;
    }

    virtual void showDetails()=0;
    virtual void prepare()=0;
};

class Appetizer:public MenuItem{
    public:
    Appetizer(){}

    Appetizer(string a, double b):MenuItem(a,b){}

    void showDetails(){
        cout<<"Appetizer: "<<this->get_dishname()<<endl;
        cout<<"Price: "<<this->get_price()<<endl;
    }

    void prepare(){
        cout<<"Preparing Appetizer "<<this->get_dishname()<<endl;
    }
};

class MainCourse:public MenuItem{
    public:
    MainCourse(){}

    MainCourse(string a, double b):MenuItem(a,b){}

    void showDetails(){
        cout<<"Main Course: "<<this->get_dishname()<<endl;
        cout<<"Price: "<<this->get_price()<<endl;
    }

    void prepare(){
        cout<<"Preparing a Main Course "<<this->get_dishname()<<endl;
    }

};

int main(){

    Appetizer App("Chicken Wings",2000);
    MainCourse Main("Biryani",5000);
    MenuItem* item;

    item=&App;
    item->showDetails();
    item->prepare();

    item=&Main;
    item->showDetails();
    item->prepare();

}
