/*
    Streams Manipulators
    - have useful memeber functions to control formatiing
    - can be used on input and output streams
    - time of the effect on the stream varies
    - can b used as member funtions or as a manipulato
*/
#include <iostream>
#include <iomanip>


int main()
{
    // Stream Manipulator - Boolean
    // Default: 1/0
    // Affects all further output to stream
    // std::cout << std::boolalpha; //  will be true/false instead of 1/0
    // std::cout.setf(std::ios::boolalpha); // same as above
    // std::cout << (10==10) << std::endl;
    // std::cout << (10==20) << std::endl;
    // std::cout << std::noboolalpha; // back to 1/0
    // std::cout << std::resetiosflags(std::ios::boolalpha); //reset to default

    // Stream Manipulator - Integers
    // Default: base 10 (dec), noshowbase, nouppercase, noshowpos
    // Affects all further output to stream
    // int num{255};
    // std::cout << std::showbase << std::uppercase << std::showpos; // persist
    // std::cout << std::dec << num << std::endl;
    // std::cout << std::hex << num << std::endl;
    // std::cout << std::oct << num << std::endl;
    // std::cout << std::noshowbase << std::nouppercase << std::noshowpos; // reset

    // Stream Manipulator - Floating Point
    // Default: setprecision(6 digit, rounding always occur), fixed(no fixed num after decimal), noshowpoint(no trailing 0), nouppercase, noshowpos
    // Affects all further output to stream
    // double num1{1234.5678};
    // double num2{123456789.987654321};
    // std::cout << std::setprecision(3); 
    // std::cout << std::fixed; // 6 digits right after the decimal point 
    // std::cout << std::scientific << std::uppercase << std::showpos;
    // std::cout << num1 << std::endl;
    // std::cout << num2 << std::endl;

    // Stream Manipulator - Align and Fill
    // Default: setw(not set by default), left(no width defined, right when width defined), fill(not set by default, blank spacce used) 
    // Some manipulators affects only the next data element put on the stream
    double num11{1234.5678};
    std::string hello11{"Hello"};

    // set width only appiled to the first element inserted into the stream
    // set fill is persistant
    std::cout << std::setfill('-') <<std::setw(10) << num11 << std::setw(10) << hello11 << std::endl; 






    return 0;
}
