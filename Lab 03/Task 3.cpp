#include<iostream>
using namespace std;

class Library{
    string bookList[100];
    string borrowedBooks[100];
    string availableBooks[100];
    public:
    void set_values(){
        int i;
        for(i=0;i<100;i++){
            bookList[i]="NULL";
            borrowedBooks[i]="NULL";
            availableBooks[i]="NULL";
        }
    }

    void add_book(string book){
        int i;
        bool present=false;
        for(i=0;i<100;i++){
            if(bookList[i]==book){
                present=true;
                break;
            }
        }
        if(present==false){
            for(i=0;i<100;i++){
                if(bookList[i]=="NULL"){
                    bookList[i]=book;
                    availableBooks[i]=book;
                    cout<<"\nBook Added Succesfully"<<endl;
                    break;
                }
            }
        }
        else{
            cout<<"\nThis book is already present in the Library"<<endl;
        }
    }

    void remove_book(string book){
        int i,j;
        bool present=false;
        for(i=0;bookList[i]!="NULL";i++){
            if(bookList[i]==book){
                present=true;
            }
        }
        if(present==true){
            for(i=0;i<100;i++){
                if(bookList[i]==book){
                    bookList[i]="NULL";
                    for(j=i;bookList[j+1]!="NULL";j++){
                        string temp=bookList[j];
                        bookList[j]=bookList[j+1];
                        bookList[j+1]=temp;
                    }
                }
            }
    
            for(i=0;i<100;i++){
                if(borrowedBooks[i]==book){
                    borrowedBooks[i]="NULL";
                    for(j=i;borrowedBooks[j+1]!="NULL";j++){
                        string temp=borrowedBooks[j];
                        borrowedBooks[j]=borrowedBooks[j+1];
                        borrowedBooks[j+1]=temp;
                    }
                }
            }
    
            for(i=0;i<100;i++){
                if(availableBooks[i]==book){
                    availableBooks[i]="NULL";
                    for(j=i;availableBooks[j+1]!="NULL";j++){
                        string temp=availableBooks[j];
                        availableBooks[j]=availableBooks[j+1];
                        availableBooks[j+1]=temp;
                    }
                }
            }
        }
        else{
            cout<<"\nThis book is already not in our Library"<<endl;
        }
    }

    void Display_bookList(){
        int i;
        if(bookList[0]=="NULL"){
            cout<<"\nBook List is empty | You have to Fill it"<<endl;

        }
        else{
            cout<<"\n--- Book List ---"<<endl;
            for(i=0;i<100;i++){
                if(bookList[i]!="NULL"){
                    cout<<i+1<<". "<<bookList[i]<<endl;
                }
            }
        }
    }

    void Display_borrowedBooks(){
        int i;
        if(borrowedBooks[0]=="NULL" && bookList[0]=="NULL"){
            cout<<"\nBook List is empty"<<endl;
        }
        else if(borrowedBooks[0]=="NULL" && bookList[0]!="NULL"){
            cout<<"\nNo one has borrowed any book | Expand it by diving into world of Imagination!"<<endl;
        }
        else{      
            cout<<"\n--- Borrowed Book List ---"<<endl;
            for(i=0;i<100;i++){
                if(borrowedBooks[i]!="NULL"){
                    cout<<i+1<<". "<<borrowedBooks[i]<<endl;
                }
            }
        }
    }

    void Display_availableBooks(){
        int i;
        if(availableBooks[0]=="NULL" && bookList[0]!="NULL"){
            cout<<"\nWow, Looks like we got all readers | No book available right now"<<endl;
        }
        else if(availableBooks[0]=="NULL" && bookList[0]=="NULL"){
            cout<<"\nFill the Book List First"<<endl;
        }
        else if(availableBooks[0]!="NULL"&&bookList[0]!="NULL"){
            cout<<"\n--- Available Book List ---"<<endl;
            for(i=0;i<100;i++){
                if(availableBooks[i]!="NULL"){
                    cout<<i+1<<". "<<availableBooks[i]<<endl;
                }
            }
        }
    }

    void Lend_book(string book){
        int i,j,k;
        bool present=false;
        bool available=false;
        for(i=0;bookList[i]!="NULL";i++){
            if(bookList[i]==book){
                present=true;
            }
        }
        if(present==true){
            for(i=0;availableBooks[i]!="NULL";i++){
                if(availableBooks[i]==book){
                    available=true;
                }
            }
            if(available==true){
                for(i=0;availableBooks[i]!="NULL";i++){
                    if(availableBooks[i]==book){
                        availableBooks[i]="NULL";
                        for(j=i;availableBooks[j+1]!="NULL";j++){
                            availableBooks[j]=availableBooks[j+1];
                            availableBooks[j+1]="NULL";
                        }
                        for(k=0;k<100;k++){
                            if(borrowedBooks[k]=="NULL"){
                                borrowedBooks[k]=book;
                                break;
                            }
                        }
                    }
                }
                cout<<"\nBook Borrowed Succesfully"<<endl;
            }
            else{
                cout<<"\nBook not available"<<endl;
            }
        }
        else{
            cout<<"\nBook is not in library | Wrong book"<<endl;
        }
    }

    void return_book(string book){
        int i,j;
        bool present=false;
        bool present2=false;
        for(i=0;bookList[i]!="NULL";i++){
            if(bookList[i]==book){
                present=true;
                break;
            }
        }
        if(present==true){
            for(i=0;borrowedBooks[i]!="NULL";i++){
                if(borrowedBooks[i]==book){
                    present2=true;
                    break;
                }
            }
            if(present2==true){
                for(i=0;i<100;i++){
                    if(borrowedBooks[i]==book){
                        borrowedBooks[i]="NULL";
                        for(j=i;borrowedBooks[j+1]!="NULL";j++){
                            borrowedBooks[j]=borrowedBooks[j+1];
                            borrowedBooks[j+1]="NULL";
                        }
                    }
                }
                for(i=0;i<100;i++){
                    if(availableBooks[i]=="NULL"){
                        availableBooks[i]=book;
                        break;
                    }
                }
            }
        }
        else{
            cout<<"\nThis book is not ours"<<endl;
        }
    }

};

int main(){
    int i;
    string book;
    Library library;
    library.set_values();
    do{
        cout<<"\n--- Library Management System ---\n1. Display Book List\n2. Add a book in book list\n3. Remove a book from book list\n4. Display Borrowed Books List\n5. Display Available Books List\n6. Borrow a book\n7. Return a book\n8. Exit\nEnter the Corresponding Number: ";
        cin>>i;
        if(i==1){
            library.Display_bookList();
        }
        else if(i==2){
            cout<<"\nEnter the the book name to add(it must be unique): ";
            cin>>book;
            library.add_book(book);
        }
        else if(i==3){
            cout<<"Enter the book name to remove: ";
            cin>>book;
            library.remove_book(book);
        }
        else if(i==4){
            library.Display_borrowedBooks();
        }
        else if(i==5){
            library.Display_availableBooks();
        }
        else if(i==6){
            cout<<"\nEnter the book name to borrow: ";
            cin>>book;
            library.Lend_book(book);
        }
        else if(i==7){
            cout<<"\nEnter the book name to return: ";
            cin>>book;
            library.return_book(book);
        }
        else if(i==8){
            break;
        }
        else{
            cout<<"\nEnter a Valid Option"<<endl;
        }
    }while(1);
}
