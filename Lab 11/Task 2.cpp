#include<iostream>
#include<exception>
#include<vector>
using namespace std;


class QueueUnderFLowException: public exception{
    public:
    const char* what() const noexcept override{
        return "Queue Underflow";
    }
};
class QueueOverFLowException: public exception{
    public:
    const char* what() const noexcept override{
        return "Queue Overflow";
    }
};

template<typename T>
class Queue{
    int size;
    vector<T> data;
    public:
    Queue(int s):size(s){}
    void enqueue(T s){
        if(data.size()>size){
            cout<<"Attempting to enqueue in the full queue"<<endl;
            throw QueueOverFLowException();
        }
        data.push_back(s);
        size++;
    }
    void dequeue(){
        if(data.size()==0){
            cout<<"Attempting to dequeue an empty queue"<<endl;
            throw QueueUnderFLowException();
        }
        data.erase(data.begin());
        size--;
    }
};  

int main(){
    Queue<int> Q(3);
    try{
        Q.enqueue(1);
        Q.enqueue(2);
        Q.enqueue(3);
        Q.enqueue(4);
    }
    catch (const QueueOverFLowException& e){
        cout << "Caught QueueOverflowException - what(): "<<e.what()<<endl;
    } 
    try{
        Q.dequeue();
        Q.dequeue();
        Q.dequeue();
        Q.dequeue();
        Q.dequeue();
    }
     catch (const QueueUnderFLowException& e) {
        cout << "Caught QueueUnderflowException - what(): " <<e.what()<<endl;
    } 
}