/*
    String Stream
    -  allow us to read/wrote from strings in memory much as we would read/write to files
    - very powerful / useful for data validation

    Steps to use
    - #include <sstream>
    - Declare an stringstream, istringstream or ostringstream object
    - connect it to a std::string
    - read/write from/to the string stream using formatted I/O

*/

#include <sstream>
#include <iostream>

int main()
{
    int num{};
    double total{};
    std::string name{};
    std::string data{"Moe 100 1234.5"};

    std::istringstream iss{data};
    iss >> name >> num >> total;

    std::ostringstream oss{};
    oss << name << " " << num << " " << total;
    std::cout << oss.str() << std::endl;

    
}
