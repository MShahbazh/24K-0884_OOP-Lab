#include<iostream>
#include<exception>
using namespace std; 

class DatabaseException{
    public:
    DatabaseException(){}
    const char* what(){
        return "A database error occured";
    }
};

class ConnectionFailedException: public DatabaseException{};
class QueryTimeoutException: public DatabaseException{};

template<typename T>
class DatabaseConnector{
    public:
    DatabaseConnector(){}
    void display_connection_error(){
        throw ConnectionFailedException();
    }
    void display_query_timeout(){
        throw QueryTimeoutException();
    }
};

int main(){
    DatabaseConnector<int> d;
    try{
        d.display_connection_error();

    }
    catch(ConnectionFailedException& e){
        cout<<"Caught ConnectionFailedException: "<<e.what()<<endl;
    }

    try{
        d.display_query_timeout();
    }
    catch(QueryTimeoutException& e){
        cout<<"Caught QueryTimeoutException: "<<e.what()<<endl;
    }
}