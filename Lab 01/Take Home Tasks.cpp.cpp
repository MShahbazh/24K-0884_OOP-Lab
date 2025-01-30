#include<iostream>
using namespace std;

// Tasks 1,2 and 3 functions
void addData(float arr[4][7]){ 
    int i,j;
    cout<<"\n---> Collecting Data: "<<endl;
    for(i=0;i<4;i++){
        cout<<"\nAQI values for City "<<i+1<<" : "<<endl;
        for(j=0;j<7;j++){
            cout<<"Day "<<j+1<<" : ";
            cin>>arr[i][j];
        }
    }
}

void displayData(float arr[4][7]){
    int i,j;
    cout<<"\n---> Displaying Data: "<<endl;
    for(i=0;i<4;i++){
        cout<<"\nAQI values for City "<<i+1<<" : "<<endl;
        for(j=0;j<7;j++){
            cout<<"Day "<<j+1<<" : "<<arr[i][j]<<endl;
        }
    }
}

void averageAQI(float arr[4][7]){
    int i,j,city;
    float avgAQI[4];
    float max=-1;
    cout<<"\n---> Average Weekly (only one week it is) AQI: "<<endl;
    for(i=0;i<4;i++){
        avgAQI[i]=0;
        for(j=0;j<7;j++){
            avgAQI[i]=avgAQI[i]+arr[i][j];
        }
        avgAQI[i]=avgAQI[i]/7;
    }
    for(i=0;i<4;i++){
        cout<<"Average AQI of City "<<i+1<<" is : "<<avgAQI[i]<<endl;
    }
    for(i=0;i<4;i++){
        if(avgAQI[i]>max){
            max=avgAQI[i];
            city=i;
        }
    }
    cout<<"\nWorst Air Quality is of City "<<city+1<<" which is "<<avgAQI[city]<<endl;
}

void criticalPollution(float arr[4][7]){
    int i,j,check;
    cout<<"\n---> Critical Pollution Days: "<<endl;
    for(i=0;i<4;i++){
        check=0;
        cout<<"\nCritical Pollution Days for City "<<i+1<<" : "<<endl;
        for(j=0;j<7;j++){
            if(arr[i][j]>150){
                cout<<"Day "<<j+1<<" with the value "<<arr[i][j]<<endl;
                check=1;
            }
        }
        if(check==0){
            cout<<"No Days with Critical AQI levels"<<endl;
        }
    }
}

void dataVisualize(float arr[4][7]){
    int i,j,k;
    cout<<"\n---> Data Visualization: "<<endl;
    for(i=0;i<4;i++){
        cout<<"\nCity "<<i+1<<" : "<<endl;
        for(j=0;j<7;j++){
            cout<<"Day "<<j+1<<" : ";
            for(k=1;k<=arr[i][j]/50;k++){
                cout<<"*";
            }
        cout<<"\n";
        }
    }
}

//Tasks 4 and 5 functions 
void addData_monthly(float arr[4][4][7]){
    int i,j,k;
    cout<<"\n---> Collecting Data: "<<endl;
    for(i=0;i<4;i++){
        cout<<"\nCity "<<i+1<<":"<<endl;
        for(j=0;j<4;j++){
            cout<<"   Week "<<j+1<<":"<<endl;
            for(k=0;k<7;k++){
                cout<<"      Day "<<k+1<<": ";
                cin>>arr[i][j][k];
            }
        }
    }
}

void displayData_monthly(float arr[4][4][7]){
    int i,j,k;
    cout<<"\n---> Displaying Data: "<<endl;
    for(i=0;i<4;i++){
        cout<<"City "<<i+1<<":"<<endl;
        for(j=0;j<4;j++){
            cout<<"   Week "<<j+1<<":"<<endl;
            for(k=0;k<7;k++){
                cout<<"      Day "<<k+1<<": "<<arr[i][j][k]<<endl;
            }
        }
        cout<<"\n";
    }
}

