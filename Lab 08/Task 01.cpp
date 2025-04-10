#include<iostream>
#include<cmath>
using namespace std;

class Complex{
    float real;
    float imaginary;
    public:
    Complex(){}
    Complex(float a, float b):real(a),imaginary(b){}
    Complex operator + (Complex& c){
        Complex result;
        result.real=this->real+c.real;
        result.imaginary=this->imaginary+c.imaginary;
        return result;
    }   
    Complex operator - (Complex& c){
        Complex result;
        result.real=this->real-c.real;
        result.imaginary=this->imaginary-c.imaginary;
        return result;
    }   
    Complex operator * (Complex& c){
        Complex result;
        result.real=this->real*c.real-this->imaginary*c.imaginary;
        result.imaginary=this->real*c.imaginary+this->imaginary*c.real;
        return result;
    }   
    Complex operator / (Complex& c){
        Complex result;
        float denominator=(c.real)*(c.real)+(c.imaginary)*(c.imaginary);
        result.real=(this->real*c.real+this->imaginary*c.imaginary)/denominator;
        result.imaginary=(this->imaginary*c.real-this->real*c.imaginary)/denominator;
        return result;
    }   
    friend ostream& operator <<(ostream& o, Complex& c);
    friend float magnitude(Complex& c);
};

ostream& operator<<(ostream& o, Complex& c){
    if(c.imaginary<0){
        o<<c.real<<" - "<<-c.imaginary<<"i"<<endl;
    }
    else{
        o<<c.real<<" + "<<c.imaginary<<"i"<<endl;
    }
    return o;
}

float magnitude(Complex& c){
    return pow((pow(c.real,2)+pow(c.imaginary,2)),0.5);
}

int main(){
    Complex c1(1,2);
    Complex c2(4,5);
    Complex c3=c1+c2;
    cout<<"\nAddition of both Complex Numbers(c1+c2): "<<endl;
    cout<<c3;
    c3=c1-c2;
    cout<<"\nSubtraction of both Complex Numbers(c1-c2): "<<endl;
    cout<<c3;
    c3=c1*c2;
    cout<<"\nMultiplication of both Complex Numbers(c1*c2): "<<endl;
    cout<<c3;
    c3=c1/c2;
    cout<<"\nDivision of both Complex Numbers(c1/c2): "<<endl;
    cout<<c3;
    cout<<"\nMagnitude of c3 is: "<<magnitude(c3)<<endl;
}