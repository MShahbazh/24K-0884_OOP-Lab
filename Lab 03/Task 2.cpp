#include<iostream>
using namespace std;

class FitnessTracker{
    string username;
    int dailyStepGoal;
    int stepsTaken;
    int caloriesBurned=0;
    public:
    void set_values(string name, int i, int j){
        username=name;
        dailyStepGoal=i;
        stepsTaken=j;
    }

    void update_dailystepgoal(int i){
        if(i<0){
            cout<<"Step Goal can't be negative"<<endl;
        }
        else{
            dailyStepGoal=i;
        }
    }

    void update_stepstaken(int i){
        stepsTaken=i;
    }

    void update_caloriesburned(int i){
        caloriesBurned=i;
    }

    void display_progress(){
        cout<<"\nUsername: "<<username<<endl;
        cout<<"Steps Goal: "<<dailyStepGoal<<endl;
        cout<<"Steps Taken: "<<stepsTaken<<endl;
        cout<<"Calories Burned till now: "<<caloriesBurned<<endl;
    }

    void log_steps(int steps, int calorie_per_step){
        stepsTaken+=steps;
        caloriesBurned+=steps*calorie_per_step;
    }

    bool check_goal(){
        if(stepsTaken>=dailyStepGoal){
            return true;   
        }
        else{
            return false;
        }
    }
};

int main(){
    int n,i,j,k;
    string name;
    FitnessTracker tracker;
    cout<<"\nEnter the your name: ";
    cin>>name;
    cout<<"Enter your daily step goal: ";
    cin>>i;
    if(i<=0){
        while(i<=0){
            cout<<"\nDaily Step Goal can't be zero nor negative\nEnter Again: ";
            cin>>i;
        }
    }
    cout<<"Enter the value for calorie/step, number of calories consumed per step: ";
    cin>>n;
    if(n<=0){
        while(n<=0){
            cout<<"\nCalorie per step can't be zero not negative\nEnter Again: ";
            cin>>n;
        }
    }
    tracker.set_values(name,i,0);
    do{
        if(tracker.check_goal()==false){
            cout<<"\n1. Log Steps\n2. Display Progress\n3. Exit\nEnter the Corresponding Number: ";
            cin>>i;
            if(i==1){
                cout<<"\nEnter the number of steps you took: ";
                cin>>j;
                tracker.log_steps(j,n);
            }
            else if(i==2){
                tracker.display_progress();
            }
            else if(i==3){
                break;
            }
        }
        else{
            cout<<"\nYou have reached the Daily Step Goal. Either: "<<endl;
            cout<<"1. Reset the Steps taken (zero)\n2. Update the daily Step Goal (steps and calories taken, will then be zero)\n3. Update Daily Steps Goal (with steps and calories taken remain as it is)\nEnter the Corresponding number: ";
            cin>>j;
            if(j==1){
                tracker.update_stepstaken(0);
            }
            else if(j==2){
                cout<<"\nEnter the new value for daily Steps Taken: ";
                cin>>k;
                tracker.update_dailystepgoal(k);
                tracker.update_stepstaken(0);
                tracker.update_caloriesburned(0);
            }
            else if(j==3){
                cout<<"\nEnter the new value for daily steps Taken: ";
                cin>>k;
                tracker.update_dailystepgoal(k);
            }
            tracker.display_progress();
        }

    }while(1);
}