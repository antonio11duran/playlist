#include "iostream"
#include <string>
#include "../code/DoublyLinkedList.h"

using namespace std;

void Menu(DoublyLL playlist) {
    bool quit = false;
    int choice;
    int location;
    string title;
    string artist;
    do {
    cout << endl << "Enter the corresponding option for the desired menu selection:" << endl << endl;
    cout << "1 - Add a song to end of playlist" << endl;
    cout << "2 - Insert song at specific location in playlist" << endl;
    cout << "3 - Remove a song" << endl;
    cout << "4 - Display all songs in the playlist" << endl;
    cout << "5 - Quit and exit program" << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "Enter the title of the song to be added:" << endl;
        cin.ignore();
        getline(cin, title);
        cout << "Enter the artist of the song to be added:" << endl;
        getline(cin, artist);
        cout << "Adding song to playlist..." << endl;
        playlist.add_song(title, artist);
        cout << "Song added to playlist" << endl;
    } else if (choice == 2) {
        cout << "Enter the title of the song to be added:" << endl;
        cin.ignore();
        getline(cin, title);
        cout << "Enter the artist of the song to be added:" << endl;
        getline(cin, artist);
        cout << "Enter location of the song between 1 and " << playlist.playlist_size() + 1 << endl;
        cin >> location;
        if (location < 1 || location > playlist.playlist_size() + 1) {
            cout << "Enter a number within the given range!" << endl;
        } else {
            song* new_song = playlist.init_song(title, artist);
            playlist.insert_at_specific_spot(location, new_song);
            cout << "Song added successfully to the provided location." << endl;
        }
    } else if (choice == 3) {
        cout << "Enter the title of the song to be removed:" << endl;
        cin.ignore();
        getline(cin, title);
        cout << "Enter the artist of the song to be removed:" << endl;
        getline(cin, artist);
        song* deleted_song = playlist.find_song(title, artist);
        if (deleted_song == NULL) {
            cout << "No song found with the title and/or artist. Please try again!" << endl;
            cout << "Make sure the artist name and title are spelled correctly!" << endl;
        } else {
            cout << "Song found!" << endl;
            playlist.remove_song(deleted_song);
            cout << "Song removed from the playlist!" << endl;
        }
    } else if (choice == 4) {
        string all_songs = playlist.display_playlist();
        cout << "Here are all the songs currently in the playlist:" << endl << endl;
        cout << all_songs << endl;
    } else if (choice == 5)  {
        quit = true;
    } else {
        cout << "Please choose an option from the provided list!" << endl;
    }
    } while (!quit);
}

int main(){

    // Do some printing
    cout << "New Playlist Created" << endl;
    DoublyLL playlist = DoublyLL();
    Menu(playlist);
    
    return 0;
}