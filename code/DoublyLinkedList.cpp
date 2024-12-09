#include "DoublyLinkedList.h"

DoublyLL::DoublyLL() {
    first_song = NULL;
}

DoublyLL::~DoublyLL() {}

song* DoublyLL::init_song(string title, string artist) {
    song* new_song(new song);
    new_song->artist = artist;
    new_song->title = title;
    return new_song;
}

string DoublyLL::display_playlist() {
    string playlist;
    song* cursor = first_song;
    if (cursor == NULL) {
        return "";    
    }
    while (cursor != NULL) {
        playlist.append(cursor->title).append(" by ").append(cursor->artist);
        playlist.append("\n");
        cursor = cursor->next;
    }
    return playlist;
}

string DoublyLL::current_song() {
    return "";
}

song* DoublyLL::next_song(song* current_song) {
    return current_song->next;
}

song* DoublyLL::prev_song(song* current_song) {
    return current_song->prev;
}

void DoublyLL::add_song(string title, string artist) {
    song* new_song = init_song(title, artist);
    song* cursor = first_song;
    if (cursor == NULL) {
        first_song = new_song;
        return;
    }
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = new_song;
    cursor->next->prev = cursor;
}

song* DoublyLL::find_song(string title, string artist) {
    song* cursor = first_song;
    if (cursor == NULL) {
        return NULL;
    }
    while (cursor != NULL) {
        if (cursor->title.compare(title) == 0) {
            if (cursor->artist.compare(artist) == 0) {
                return cursor;
            }
        }
        cursor = cursor->next;
    }
    return NULL;
}

void DoublyLL::remove_song(song* deleted_song) {
    song* cursor = deleted_song;
    if (cursor == NULL) {
        return;
    }
    song* before = prev_song(deleted_song);
    song* after = next_song(deleted_song);
    deleted_song->next = NULL;
    deleted_song->prev = NULL;
    if (before == NULL && after == NULL) {
        set_top(NULL);
        return;
    }
    if (before == NULL) {
        after->prev = NULL;
        deleted_song->next = NULL;
        set_top(after);
        return;
    }
    if (after == NULL) {
        before->next = NULL;
        deleted_song->prev = NULL;
        return;
    }
    before->next = after;
    after->prev = before;
}

void DoublyLL::set_top(song* first_song_) {
    first_song = first_song_;
}

song* DoublyLL::get_first_song() { return first_song; }