# Music Playlist Creator

## About the Program
### Project Goal
This project plan was to implement the features of a music playlist by using a doubly linked list data structure.

### What is a Doubly Linked List?
A doubly linked list is a variation of the single linked list. Instead of just one pointer that points to the following node in the list, each node carries an additional pointer to the previous node in the list. This allows easy access to the beginning and end of a list. It also allows for easy insertion and deletion of specific nodes throughout the linked list. Addition and deletion at the beginning and end of lists has a O(1) time complexity. Insertion and deletion elsewhere in the list has a time complexity of O(n).

## Running the Program
Their exists a simple console menu to go through the more common functions that would be used in creating a music playlist. This includes, adding a song at the end of the playlist, inserting a song elsewhere in the playlist, removing/deleting a song from the playlist and displaying all the songs currently in the playlist.

To run the app, first open the console. Enter the following commands to run the app:
```
$ cd build
$ cmake ..
$ make && ./run_app
```


## Running the Tests
The tests I created demonstrate the bulk of the pointer functionality of the playlist. You can examine each test individually and as a group to see that pointers are updated with each addition, insertion, and deletion of song nodes. 

To run the test, you can follow the commands below after first opening the console:

```
$ cd build
$ cmake ..
$ make && ./run_tests
```

## DoublyLL Class
Major functions of the DoublyLL Class:

`display_playlist()`: Mostly used for debugging and to demonstrate playlist changes to users. It displays all the songs in the playlist, one song per line.

`add_song_node(song* new_song)`: Uses a song node to add a song to the end of the playlist/doubly linked list.

`find_song(string title, string artist)`: A helper function that is used to find a specific song in the playlist. Mostly used by the remove function to find the song and return the the song node for removal.

`insert_at_specific_spot(int location, song* song_to_add)`: Inserts a new song at a speciifc location chosen by the user. It will only work if the a valid location is chosen, from the first spot (1) to the last spot plus 1 (so the song could also be added to the end as an option).

`remove_song(song* deleted_song)`: Uses the found node from the find_song() function to remove the node from the doubly linked list and update its neighbors pointers.

## Song Node
What each song node consists of:

```
string title;            // Title of song
string artist;           // Name of song artist
song* next;              // Pointer to the next node
song* prev;              // Pointer to the previous node
```

## Further Exploration
I wanted to add this section for my own possible changes and updates to the program:

* Add another data value to the node to keep track of the number of times each track is played, allowing a priority queue to be in place to put most played songs at the beginning of the doubly linked list (playlist)
