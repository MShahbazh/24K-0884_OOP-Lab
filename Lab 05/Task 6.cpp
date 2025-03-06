#include<iostream>
using namespace std;

class Level{
    int number;
    string title;
    public:
    Level(){}
    Level(int a, string b):number(a),title(b){}
    void display(){
        cout<<"\nLevel Number: "<<this->number<<endl;
        cout<<"Level Title: "<<this->title<<endl;
    }
  
};

class VideoGame{
    string title;
    string genre;
    int size;
    Level* levels;
    public:
    VideoGame(string a, string b):title(a),genre(b){}
    
    void add_levels(){
        int n;
        cout<<"How many levels does this game contains: ";
        cin>>n;
        this->size=n;
        levels=new Level[size];
        cout<<"\n--- Levels Info ---"<<endl;
        for(int i=0;i<size;i++){
            int a;
            string b;
            cout<<"Enter the Level "<<i+1<<" Title: ";
            cin>>b;
            levels[i]=Level(i+1,b);
        }
    }
    void display(){
        cout<<"\nTitle: "<<this->title<<endl;
        cout<<"Genre: "<<this->genre<<endl;
        for(int i=0;i<size;i++){
            levels[i].display();
        }
    }
};

int main(){
    VideoGame v("Age of Empires 2","Strategy");
    v.add_levels();
    v.display();
}