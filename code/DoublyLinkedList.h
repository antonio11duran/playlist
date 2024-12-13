#include <memory>
#include <string>

using namespace std;

struct song {
    string title;
    string artist;
    song* next;
    song* prev;
};

class DoublyLL {
public:
    // constructor
    DoublyLL();

    // deconstructor
    ~DoublyLL();

    song* init_song(string title, string artist);

    string display_playlist();

    song* next_song(song* current_song);

    song* prev_song(song* current_song);

    void add_song(string title, string artist);

    void add_song_node(song* new_song);

    song* find_song(string title, string artist);

    void insert_at_specific_spot(int location, song* song_to_add);

    void remove_song(song* deleted_song);

    int playlist_size();

    song* get_first_song();

    void set_top(song* first_song_);
private:
    song* first_song;
};