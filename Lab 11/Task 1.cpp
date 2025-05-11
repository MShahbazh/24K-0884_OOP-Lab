#include<iostream>
#include<exception>
#include<sstream>
using namespace std;

template<typename T>
class Matrix;

template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& m);

class DimensionMismatchException:public exception{
    string error;
    public:
    DimensionMismatchException(){}
    DimensionMismatchException(int r1, int c1, int r2, int c2){
        ostringstream err;
        err<<"Dimension Mismatch: Matrix 1 is ("<<r1<<"x"<<c1<<") while Matrix 2 is ("<<r2<<"x"<<c2<<")";
        error=err.str();
    }

    const char* what() const noexcept override{
        return error.c_str();
    }

};


template<typename T>
class Matrix{
    int row; 
    int col;
    T** values;
    public:
    Matrix(){}
    Matrix(int r, int c):row(r),col(c){
        values=new T*[row];
        for(int i=0;i<row;i++){
            values[i]=new T[col];
        }
    }
    void add_values(){
        for(int i=0;i<row;i++){
            cout<<"--- ROW"<<i+1<<" ---"<<endl;
            for(int j=0;j<col;j++){
                cout<<"R"<<i+1<<" C"<<j+1<<" Value: ";
                cin>>values[i][j];
                cout<<endl;
            }
        }
    }
    Matrix<T> operator+(const Matrix<T> m){
        if(this->row!=m.row||this->col!=m.col){
            throw DimensionMismatchException(this->row, this->col, m.row, m.col);
        }
        Matrix<T> res(row,col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res.values[i][j]=this->values[i][j]+m.values[i][j];
            }
        }
        return res;
    }

    friend ostream& operator<< <>(ostream& out, const Matrix<T>& m);
};

template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++){
            cout<<m.values[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;
}



int main(){
    Matrix<int> m(2,3);
    Matrix<int> m1(2,2);
    cout<<"---- Matrix 1 Values ----"<<endl;
    m.add_values();
    cout<<"---- Matrix 2 Values ----"<<endl;
    m1.add_values();
    Matrix<int> m3(2,2);
    try{
        m3=m+m1;
        cout<<m3;

    }
    catch(exception& e){
        cout<<"Exception Caught: "<<e.what()<<endl;
    }
}