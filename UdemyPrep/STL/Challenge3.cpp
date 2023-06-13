/*
    Section 20 Challenge 3 - Using Sets and Maps

    Part 1, we need to display each unqiue word in the file and immediately following each word
    display the number of time it occurs in the textfile
    Please use a map with <string,int> Key/Value Pair for the solution

    Part 2, display the unique word along with which line the words are found at.
    Please use a map of <string, set<int>> Key/Value Pair
    Hint: consider using stringstream to process words once you read in a line from the file
*/

// Section 20
// Challenge 3  
// Maps and Sets

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
     std::cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::left << "[ ";
        for (auto i: pair.second) 
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() {
    std::map<std::string, int> words;
    std::string line;       
    std::string word;   
    std::ifstream in_file {"words.txt"};
    if (in_file) {
        // You implement this code
        while(!in_file.eof()){
            std::getline(in_file,line);
            auto iss = std::istringstream{line};
            while (iss >> word){
                word = clean_string(word);
                auto it = words.find(word);
                if (it != words.end())
                {
                    auto temp_value = it->second;
                    it->second  = temp_value + 1;
                }
                else 
                {
                    words.insert(std::make_pair(word , 1));
                }
            }
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}
    
// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"words.txt"};
    int line_count = 0;
    if (in_file) {
        // You implement this code
        while(!in_file.eof())
        {
            std::getline(in_file, line);
            line_count++;
            auto iss = std::istringstream(line);
            while(iss >> word)
            {
                word = clean_string(word);
                auto it = words.find(word);
                if (it != words.end())
                {
                    it->second.insert(line_count);
                }
                else 
                {
                    std::set<int> temp_s {line_count};
                    words.insert(std::make_pair(word , temp_s));
                }
            }
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    part1();
    part2();
    return 0;
}