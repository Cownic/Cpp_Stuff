#include <iostream>
#include <string>
#include <vector>

class Movie
{
    private:
        std::string name;
        std::string movie_rating;
        int watch_count;
        
    
    public:
        //constructors
        Movie(std::string _name, std::string _movie_rating, int _watch_count):name{_name},movie_rating{_movie_rating},watch_count{_watch_count}{}
        Movie():Movie("None", "None", 0){}

        // destructor
        ~Movie(){}

        //getters
        std::string get_name(){return this->name;}
        std::string get_movie_rating(){return this->movie_rating;}
        int get_watch_count(){return this->watch_count;}

        //setters
        void set_watch_count(int value){
            watch_count++;
            std::cout << watch_count << std::endl;
        }
        
        // functions
        bool check_if_exist(std::string movie_name)
        {
            if (movie_name == get_name()) 
            {
                return false;
            }
            else 
            {
                return true;
            }
        }
        

        void display_stuff()
        {
            std::cout << "Movie Name " << get_name() << " Movie Rating " << get_movie_rating() << " Watch Count " << get_watch_count() << std::endl;
        }

};

void display_options()
{
    std::cout << "1 - Add a movie" << std::endl;
    std::cout << "2 - Increment watch count for a movie" << std::endl;
    std::cout << "3 - Display all movies" << std::endl;
    std::cout << "-1 - Quit" << std::endl;
}

bool check_dup(std::vector<Movie> m_list , std::string m_name)
{
    for (Movie ms : m_list)
    {
        if (ms.get_name() == m_name)
        {
            return true;
        }
    }
    return false;
}

std::vector<Movie> increment(std::vector<Movie> m_list , std::string m_name)
{
    for (Movie ms: m_list)
    {
        if (ms.get_name() == m_name)
        {
            ms.set_watch_count(2);
            std::cout << "Success" << std::endl;
        }
    }

    return m_list;
}

void display_movies(std::vector<Movie> m_list)
{
    for (auto ms: m_list)
    {
        ms.display_stuff();
    }
}

int main()
{
    std::vector<Movie> Movies;
    int choice{0};
    std::string m_name, m_rating;
    bool result{false};
    while (choice >= 0)
    {
        display_options();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter your movie name, movie rating: ";
            std::cin >> m_name;
            std::cin >> m_rating;
            result = false;
            result = check_dup(Movies , m_name);
            if (!result)
            {
                Movie Movie_new(m_name , m_rating , 1);
                Movies.push_back(Movie_new);
                std::cout << "Movie added!" << std::endl;
            }
            else
            {
                std::cout << "Movie already in Movie list" << std::endl;
            }
            break;
        case 2:
            std::cout << "Enter the movie name" << std::endl;
            std::cin >> m_name;

            if (check_dup(Movies , m_name))
            {
                Movies = increment(Movies , m_name);
            }
            else
            {
                std::cout << "Invalid Operation" << std::endl;
            }
            break;
        case 3:
            display_movies(Movies);
            break;

        default:
            std::cout << "Invalid Option" << std::endl;
            break;
        } 
    }

    return 0;
}