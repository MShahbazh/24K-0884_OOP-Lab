#include<iostream>
#include<exception>
using namespace std;

class InvalidTemperatureException:public exception{
    public:
    const char* what() const noexcept override{
        return "Invalid temperature";
    }
};

template <typename T>
T convertToFahrenheit(T c){
    cout<<"Attempting to convert "<<c<<" ...."<<endl;
    if(c<-273.15){
        throw InvalidTemperatureException();
    }
    return (c*9/5)+32; 
}

int main(){
    try{
        float c=-300;
        float f=convertToFahrenheit(c);
        cout<<f<<endl;
    }
    catch(InvalidTemperatureException& e){
        cout<<"Caught InvalidTemperatureException -what(): "<<e.what()<<endl;
    }


}