/*
    Steps to read from input files
    - #include <fstream>
    - Declare an fstream / ifstream object
    - Connect it to the file on your file system
    - read data from the file via the stream
    - Close the stream
*/


#include <fstream>
#include <iostream>
#include <ios>

int main()
{
    // Both input / output
    //  std::fstream in_file {"test.txt" , std::ios::in}; // read mode
    // std::fstream in_file1 {"test.txt" , std::ios::in | std::ios::binary}; // read in binary mode


    // Used when we only want to read from file
    // std::ifstream in_file {"test.txt" , std::ios::in};
    // std::ifstream in_file {"test.txt" , std::ios::binary};

    // When we want to get the filename from the user
    // std::ifstream in_file;
    // std::string filename;
    // std::cin >> filename;
    // in_file.open(filename, std::ios::in);

    // To check if the file is opened successfully
    // in_file.is_open() --> returns a boolean

    // Closing a file
    // in_file.close();

    // Reading from a file using >>
    //in_file >> x >> y >> z; -> take strings, seperated by space

    // Reading from a file using getline
    // std::string line{};
    // std::getline(in_file, line)

    // Sample Way of readig from a textfile
    std::ifstream in_file{"test.txt" , std::ios::in};
    std::string line{};
    char c;

    if (!in_file)
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    // while (!in_file.eof())
    // {
    //     std::getline(in_file , line);
    //     std::cout << line << std::endl;
    // }

    while (in_file.get(c))
    {
        std::cout << c;
    }

    in_file.close();
    return 0;
}