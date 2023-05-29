// Guards included to ensure that this particular header file is only included once into the program
// Or can use #pragma once to ensure that this header file is included once only
#ifndef _LOGIN_H_
#define _LOGIN_H_
#include <iostream>
#include <string.h>


class Login{
  private:
    std::string username;
    std::string password;
  
  public:
    Login();
    Login(std::string username, std::string password);
    ~Login();
    std::string getUsername();
    std::string getPassword();
    bool checkCredentials(std::string username , std::string password);
    
};

#endif