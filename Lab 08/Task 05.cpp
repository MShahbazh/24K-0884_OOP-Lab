#include<iostream>
using namespace std;

class Matrix2x2{
    float top_left;
    float top_right;
    float bottom_left;
    float bottom_right;
    public:
    Matrix2x2(){}
    Matrix2x2(float a, float b, float c ,float d):top_left(a),top_right(b),bottom_left(c),bottom_right(d){}
    Matrix2x2 operator +(Matrix2x2& m){
        Matrix2x2 result;
        result.top_left=this->top_left+m.top_left;
        result.top_right=this->top_right+m.top_right;
        result.bottom_left=this->bottom_left+m.bottom_left;
        result.bottom_right=this->bottom_right+m.bottom_right;
        return result;
    }
    Matrix2x2 operator -(Matrix2x2& m){
        Matrix2x2 result;
        result.top_left=this->top_left-m.top_left;
        result.top_right=this->top_right-m.top_right;
        result.bottom_left=this->bottom_left-m.bottom_left;
        result.bottom_right=this->bottom_right-m.bottom_right;
        return result;
    }
    Matrix2x2 operator *(Matrix2x2& m){
        Matrix2x2 result;
        result.top_left=this->top_left*m.top_left+this->top_right*m.bottom_left;
        result.top_right=this->top_left*m.top_right+this->top_right*m.bottom_right;
        result.bottom_left=this->bottom_left*m.top_left+this->bottom_right*m.bottom_left;
        result.bottom_right=this->bottom_left*m.top_right+this->bottom_right*m.bottom_right;
        return result;
    }
    friend ostream& operator<<(ostream& o, Matrix2x2& m);
    friend float determinant(Matrix2x2& m);
    friend class MatrixHelper;
};

class MatrixHelper{
    public:
    void update_top_left(Matrix2x2& m, float a){
        m.top_left=a;
    }
    void update_top_right(Matrix2x2& m, float a){
        m.top_right=a;
    }
    void update_bottom_left(Matrix2x2& m, float a){
        m.bottom_left=a;
    }
    void update_bottom_right(Matrix2x2& m, float a){
        m.bottom_right=a;
    }
};

ostream& operator<<(ostream& o, Matrix2x2& m){
    o<<"| "<<m.top_left<<" "<<m.top_right<<" |"<<endl;
    o<<"| "<<m.bottom_left<<" "<<m.bottom_right<<" |"<<endl;
    return o;
}

float determinant(Matrix2x2& m){
    return m.top_left*m.bottom_right-m.top_right*m.bottom_left;
}

int main(){
    Matrix2x2 m1(1,2,3,4);
    Matrix2x2 m2(4,5,6,7);
    Matrix2x2 m3;
    cout<<m1;
    cout<<m2;
    cout<<"Addition of both Matrices: "<<endl;
    m3=m1+m2;
    cout<<m3;
    cout<<"Subtraction of both Matrices: "<<endl;
    m3=m1-m2;
    cout<<m3;
    cout<<"Multiplication of both Matrices: "<<endl;
    m3=m1*m2;
    cout<<m3;
    cout<<"Determinant of Matrix 3: ";
    cout<<determinant(m3);
}