void averageAQI_monthly(float arr[4][4][7]){
    int i,j,k;
    float arr2[4];
    float temp;
    for(i=0;i<4;i++){
        temp=0;
        for(j=0;j<4;j++){
            for(k=0;k<7;k++){
               temp=temp+arr[i][j][k]; 
            }
        }
        arr2[i]=temp/28;
    }
    cout<<"\n---> Average Monthly AQI for each City: "<<endl;
    for(i=0;i<4;i++){
        cout<<"City "<<i+1<<": "<<arr2[i]<<endl;
    }
    
}

void averageAQI_allweeks(float arr[4][4][7]){
    int i,j,k,index=0;
     float arr2[4][4];
    float temp;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            temp=0;
            for(k=0;k<7;k++){
                temp=temp+arr[i][j][k];    
            }
            arr2[i][j]=temp/4;
        }
    }
    cout<<"\n---> Weekly Averages For each City:"<<endl;
    for(i=0;i<4;i++){
        cout<<"City "<<i+1<<":"<<endl;
        for(j=0;j<4;j++){
            cout<<"   Week "<<j+1<<": "<<arr2[i][j]<<endl;
        }
        cout<<"\n";
    }
    temp= temp=arr2[0][0]-arr2[0][3];
    cout<<"---> City with Most Improved Air Quality:"<<endl;
    for(i=0;i<4;i++){
        if(arr2[i][0]-arr2[i][3]>=temp && arr2[i][0]>=arr2[i][3]){
            temp=arr2[i][0]-arr2[i][3];
            index=i;
        }
    }
    cout<<"\nThe City with the most improved quality is City "<<index+1<<" with the largest drop of "<<temp<<" AQI between First week ("<<arr2[index][0]<<" AQI) and last week ("<<arr2[index][3]<<" AQI).\n";
}

void highlow_AQI(float arr[4][4][7]){
    int i,j,k,index_week,index_day;
    float high,low;
    cout<<"\n---> Highest and Lowest AQI values for each City in a month:"<<endl;
    for(i=0;i<4;i++){
        cout<<"City "<<i+1<<": "<<endl;
        high=arr[i][0][0];
        low=arr[i][0][0];
        for(j=0;j<4;j++){
            for(k=0;k<7;k++){
                if(arr[i][j][k]<=low){
                    low=arr[i][j][k];
                    index_week=j;
                    index_day=k;
                }
                else if(arr[i][j][k]>=high){
                    high=arr[i][j][k];
                    index_week=j;
                    index_day=k;
                }
            }
        }
        cout<<"Lowest AQI of "<<low<<" on day "<<index_week+1<<" of week "<<index_week+1<<endl;
        cout<<"\n";
    }
}

void criticalPollution_monthly(float arr[4][4][7]){
    int i,j,k;
    int check;
    cout<<"\n---> Critical Pollution Days: "<<endl;
    for(i=0;i<4;i++){
        cout<<"City "<<i+1<<":"<<endl;
            check=0;
        for(j=0;j<4;j++){
            for(k=0;k<7;k++){
                if(arr[i][j][k]>150){
                    cout<<"   Day "<<k+1<<" of Week "<<j+1<<" with AQI of "<<arr[i][j][k]<<endl;
                    check=1;
                }
            }
        }
        if(check==0){
            cout<<"No Critical Pollution Days for this City"<<endl;
        }
        cout<<"\n";
    }
}

int main(){
    float index[4][7];
    float monthly_AQI[4][4][7];
    //Tasks 1,2 and 3
    cout<<"\n\n---------- Tasks 1,2 and 3 ----------"<<endl;
    addData(index);
    displayData(index);
    averageAQI(index);
    criticalPollution(index);
    dataVisualize(index);
    //Tasks 4,5
    cout<<"\n\n---------- Tasks 4,5 ----------"<<endl;
    addData_monthly(monthly_AQI);
    displayData_monthly(monthly_AQI);
    cout<<"\n--------------- REPORT ----------"<<endl;
    averageAQI_monthly(monthly_AQI);
    averageAQI_allweeks(monthly_AQI);
    criticalPollution_monthly(monthly_AQI);
    highlow_AQI(monthly_AQI);
}
