#include<iostream>
using namespace std;

class Car{
    string brand;
    string model;
    int feulCapacity;
    float currentFeulLevel;
    public:
    void set_values(string a, string b, int x, int y){
        brand=a;
        model=b;
        feulCapacity=x;
        currentFeulLevel=y;
    }

    int get_feulCapacity(){
        return feulCapacity;
    }

    float checkFeulStatus(){
        return currentFeulLevel; 
    }

    void drive_car(float avg){
        float i;
        cout<<"\nEnter how many km's you have travelled till now: ";
        cin>>i;
        if(currentFeulLevel-i/avg<=0){
            currentFeulLevel=0;
        }
        else{
            currentFeulLevel-=i/avg;
        }
        
    }

    void refeulTank(int i){
        if(currentFeulLevel+i>=feulCapacity){
            currentFeulLevel=feulCapacity;
        }
        else{
            currentFeulLevel+=i;
        }
    }

};

int main(){
    string a,b;
    int i,j;
    float k;
    cout<<"\nEnter the Brand name: ";
    cin>>a;
    cout<<"Enter the model name: ";
    cin>>b;
    cout<<"Enter the Feul Capacity of your car: ";
    cin>>i;
    cout<<"Enter the current Feul Level of your car: ";
    cin>>j;
    cout<<"Enter the Feul Average of your Car (km/litre): ";
    cin>>k;
    Car car;
    car.set_values(a,b,i,j);
    do{
        cout<<"\n1. Drive the Car\n2. Check Feul Status\n3. Refeul Tank\n4. Stop the Car\nEnter the Corresponding Number: ";
        cin>>i;
        if(i==1){
            car.drive_car(k);
        }
        else if(i==2){
            cout<<"\nFeul Status: "<<car.checkFeulStatus()<<endl;
        }
        else if(i==3){
            cout<<"\nEnter the Feul to Refill: ";
            cin>>j;
            car.refeulTank(j);
        }
        else if(i==4){
            break;
        }
        if(car.checkFeulStatus()<50 && car.checkFeulStatus()>0){
            cout<<"\nCar Feul Level is below 50, refill it"<<endl;
        }
        else if(car.checkFeulStatus()<=0){
            cout<<"\nTank Empty | Car Stopped "<<endl;
            break;
        }
    }while(1);
}

