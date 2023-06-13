/*
    Section 20 Chanllenge 2
    use std::lsit to create a mmenu driven application
*/

#include <list>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cctype>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);

private:
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string n, std::string a, int r) : name{n}, artist{a}, rating{r} {}
    std::string get_name() const { return name; }
    std::string get_artist() const { return artist; }
    int get_rating() const { return rating; }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name << std::setw(30) << std::left << s.artist << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "\nN - Play Next Song" << std::endl;
    std::cout << "\nP - Play Previous Song" << std::endl;
    std::cout << "\nA - Add and play a new song at current location" << std::endl;
    std::cout << "\nL - List the current playlist" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "\nEnter a selection (Q to quit) ";
}

void play_current_song(const Song &song)
{
    // this function should display
    // Playing: follwed by the song that is playing
    std::cout << "___________________________________________" << "\n";
    std::cout << "Playing: " << song.get_name() << std::endl;
    std::cout << "___________________________________________" << "\n";
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    // this function should display the current playlist
    // and then the current song playing
    for (const auto &song : playlist)
    {
        std::cout << song << "\n";
    }
    play_current_song(current_song);
}

int main()
{
    char choice{};
    std::string song_name;
    std::string artist;
    int rating;

    std::list<Song> song_list{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Caila Cabello", 5},
        {"Pray For Me", " The Weekend and K.Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whaever It Takes", "Imagine Dragons", 3},
    };

    std::list<Song>::iterator current_song = song_list.begin();

    // Program logic
    display_menu();
    std::cin >> choice;
    while (choice != 'Q')
    {
        switch (choice)
        {
        case 'F':
            display_playlist(song_list, *current_song);
            break;
        case 'N':
            current_song++;
            play_current_song(*current_song);
            break;
        case 'P':
            current_song--;
            play_current_song(*current_song);
            break;
        case 'A':
        {
            std::cout << "Enter Song Name: " << std::endl;
            std::cin >> song_name;
            std::cout << "Enter Artist: " << std::endl;
            std::cin >> artist;
            std::cout << "Enter rating: " << std::endl;
            std::cin >> rating;
            Song temp_song{song_name, artist, rating};
            song_list.insert(current_song , temp_song);
            current_song--;
            play_current_song(*current_song);
            break;
        }
        case 'L':
            display_playlist(song_list , *current_song);
            break;
        case 'Q':
            std::cout << "Good Bye" << std::endl;
            break;
        }
        display_menu();
        std::cin >> choice;
    }

    return 0;
}
