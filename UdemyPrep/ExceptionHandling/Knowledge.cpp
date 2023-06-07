/*
    Exception Handling
    - Deals with extraordinary situations
    - indicates that an extraordinary situation has occured
    - Porgram can deal with the extraordinary situations in a suitable manner

    Exception safe --> code handles exceptions

    Exception --> an object or primitive type that signals that an error has occured

    Throwing an exception
    - code detects an error has occurred or will occur
    - place where the error occur may not know how to handle the error
    - throw exception to another part of the program that knows how to handle the error

    Catching an exception
    - code that handles the exception
    - may or may not cause the program to terminate
    - always catch an exception by reference

    Stack Unwinding
    - to find a handler for the exception
    - function which the exception was not caught terminates and is removed from the call stack
    - if stack is unwound back to main and no catch handler handles the exception, the program terminates

    User-defined exceptions
    - throw an object, not a primitive type
    - throw an object by value
    - catch an objext by reference/ const reference

    Class-Level Exceptions
    - Methods --> works the same way as functions
    - Constructor --> constructor may fail, do not return any value, thorws an exception if cannot initalize an object
    - DO NOT throw exceptions from your destructor

    C++ Standard Library Exception Class Hierarchy
    - std::exception is the base class
    - all subclasses implement the what() virtaul function
    - virtual const char *what() const noexcept;

*/

#include <iostream>
#include <memory>
#include <vector>

// Creating exception classes
class DivideByZeroException: public std::exception{
    public:
        DivideByZeroException() noexcept = default;
        ~DivideByZeroException() = default;
        virtual const char* what() const noexcept
        {
            return "Illegal balance exception";
        }
};

class NegativeValueException{};

double calculate_avg(int sum, int total)
{
    if (total == 0)
    {
        throw DivideByZeroException();
    }
    if (total < 0)
    {
        throw NegativeValueException();
    }
    return static_cast<double>(sum)/total;
}

int main()
{
    double sum{10.0};
    double total{0.0};
    double average {};
    try
    {
        average = calculate_avg(sum, total);
        std::cout << average << std::endl;
    }
    catch(const DivideByZeroException &error)
    {
        std::cerr << error.what() << '\n';
    }
    catch(const NegativeValueException &error)
    {
        std::cerr << "Negative Values not allowed" << std::endl;
    }
    catch(...)
    {
        std::cerr << "All other errors" << std::endl;
    }

    std::cout << "Program Continues" << std::endl;
    
    return 0;
}