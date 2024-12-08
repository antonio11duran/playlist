#include "DoublyLinkedList.h"

DoublyLL::DoublyLL() {
    first_song = NULL;
}

DoublyLL::~DoublyLL() {}

song* init_song(string title, string artist) {
    song* new_song(new song);
    new_song->artist = artist;
    new_song->title = title;
    return new_song;
}

song* DoublyLL::get_first_song() { return first_song; }