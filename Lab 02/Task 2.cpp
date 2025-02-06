#include<iostream>
using namespace std;

void Input_Data(int** mat1, int** mat2 , int r, int c){
    int i,j;
    cout<<"\n--- Input Data ---"<<endl;
    cout<<"\nMatrix 1 data: "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"Element at "<<i+1<<","<<j+1<<": ";
            cin>>mat1[i][j];
        }
    }
    cout<<"\nMatrix 2 data: "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"Element at "<<i+1<<","<<j+1<<": ";
            cin>>mat2[i][j];
        }
    }
}

void Display_Data(int** mat1, int** mat2, int r, int c){
    int i,j;
    cout<<"\n--- Display Data ---"<<endl;
    cout<<"\nMatrix 1 display: "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nMatrix 2 display: "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

void Addition_Subtraction(int** mat1, int** mat2, int r ,int c, int** add, int** sub){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            add[i][j]=mat1[i][j]+mat2[i][j];
            sub[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    cout<<"\n--- Display Addition and Subtraction Matrix ---"<<endl;
    cout<<"\nAddition"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<add[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nSubtraction"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<sub[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int r,c,i,j;
    
    cout<<"Enter the number of rows: ";
    cin>>r;
    cout<<"Enter the number of columns: ";
    cin>>c;

    int** mat1=new int*[r];
    int** mat2=new int*[r];
    for(i=0;i<r;i++){
        mat1[i]=new int[c];    
        mat2[i]=new int[c]; 
    }

    int** add=new int*[r];
    int** sub=new int*[r];
    for(i=0;i<r;i++){
        add[i]=new int[c];
        sub[i]=new int[c];
    }

    Input_Data(mat1,mat2,r,c);
    Display_Data(mat1,mat2,r,c);
    Addition_Subtraction(mat1,mat2,r,c,add,sub);
    
    for(i=0;i<r;i++){
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] add[i];
        delete[] sub[i];
    }
        delete[] mat1;
        delete[] mat2;
        delete[] add;
        delete[] sub;
    
}