#include<iostream>
using namespace std;

class Account{
    long long account_number;
    float balance;
    public:
    Account(){}
    Account(long long a, float b):account_number(a),balance(b){}
    friend class Manager;
    friend void transfer_funds(Account& a, Account& b,float c);
};

class Manager{
    public:
    void display_account(Account& a){
        cout<<"\nAccount Number: "<<a.account_number<<endl;
        cout<<"Account Balance: "<<a.balance<<endl;
    }
    void deposit(Account& a, float b){
        a.balance+=b;
        cout<<"Account of "<<b<<" Deposited Successfully"<<endl;
    }
    void withdraw(Account& a, float b){
        if(b>a.balance) cout<<"Not enough Balance"<<endl;
        else{
            a.balance-=b;
            cout<<"Account of "<<b<<" Deposited Successfully"<<endl;
        }
    }
};

void transfer_funds(Account& a, Account& b,float c){
    if(c>a.balance){
        cout<<"Cannot transfer amount "<<c<<" from account number "<<a.account_number<<" to "<<b.account_number<<endl;
    }
    else{
        a.balance-=c;
        b.balance+=c;
        cout<<"Amount of "<<c<<" transferred from account number "<<a.account_number<<" to "<<b.account_number<<endl;
    }
}

int main(){
    Account a(1001,500);
    Account b(2001,2500);
    Manager m;
    m.deposit(a,200);
    m.withdraw(b,100);
    transfer_funds(b,a,2000);
    m.display_account(a);
    m.display_account(b);
}

