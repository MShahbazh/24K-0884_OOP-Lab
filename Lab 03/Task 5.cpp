#include<iostream>
using namespace std;

class MusicPlayer{
    string playlists[100];
    string currentlyPlayingSong;
    public:
    void playlist(){
        for(int i=0;i<100;i++){
            playlists[i]="NULL";
        }
        currentlyPlayingSong="No Song Currently Playing";
    }

    void Add_Song(string song){
        int i;
        for(i=0;i<100;i++){
            if(playlists[i]=="NULL"){
                playlists[i]=song;
                break;
            }
        }
    }

    void Remove_song(string song){
        int i,j;
        bool check=false;
        for(i=0;i<100;i++){
            if(playlists[i]==song){
                playlists[i]="NULL";
                for(j=i;playlists[j+1]!="NULL";j++){
                    string temp=playlists[i];
                    playlists[i]=playlists[i+1];
                    playlists[i+1]=temp;
                }
                check=true;
                break;
            }
        }
        if(check==false){
            cout<<"\nSong not present"<<endl;
        }
    }

    void Display_Playlist(){
        int i;
        bool empty=false;
        cout<<"\n--- Display Playlists ---"<<endl;
        for(i=0;playlists[i]!="NULL";i++){
            cout<<i+1<<" "<<playlists[i]<<endl;
            empty=true;
        }
        if(empty==false){
            cout<<"\nPlaylist Empty"<<endl;
        }
    }

    void set_currentlyPlayingSong(string song){
        int i;
        bool song_found=false;
        for(i=0;playlists[i]!="NULL";i++){
            if(playlists[i]==song){
                currentlyPlayingSong=song;
                cout<<"\n"<<currentlyPlayingSong<<" currently playing"<<endl;
                song_found=true;
                break;
            }
        }
        if(song_found==false){
            cout<<"\nSong not found"<<endl;
        }
    }

    void get_currentlyPlayingSong(){
        cout<<"\nSong Curently PLaying: "<<currentlyPlayingSong<<endl;
    }
};

int main(){
    int i;
    string song;
    cout<<"\n--- Music Player ---"<<endl;
    MusicPlayer Player1;
    Player1.playlist();
    do{
        cout<<"\n1. Add Song\n2. Remove Song\n3. Display Playlists\n4. Change Currently Playing song\n5. Display Currently Playing Song\n6. Exit\nEnter the corresponding number: ";
        cin>>i;
        if(i==1){
            cout<<"\nEnter the Song name to add in the playlists: ";
            cin>>song;
            Player1.Add_Song(song);
        }
        else if(i==2){
            cout<<"\nEnter the Song name to remove from the playlists: ";
            cin>>song;
            Player1.Remove_song(song);
        }
        else if(i==3){
            Player1.Display_Playlist();
        }
        else if(i==4){
            cout<<"\nEnter the Song name to play: ";
            cin>>song;
            Player1.set_currentlyPlayingSong(song);
        }
        else if(i==5){
            Player1.get_currentlyPlayingSong();
        }
        else if(i==6){
            break;
        }
    }while(1);
}