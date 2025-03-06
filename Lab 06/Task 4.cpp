#include<iostream>
using namespace std;

class Account{
    int accountNumber;
    float balance;
    public:
    Account(int a, int b):accountNumber(a),balance(b){}
    void display_Account(){
        cout<<"Account Number: "<<this->accountNumber<<endl;
        cout<<"Balance: "<<this->balance<<endl;
    }
};

class SavingsAccount: public Account{
    float interestRate;
    public:
    SavingsAccount(int a, int b, float c):Account(a,b),interestRate(c){}
    void display_SavingsAccount(){
        this->display_Account();
        cout<<"Interest Rate: "<<this->interestRate<<endl;
    }
};

class CheckingAccount: public Account{
    float overdraftLimit;
    public:
    CheckingAccount(int a, int b, float c):Account(a,b),overdraftLimit(c){}
    void display_CheckingAccount(){
        this->display_Account();
        cout<<"Overdraft Limit: "<<this->overdraftLimit<<endl;
    }
};

int main(){
    SavingsAccount s(1001,45000,350);
    CheckingAccount c(1002,50000, 20000);
    cout<<"\n--- Savings Account Info ---"<<endl;
    s.display_SavingsAccount();
    cout<<"\n--- Checking Account Info ---"<<endl;
    c.display_CheckingAccount();
}