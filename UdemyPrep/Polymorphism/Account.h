// Simple Account
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>
#include "I_Printable.h"

class Account : public I_Printable
{
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

protected:
    std::string name;
    double balance;

public:
    // Constructor is still needed when we are creating derived objects
    Account(std::string name = def_name, double balance = def_balance);
    // Even tho we declare as virtual, we can still do the implementation as long as it make sense
    virtual bool deposit(double amount)=0;
    virtual bool withdraw(double amount)=0;
    virtual ~Account() = default;
    virtual void print(std::ostream &os) const;
};
#endif