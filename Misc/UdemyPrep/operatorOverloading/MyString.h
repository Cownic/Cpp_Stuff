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

        // Adding const to the end of the funcion will make that "this" pointer is const-qualified
        void display() const;
        int get_length() const;
        const char *get_str() const;
};

#endif