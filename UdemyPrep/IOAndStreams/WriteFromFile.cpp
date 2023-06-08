/*
    Steps to write to a file
    - #include <fstream>
    - Declare an fstream or ofstream object
    - Connect it to a file on your file system (open it for writing)
    - Write the data to the file via they stream
    - Close the stream
*/

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    // Opening a file for writing (using fstream)
    //fstream out_file{"test.txt" , ios::out};
    //fstream out_file{"test.txt" , ios::out | ios::binary};

    // Opening a file for writing (using ofstream)
    // ofstream out_file{"test.txt" , ios::binary};

    // Different modes when we open the file for write:
    // Default --> truncate(discard content when opening) std::ios::trunc
    // Append on each write --> std::ios::app
    // Seek to the end of stream --> std::ios::ate

    string user_input{};

    fstream out_file{"test.txt", ios::app};
    getline(cin, user_input);
    out_file << "1. " <<user_input << endl; // flush the content into the file and close

    out_file.close();
    return 0;
}