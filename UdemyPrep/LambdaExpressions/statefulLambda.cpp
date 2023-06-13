/*
    stateful lambda expression -> captures information/variables from its environment
    lambda make use of compiler-generated closure, which is basically creating an object for the lambda defination
    capture list -> members of the objects -> used by the lambda

    Default capture (all)
    [=] --> default capture by value
    [&] --> default capture by reference
    [this] --> default capture this object by reference
*/

#include <functional>
#include <iostream>

int main()
{
    int y{10};

    // Take reference of y from the top
    // Can capture by either value or reference
    // To capture by value and change the value, we add the mutable keyword
    auto l = [y] (int x) mutable {std::cout << x+y;};

    l(20);

    return 0;
}