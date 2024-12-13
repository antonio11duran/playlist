#include "../code/DoublyLinkedList.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

TEST(test_DoubleLL, InitTest) {
    DoublyLL playlist;
    ASSERT_FALSE(playlist.get_first_song());
    string title = "Shake it Off";
    string artist = "Taylor Swift";
    song* TS = playlist.init_song(title, artist);
    ASSERT_TRUE(TS);
    ASSERT_EQ(title, TS->title);
    ASSERT_EQ(artist, TS->artist);
    ASSERT_FALSE(TS->next);
    ASSERT_FALSE(TS->prev);
}

song* build_three_song_playlist() {
    song* three(new song);
    three->title = "Shake it Off";
    three->artist = "Taylor Swift";
    three->prev = NULL;
    three->next = new song;
    three->next->title = "La Camisa Negra";
    three->next->artist = "Juanes";
    three->next->prev = three;
    three->next->next = new song;
    three->next->next->title = "Japan";
    three->next->next->artist = "Throttle";
    three->next->next->prev = three->next;
    three->next->next->next = (NULL);
    return three;
}

TEST(test_DoubleLL, PlaylistTest) {
    DoublyLL playlist;
    ASSERT_EQ("", playlist.display_playlist());
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    string list = "Shake it Off by Taylor Swift\nLa Camisa Negra by Juanes\nJapan by Throttle\n";
    ASSERT_EQ(list, playlist.display_playlist());
}

TEST(test_DoubleLL, NextSongTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    ASSERT_EQ(three->next, playlist.next_song(three));
    ASSERT_EQ(three->next->next, playlist.next_song(three->next));
    ASSERT_EQ(NULL, playlist.next_song(three->next->next));
}

TEST(test_DoubleLL, PrevSongTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    ASSERT_EQ(NULL, playlist.prev_song(three));
    ASSERT_EQ(three, playlist.prev_song(three->next));
    ASSERT_EQ(three->next, playlist.prev_song(three->next->next));
}

TEST(test_DoubleLL, AddSongTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    playlist.add_song("Touch", "Daft Punk");
    song* cursor = playlist.get_first_song()->next->next->next;
    ASSERT_TRUE(cursor);
    ASSERT_FALSE(cursor->next);
    ASSERT_EQ("Touch", cursor->title);
    ASSERT_EQ("Daft Punk", cursor->artist);
    ASSERT_EQ(playlist.get_first_song()->next->next, cursor->prev);
}

TEST(test_DoubleLL, FindSongTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    ASSERT_FALSE(playlist.find_song("Touch", "Daft Punk"));
    ASSERT_TRUE(playlist.find_song("Japan", "Throttle"));
}

TEST(test_DoubleLL, RemoveMiddleSongTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    song* taylor = playlist.find_song("Shake it Off", "Taylor Swift");
    song* juanes = playlist.find_song("La Camisa Negra", "Juanes");
    song* throttle = playlist.find_song("Japan", "Throttle");
    playlist.remove_song(juanes);
    ASSERT_FALSE(playlist.find_song("La Camisa Negra", "Juanes"));
    ASSERT_EQ(taylor->next, throttle);
    ASSERT_EQ(throttle->prev, taylor);
    ASSERT_FALSE(juanes->next);
    ASSERT_FALSE(juanes->prev);
}

TEST(test_DoubleLL, RemoveFirstSongTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    song* taylor = playlist.find_song("Shake it Off", "Taylor Swift");
    song* juanes = playlist.find_song("La Camisa Negra", "Juanes");
    playlist.remove_song(taylor);
    ASSERT_FALSE(playlist.find_song("Shake it Off", "Taylor Swift"));
    ASSERT_EQ(playlist.get_first_song(), juanes);
    ASSERT_FALSE(juanes->prev);
    ASSERT_FALSE(taylor->next);
}

TEST(test_DoubleLL, RemoveLastSongTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    song* juanes = playlist.find_song("La Camisa Negra", "Juanes");
    song* throttle = playlist.find_song("Japan", "Throttle");
    playlist.remove_song(throttle);
    ASSERT_FALSE(playlist.find_song("Japan", "Throttle"));
    ASSERT_FALSE(juanes->next);
    ASSERT_FALSE(throttle->prev);
}

TEST(test_DoubleLL, RemoveAllSongsTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    song* taylor = playlist.find_song("Shake it Off", "Taylor Swift");
    song* juanes = playlist.find_song("La Camisa Negra", "Juanes");
    song* throttle = playlist.find_song("Japan", "Throttle");
    playlist.remove_song(taylor);
    playlist.remove_song(juanes);
    playlist.remove_song(throttle);
    ASSERT_FALSE(playlist.find_song("Shake it Off", "Taylor Swift"));
    ASSERT_FALSE(playlist.find_song("La Camisa Negra", "Juanes"));
    ASSERT_FALSE(playlist.find_song("Japan", "Throttle"));
    ASSERT_FALSE(playlist.get_first_song());
    ASSERT_FALSE(throttle->next);
    ASSERT_FALSE(throttle->prev);
}

TEST(test_DoubleLL, SizeTest) {
    DoublyLL playlist;
    ASSERT_EQ(0, playlist.playlist_size());
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    ASSERT_EQ(3, playlist.playlist_size());
    song* throttle = playlist.find_song("Japan", "Throttle");
    playlist.remove_song(throttle);
    ASSERT_EQ(2, playlist.playlist_size());
}

TEST(test_DoubleLL, InsertTest) {
    DoublyLL playlist;
    song* three = build_three_song_playlist();
    playlist.set_top(three);
    song* taylor = playlist.find_song("Shake it Off", "Taylor Swift");
    song* juanes = playlist.find_song("La Camisa Negra", "Juanes");
    song* throttle = playlist.find_song("Japan", "Throttle");
    // Insert at beginning
    song* ph = playlist.init_song("1901", "Phoenix");
    playlist.insert_at_specific_spot(1, ph);
    // Should be ph, taylor, juanes, throttle
    ASSERT_EQ(ph, playlist.get_first_song());
    ASSERT_EQ(taylor, ph->next);
    ASSERT_EQ(ph, taylor->prev);
    ASSERT_FALSE(ph->prev);

    // Insert at middle
    song* inter = playlist.init_song("Evil", "Interpol");
    playlist.insert_at_specific_spot(3, inter);
    // Should be ph, taylor, inter, juanes, throttle
    ASSERT_EQ(inter, taylor->next);
    ASSERT_EQ(inter, juanes->prev);
    ASSERT_EQ(taylor, inter->prev);
    ASSERT_EQ(juanes, inter->next);

    // Insert at end
    song* smash = playlist.init_song("All Star", "Smash Mouth");
    playlist.insert_at_specific_spot(6, smash);
    // Should be ph, taylor, inter, juanes, throttle, smash
    ASSERT_EQ(smash, throttle->next);
    ASSERT_EQ(throttle, smash->prev);
    ASSERT_FALSE(smash->next);
}