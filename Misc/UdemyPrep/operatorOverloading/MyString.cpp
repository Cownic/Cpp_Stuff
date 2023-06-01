#include <cstring>
#include <iostream>
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
