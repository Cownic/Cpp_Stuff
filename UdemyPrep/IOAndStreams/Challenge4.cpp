// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers

// This challenge should be pretty easy.
// I have provided the text to Romeo and Juliet in a file named romeoandjuliet.txt

// For this challenge you have to make copy of the Romeo and Juliet file and save it to another file.
// This new copy should have line numbers at the beginning of each line in the play.
// Please format the numbers nicely so everything lines up.

#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>

int main()
{
    int number{1};
    std::ifstream in_file{"romeoandjuliet.txt" ,std::ios::in};
    std::ofstream out_file{"numbered_romeoandjuliet.txt"}; // default is truncate mode
    std::string line;

    if (!in_file)
    {
        std::cerr << "Error Opening File" << std::endl;
    }

    if (!out_file)
    {
        std::cerr << "Error Opening File" << std::endl;
    }

    while (!in_file.eof())
    {
        std::getline(in_file, line);
        if (line == "")
        {
            out_file << std::endl;
        }
        else {
            out_file<< std::left << std::setw(10) << number++ << line << std::endl;
        }
    }

    std::cout << "Copy Completed" << std::endl;
    in_file.close();
    out_file.close();

    return 0;
}