#include "../code/DoublyLinkedList.h"
#include <gtest/gtest.h>

#include <cmath>
#include <string>

TEST(InitTest, InitTest) {
    DoublyLL playlist;
    ASSERT_FALSE(playlist.get_first_song());
    song* TS = playlist.init_song("Shake it Off", "Taylor Swift");
    ASSERT_TRUE(TS);
    ASSERT_EQ("Shake it Off", TS->title);
    ASSERT_EQ("Taylor Swift", TS->artist);
    ASSERT_FALSE(TS->next);
    ASSERT_FALSE(TS->prev);
}