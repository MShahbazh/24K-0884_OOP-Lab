#include<iostream>
#include<fstream>
using namespace std;

class InventoryItem{
    int itemID;
    char itemName[20];
    ifstream input;
    ofstream output;
    string name;
    public:
    InventoryItem(string name):name(name){}
    InventoryItem(int itemID, char itemName[20],string name):name(name),itemID(itemID){\
        int i;
        for(i=0;itemName[i]!='\0';i++){
            this->itemName[i]=itemName[i];
        }
        this->itemName[i]='\0';
        output.open(name,ios::binary);
        char ch=itemID;
        output.put(ch);
        output.write(itemName,20);
        output.close();
    }

    void readfromfile(){
        input.open(name,ios::binary);
        char ch=input.get();
        itemID=ch;
        input.read(itemName,20);
        input.close();
    }

    void display(){
        cout<<"Item ID: "<<itemID<<endl;
        cout<<"ItemName: "<<itemName<<endl;
    }
};

int main(){
    char item[20]={'W','e','a','p','o','n','s','\0'};
    InventoryItem object1(100,item,"inventory.dat");
    InventoryItem object2("inventory.dat");
    object2.readfromfile();
    object2.display();
}