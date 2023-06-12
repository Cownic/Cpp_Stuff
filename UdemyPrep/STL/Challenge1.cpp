/*
    Section 20 Challenge 1 - Deque Challenge
    Make sure of deque to implement a palindrome
*/

#include <iostream>
#include <deque>
#include <cctype>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string &s)
{
    // Implement the function using deque
    std::deque<char> d;
    for (const auto &c: s){
        if (std::isalpha(c)){
            d.push_back(std::tolower(c));
        }
    }

    while (!d.empty())
    {
        if (d.size() == 1)
        {
            break;
        }
        if (d.front() == d.back())
        {
            d.pop_front();
            d.pop_back();
            //std::cout << "Same" << std::endl;
        }
        else 
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings {"a", "aa", "abba", "abbcbba", "ab", "abc" , "radar", "bob" , "A Toyota's a toyota" , "C++", "This is a palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto &string: test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(string) << string << std::endl;
    }
    std::cout << std::endl;


    return 0;
}