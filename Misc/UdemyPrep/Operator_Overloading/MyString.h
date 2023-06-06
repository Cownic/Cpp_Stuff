#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <istream>

class Mystring{
    private:
        char *str;
    
    public:
        Mystring();
        Mystring(const char *s);
        Mystring(const Mystring &source); // Copy Constructor
        ~Mystring(); // destructor

        // Overloading operator
        // Returns a Mystring object after copying
        // because we have const in the input parameter, we can take in both l-value and r-value
        // Having const in the parameter, we promise the function will not make any edits on input
        Mystring &operator=(const Mystring &rhs); // for l-value references 

        // Move an r-value reference
        // RHS value cannot be const as we will be making edits to it as we steal the pointer
        Mystring &operator=(Mystring &&rhs);      // for r-value references,

        //Unary Operator Overloading
        // Adding const to the end of the function is so that we will not edit the current object we are working with
        Mystring operator-() const;

        // Binary Operator Overloading, have to take note on what we want to overload
        bool operator==(const Mystring &rhs) const;
        Mystring operator+(const Mystring &rhs) const; 

        // Adding const to the end of the funcion will make that "this" pointer is const-qualified
        void display() const;
        int get_length() const;
        const char *get_str() const;

        // Declaring a friend function here, so that it can directly access this class private members
        // friend Mystring operator-(const Mystring &obj);
        // friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
        // friend bool operator==(const Mystring &lhs, const Mystring &rhs);
};

std::ostream &operator<<(std::ostream &os, const Mystring &obj);
std::istream &operator>>(std::istream &is, Mystring &obj);

#endif

