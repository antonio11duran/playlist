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

song* DoublyLL::next_song(song* current_song) {
    return current_song->next;
}

song* DoublyLL::prev_song(song* current_song) {
    return current_song->prev;
}

void DoublyLL::add_song(string title, string artist) {
    add_song_node(init_song(title, artist));
}

void DoublyLL::add_song_node(song* new_song) {
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

void DoublyLL::insert_at_specific_spot(int location, song* song_to_add) {
    song* cursor = first_song;
    int i = 1;
    if (location < 1 || location > playlist_size() + 1 || cursor == NULL) {
        return;
    }
    if (location == 1) {
        song_to_add->next = cursor;
        cursor->prev = song_to_add;
        set_top(song_to_add);
        return;
    }
    if (location == playlist_size() + 1) {
        add_song_node(song_to_add);
        return;
    }
    while (i != location) {
        cursor = cursor->next;
        i++;
    }
    song_to_add->next = cursor;
    song_to_add->prev = cursor->prev;
    cursor->prev->next = song_to_add;
    cursor->prev = song_to_add;
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

int DoublyLL::playlist_size() {
    int size = 0;
    song* cursor = first_song;
    while (cursor != NULL) {
        cursor = cursor->next;
        size++;
    }
    return size;
}

void DoublyLL::set_top(song* first_song_) {
    first_song = first_song_;
}

song* DoublyLL::get_first_song() { return first_song; }