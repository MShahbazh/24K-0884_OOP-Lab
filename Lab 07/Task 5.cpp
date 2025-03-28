#include<iostream>
using namespace std;

class Character{
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
    public:
    Character(){};
    Character(int a, string b, int c, int d, string e):characterID(a),name(b),level(c),healthPoints(d),weaponType(e){};
    virtual void attack(){
        cout<<"Attack!"<<endl;
    }
    virtual void defend(){
        cout<<"Defend!"<<endl;
    }
    virtual void displayStats(){
        cout<<"\nCharacter ID: "<<characterID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Level:"<<level<<endl;
        cout<<"Health Points: "<<healthPoints<<endl;
        cout<<"Weapon Type: "<<weaponType<<endl;
    }
};

class Warrior: public Character{
    int armourStrength;
    int meleeDamage;
    public:
    Warrior(){}
    Warrior(int a, string b, int c, int d, string e, int f, int g):Character(a,b,c,d,e),armourStrength(f),meleeDamage(g){}
    void attack() override{
        cout<<"Warrior Units Attack!"<<endl;
    }
};

class Mage:public Character{
    int manaPoints;
    int spellPower;
    public:
    Mage(){}
    Mage(int a, string b, int c, int d, string e, int f, int g):Character(a,b,c,d,e),manaPoints(f),spellPower(g){}
    void defend(){
        cout<<"Mage Units Heal!"<<endl;
    }
};

class Archer: public Character{
    int arrowCount;
    int rangedAccuracy;
    public:
    Archer(){}
    Archer(int a, string b, int c, int d, string e, int f, int g):Character(a,b,c,d,e),arrowCount(f),rangedAccuracy(g){}
    void attack(){
        cout<<"Archer Units Fire!"<<endl;
    }
};

class Rogue: public Character{
    int stealthLevel;
    int agility;
    public:
    Rogue(){}
    Rogue(int a, string b, int c, int d, string e, int f, int g):Character(a,b,c,d,e),stealthLevel(f),agility(g){}
    void displayStats(){
        Character::displayStats();
        cout<<"Stealth Level: "<<stealthLevel<<endl;
        cout<<"Agility: "<<agility<<endl;
    }
};


int main(){
    Character* c=new Warrior(101,"Warrior Unit",1,80,"Sword",100,70);
    c->attack();
    c->displayStats();

    c=new Mage(102,"Msge Unit",5,90,"Wand",20,50);
    c->defend();
    c->displayStats();

    c=new Archer(103,"Archer Unit",6,70,"Arrows",45,190);
    c->attack();
    c->displayStats();

    c=new Rogue(104,"Rogue Unit",10,100,"Guns",190,180);
    c->displayStats();
}