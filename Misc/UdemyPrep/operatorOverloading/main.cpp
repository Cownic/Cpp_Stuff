#include <iostream>
#include <string>

#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    // ==================COPY/MOVE CONSTRUCTOR PART================
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
    // ==================COPY/MOVE CONSTRUCTOR PART================

    // ==================UNARY OPERATOR PART================
    // Mystring larry1 {"LARRY"};
    // Mystring larry2;

    // larry1.display();

    // larry2 = -larry1;

    // larry1.display();
    // larry2.display();
    // ==================UNARY OPERATOR PART================

    // ==================BINARY OPERATOR <==> PART================
    // Mystring test1{"Hello"};
    // Mystring test2{"Hello"};
    // bool result = test1==test2;

    // std::cout << "The result is " << result << std::endl;
    // ==================BINARY OPERATOR <==> PART================


    // ==================BINARY OPERATOR <+> PART================
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring stooges{" is one of the three stooges"};

    Mystring result = larry + stooges;
    result.display();
    // ==================BINARY OPERATOR <+> PART================

    return 0;
}
