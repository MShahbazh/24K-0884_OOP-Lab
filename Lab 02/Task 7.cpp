#include<iostream>
using namespace std;

int** Input_matrix1(int** mat1, int r1,int c1){
    int i,j;
    cout<<"\n--- Input Values ---"<<endl;
    for(i=0;i<r1;i++){
        mat1[i]=new int[c1];
    }
    cout<<"\n--- Matrix 1 ---"<<endl;
    for(i=0;i<r1;i++){
        cout<<"\nRow "<<i+1<<": "<<endl;
        for(j=0;j<c1;j++){
            cout<<"  Column "<<j+1<<": ";
            cin>>mat1[i][j];
        }
    }
    return mat1;
}

int** Input_matrix2(int** mat2,int r2,int c2){
    int i,j;
    for(i=0;i<r2;i++){
        mat2[i]=new int[c2];
    }
    cout<<"\n-- Matrix 2 ---"<<endl;
    for(i=0;i<r2;i++){
        cout<<"\nRow "<<i+1<<": "<<endl;
        for(j=0;j<c2;j++){
            cout<<"  Column "<<j+1<<": ";
            cin>>mat2[i][j];
        }
    }
    return mat2;
}

void Display_Matrices(int** mat1, int** mat2, int r1, int c1, int r2, int c2){
    int i,j;
    cout<<"\n--- Display Matrices ---"<<endl;
    cout<<"\n--- Matrix 1 ---"<<endl;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n--- Matrix 2 ---"<<endl;
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
}

int** Multiplication(int** mat1, int** mat2, int** prod, int r1, int c1, int r2, int c2){
    // c1 = r2
    int i,j,k;
    for(i=0;i<r1;i++){
        prod[i]= new int[c2];
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            prod[i][j]=0;
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<c1;k++){
                prod[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return prod;
}

void Display_multiplication(int** prod, int r1, int c2){
    int i,j;
    cout<<"\n--- Result Matrix ---"<<endl;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            cout<<prod[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Free(int** mat1, int** mat2, int** prod, int r1, int r2){
    int i;
    for(i=0;i<r1;i++){
        delete[] mat1[i];
        delete[] prod[i];
    }
    for(i=0;i<r2;i++){
        delete[] mat2[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] prod;
}

int main(){
    int r1,c1,r2,c2;
    cout<<"Enter the Row of first matrix: ";
    cin>>r1;
    cout<<"Enter the Column number of first matrix: ";
    cin>>c1;
    cout<<"Enter the Row number of second matrix: ";
    cin>>r2;
    cout<<"Enter the Column number of second matrix: ";
    cin>>c2;
    if(c1==r2){
        int** matrix1=new int*[r1];
        int** matrix2=new int*[r2];
        int** multiply = new int*[r1];
        Input_matrix1(matrix1,r1,c1);
        Input_matrix2(matrix2,r2,c2);
        Display_Matrices(matrix1,matrix2,r1,c1,r2,c2);
        Multiplication(matrix1,matrix2,multiply,r1,c1,r2,c2);
        Display_multiplication(multiply,r1,c2);
        Free(matrix1, matrix2, multiply,r1,r2);
    }
    else{
        cout<<"\nMatrix Multiplication not possible"<<endl;
    }
}