#ifndef _MYSTRING_H_
#define _MYSTRING_H_

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
};

#endif

/*
    Default is memberwise assignment (shallow copy)
    if we have raw pointer data member, we must do deep copy for them

    overloading the copy assignment operator(deep copy)
    Type &Type::operator=(const Type &rhs)
    this will allow us to do S2 = S1 as S2.operator=(S1)

*/

/*
    l-value : alot of time is on the left side of the equal sign
    r-value : alot of time is on the right side of the equal side

    int i = 10;

    i : has a location in memory
    10 : numeric literal, no memory associated with it until it is assigned to a l-value

    int  a  = i;
    assigning l-value to a l-value

    int &a -> l-value reference
    int &&a -> r-value reference

    this is usually used to optimise code, we can steal resources straight from a temp.
*/

/*
    Unary Operators (++, --, -, !)
    ReturnType Type::operator<op>();

    Binary Operators (+, -, ==, !=, <, > etc)
    ReturnType Type::operator<op>(const Type &rhs)

*/