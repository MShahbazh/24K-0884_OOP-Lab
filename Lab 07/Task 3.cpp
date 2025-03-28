#include<iostream>
using namespace std;

class Ticket{
    int ticketID;
    string passengerName;
    int price;
    string date;
    string destination;
    public:
    Ticket(){}
    Ticket(int a, string b, int c, string d, string e):ticketID(a),passengerName(b),price(c),date(d),destination(e){}
    virtual void reserve(){
        cout<<"Ticket Reserved"<<endl;
    }
    void cancel(){
        cout<<"Ticket Cancelled"<<endl;
    }
    virtual void displayTicketInfo(){
        cout<<"Ticket ID: "<<ticketID<<endl;
        cout<<"Passenger Name: "<<passengerName<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Destination: "<<destination<<endl;
    }
};

class FlightTicket: public Ticket{
    string airlineName;
    int flightNumber;
    string seatClass;
    public:
    FlightTicket(){}
    FlightTicket(int a, string b, int c, string d, string e, string f,int g, string h):Ticket(a,b,c,d,e),airlineName(f),flightNumber(g),seatClass(h){}
    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout<<"Airline Number: "<<airlineName<<endl;
        cout<<"Flight Number: "<<flightNumber<<endl;
        cout<<"Seat Class: "<<seatClass<<endl;
    }
};

class TrainTicket: public Ticket{
    int trainNumber;
    string coachType;
    string departureTime;
    public:
    TrainTicket(){}
    TrainTicket(int a, string b, int c, string d, string e,int f, string g, string h):Ticket(a,b,c,d,e),trainNumber(f),coachType(g),departureTime(h){}
    void reserve() override{
        cout<<"Train Ticket Reserved"<<endl;
    }
};

class ConcertTicket:public Ticket{
    string artistName;
    string venue;
    string seatType;
    public:
    ConcertTicket(){}
    ConcertTicket(int a, string b, int c, string d, string e, string f, string g , string h):Ticket(a,b,c,d,e),artistName(f),venue(g),seatType(h){}
    void displayTicketInfo() override{
        cout<<"Artist Name: "<<artistName<<endl;
        cout<<"Venue: "<<venue<<endl;
        cout<<"Seat Type: "<<seatType<<endl;
        Ticket::displayTicketInfo();
    }
};


int main(){
    Ticket* t=new FlightTicket(1,"Jake",2000,"15-01-2025","UAE","Emirates",200,"Business");
    t->reserve();
    t->displayTicketInfo();

    t=new TrainTicket(2,"Alex",1500,"16-04-2025","USA",23,"Coach","15:30");
    t->reserve();

    t=new ConcertTicket(3,"John",2400,"25-10-2025","London","Artist 101","Hall","Front seats");
    t->displayTicketInfo();
}