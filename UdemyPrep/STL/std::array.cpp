#include <iostream>
#include <array>
#include <algorithm>

/*
    - #include <array>
    - fixed size, direct element access, use instead of raw arrays when possible
    - all iterators available and do not invalidate

*/
using namespace std;

int main()
{
    array<int,5> arr1 {{1,2,3,4,5}};

    array<string,3> stooges {
        string {"LARRY"},
        "Moe", // will convert c-style string to std::string automatically
        string {"Curly"}
    };

    cout << arr1.size();
    cout << arr1.at(0);
    cout << arr1.front();
    cout << arr1.empty();
    //arr1.swap(stooges);

    // Still got alot of things we can do using iterators, look thru at cppreferences

    return 0;
}
