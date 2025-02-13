#include<iostream>
using namespace std;

class Transaction_History{
    string Date;
    int transaction_amount;
    int Balance_After;
    string status;
    public:
    void set_history_values(string date, int amount, int after , int n){
        Date=date;
        transaction_amount=amount;
        Balance_After=after;
        if(n==-1){
            status="Spent amount: ";
        }
        else if(n==1){
            status="Added amount: ";
        }
        else if(n==0){
            status="NULL";
        }
    }

    string get_date(){
        return Date;
    }
    
    int get_amount(){
        return transaction_amount;
    }

    int get_after(){
        return Balance_After;
    }

    string get_status(){
        return status;
    }

};

class Wallet{
    string owner_Name;
    int total_Balance;
    Transaction_History* history=new Transaction_History[100];
    public: 
    void set_wallet_values(string name, int balance){
        int i;
        owner_Name=name;
        total_Balance=balance;
        for(i=0;i<100;i++){
            history[i].set_history_values("NULL",0,0,0);
        }
    }

    string getname(){
        return owner_Name;
    }

    void set_new_balance(int n){
        total_Balance=n;
    }

    int get_balance(){
        return total_Balance;
    }

    void Add_history(string date, int after, int amount, int n){
        int i;
        for(i=0;i<100;i++){
            if(history[i].get_date()=="NULL"){
                history[i].set_history_values(date,amount,after,n);
                break;  
            }
        }
    }

    void Display_history(){
        int i,check=0;
        for(i=0;i<100;i++){
           if(history[i].get_date()!="NULL"){
                cout<<"\nDate: "<<history[i].get_date()<<" | "<<history[i].get_status()<<" "<<history[i]. get_amount()<<" | "<<" Balance after this: "<<history[i].get_after()<<endl;
                check=1;
           }
        }
        if(check==0){
            cout<<"\nTransaction History Empty"<<endl;
        }
    }

    void Free(){
        delete[] history;
    }
};

int main(){
    int i,amount;
    string date;
    Wallet Owner1;
    cout<<"\nEnter the initial amount Saad has in its bank account: ";
    cin>>amount;
    Owner1.set_wallet_values("Saad",amount);
    cout<<"\n--- "<<Owner1.getname()<<"'s Transaction System ---"<<endl;
    do{
        cout<<"\n1.Add Amount\n2.Spend Amount\n3.Display Transaction History\n4.Display Current Balance\n5.Exit the program\nEnter the corresponding number: ";
        cin>>i;
        if(i==1){
            cout<<"\nEnter the amount you want to add: ";
            cin>>amount;
            cout<<"Enter the Date(MUST): ";
            cin>>date;
                Owner1.set_new_balance(Owner1.get_balance()+amount);
                Owner1.Add_history(date,Owner1.get_balance(),amount,1);
        }

        else if(i==2){
            cout<<"\nEnter the amount you want to spend: ";
            cin>>amount;
            cout<<"Enter the Date(MUST): ";
            cin>>date;
            if(Owner1.get_balance()-amount>=0){
                Owner1.set_new_balance(Owner1.get_balance()-amount);
                Owner1.Add_history(date,Owner1.get_balance(),amount,1);
            }
            else{
                    cout<<"\nNot enough Amount in the account"<<endl;
            }
        }
        
        else if(i==3){
            Owner1.Display_history();
        }

        else if(i==4){
            cout<<"\nCurrent Balance: "<<Owner1.get_balance()<<endl;
        }
        
        else if(i==5){
            break;
        }
        
        else{
            cout<<"\nChoose between options 1 and 5"<<endl;
        }
    }while(1);
    Owner1.Free();
}