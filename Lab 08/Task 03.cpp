#include<iostream>
using namespace std;
 
class Vector2D{
    float x;
    float y;
    public:
    Vector2D(){}
    Vector2D(float a, float b):x(a),y(b){}
    Vector2D operator +(Vector2D& v){
        Vector2D result;
        result.x=this->x+v.x;
        result.y=this->y+v.y;
        return result;
    }
    Vector2D operator -(Vector2D& v){
        Vector2D result;
        result.x=this->x-v.x;
        result.y=this->y-v.y;
        return result;
    }
    Vector2D operator *(float a){
        Vector2D result;
        result.x=this->x*a;
        result.y=this->y*a;
        return result;
    }
    friend ostream& operator<<(ostream& o,Vector2D& v);
    friend float dotProduct(Vector2D& a,Vector2D& b);
};

ostream& operator<<(ostream& o, Vector2D& v){
    o<<"("<<v.x<<","<<v.y<<")"<<endl;
    return o;
}

float dotProduct(Vector2D& a,Vector2D& b){
    return a.x*b.x+a.y*b.y;
}

int main(){
    Vector2D v(1,2);
    Vector2D v1(3,4);
    Vector2D v2;
    cout<<v;
    cout<<v1;
    v2=v+v1;
    cout<<"Addition of v and v1 gives vector: ";
    cout<<v2;
    v2=v-v1;
    cout<<"Subtraction of v and v1 gives vector: ";
    cout<<v2;
    v2=v*2;
    cout<<"Multiplication of v and 2 gives vector: ";
    cout<<v2;
    cout<<"Dot Product of v and v1 is "<<dotProduct(v,v1);
}
