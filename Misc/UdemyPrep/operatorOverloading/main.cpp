#include <iostream>
#include <string>

#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    // Mystring empty;
    // Mystring larry("Larry");
    // Mystring stooge{larry}; // copy constructor

    // Mystring a{"Hello"};
    // Mystring b;
    // b = a;

    // b.display();

    // // Temp object will be created, then assigned to b after
    // b = "This is a test";

    // b.display();

    // empty.display();
    // larry.display();
    // stooge.display();

    Mystring larry1 {"LARRY"};
    Mystring larry2;

    larry1.display();

    larry2 = -larry1;

    larry1.display();
    larry2.display();

    return 0;
}
