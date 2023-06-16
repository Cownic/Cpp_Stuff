#include <iostream>

int main()
{
    // Annoymous, no type safety
    // Named Type safe
    enum Colour{Red, Blue, Green}; // Implicit initialiation will initialise the first element to 0, then +1 for the subsequent ones
    enum{y=1, z,q};

    Colour my_colour{};

    my_colour = Red;
    //my_colour = 4; --> become not valid
}