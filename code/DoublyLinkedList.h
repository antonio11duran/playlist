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
    DoublyLL();

    ~DoublyLL();

    song* init_song(string title, string artist);

    string display_playlist();

    string current_song(); // might need to switch to a private cursor?

    song* next_song();

    song* prev_song();

    void add_song();

    void remove_song();

    song* get_first_song();
private:
    song* first_song;
};