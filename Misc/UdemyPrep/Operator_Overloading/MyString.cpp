#include <cstring>
#include <iostream>
#include <istream>
#include "MyString.h"

Mystring::Mystring(): str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s): str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else 
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str , s);
    }
}

Mystring::Mystring(const Mystring &source): str{nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str , source.str);
}

Mystring::~Mystring()
{
    delete [] str;
}

// Works with l-value references
Mystring &Mystring::operator=(const Mystring &rhs) 
{
    // Doing a deep copy
    // This will refer to the LHS, which we wanna copy RHS info to
    std::cout << "l-value copy is running" << std::endl;
    if (this == &rhs)
    {
        return *this;
    }

    delete[] str;

    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str , rhs.str);
    return *this;
}

// Work for r-value references
Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout << "r-value copy is running" << std::endl;
    if (this == &rhs)
    {
        return *this;
    }

    delete [] str;     // delete lhs stuff
    str = rhs.str;     // steal the rhs pointer
    rhs.str = nullptr; // null oput the rhs object
    return *this;      // return current object (LHS)
}

// Unary Operator of -
Mystring Mystring::operator-() const
{
    char *buff = new char[std::strlen(str + 1)];
    std::strcpy(buff , str);
    for (size_t i = 0 ; i < std::strlen(buff) ; i++)
    {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

// Binary Operator that is used to compare if the string in both objects are the same
// Can be off different address
bool Mystring::operator==(const Mystring &rhs) const
{
    // if they are the same object, string will be the same
    if (this == &rhs)
    {
        return true;
    }
    if (std::strcmp(str , rhs.str) == 0)
    {
        return true;
    }
    return false;
}

// Use to concat the string together
Mystring Mystring::operator+(const Mystring &rhs) const
{
    size_t size = std::strlen(str + 1) + std::strlen(rhs.str);

    char *buff = new char[size];

    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    // Cos I am returning a Mystring objct
    Mystring temp{buff};
    delete [] buff;
    return temp;

}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}

void Mystring::display() const
{
    std::cout << str << get_length() <<std::endl;
}

//Friend functions
// bool operator==(const Mystring &lhs, const Mystring &rhs)
// {
//     if (std::strcmp(lhs.str, rhs.str) == 0)
//     {
//         return true;
//     }
//     return false;
// }

// Mystring operator-(const Mystring &obj)
// {
//     size_t size = std::strlen(obj.str) + 1;
//     char *buff = new char[size];
//     std::strcpy(buff, obj.str);
//     for (int i = 0 ; i < size ; i++)
//     {
//         buff[i] = std::tolower(buff[i]);
//     }
//     Mystring temp{buff};
//     delete [] buff;
//     buff = nullptr;
//     return temp;
// }

// Mystring operator+(const Mystring &lhs, const Mystring &rhs)
// {
//     size_t size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
//     char *buff = new char[size];
//     std::strcpy(buff, lhs.str);
//     std::strcat(buff, rhs.str);
//     Mystring temp{buff};
//     delete [] buff;
//     buff = nullptr;
//     return temp;
// }

// Overloading stream Insertion operator <<
// output by reference to ostream so we can keep inserting or chain the operator
 std::ostream &operator<<(std::ostream &os, const Mystring &obj)
{
    //os << obj.str; //if this is declared as a friend function
    os << obj.get_str(); // allow me to output the string member straight to terminal
    return os;
}

// Overloading stream extraction operator
std::istream &operator>>(std::istream &is, Mystring &obj)
{
    char *buff = new char[1000]; // this limit is set by user
    is >> buff;                  // read from the terminal input
    obj = Mystring{buff};        // move semantic is required
    delete [] buff;
    buff = nullptr;
    return is;
}