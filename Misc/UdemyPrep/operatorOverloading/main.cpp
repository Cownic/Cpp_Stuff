#include <iostream>
#include <string>

#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge{larry}; // copy constructor

    empty.display();
    larry.display();
    stooge.display();

    return 0;
}
