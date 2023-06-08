#include <string>
#include <iostream>
#include <fstream>
#include <ios>

/*
    Section 19
    Challenge 3
    Word finder

    Ask the user to enter a word
    Process the Romeo and Juliet file and determine how many total words there are
    and how many times the word the user entered appears as a substring of a word in the play.
*/
using namespace std;

bool check_if_exist(const string &tw , const string &uw)
{
    size_t found = tw.find(uw); // find the first occurence of substring and return the position
    if (found != string::npos){ // as long as the position return is valid
        return true;
    }
    return false;
}

int main()
{
    ifstream in_file{"romeoandjuliet.txt" , ios::in};
    string temp_word{};
    string user_word{};
    int total_word_count{0};
    int match_count{0};

    if (!in_file)
    {
        cerr << "Error Locating File" << endl;
    }

    cout << "Enter a word to find: " ;
    cin >> user_word;

    while (in_file >> temp_word)
    {

        if (check_if_exist(temp_word, user_word))
        {
            match_count++;
        }
        total_word_count++;
    }

    cout << "Total Number of words checked: " << total_word_count << endl;
    cout << "Total Matches Found: " << match_count << endl;

    return 0;
}