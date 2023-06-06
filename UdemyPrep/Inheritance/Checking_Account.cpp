#include "Checking_Account.h"
#include <iostream>

Checking_Account::Checking_Account(std::string name, double balance): Account(name,balance){}

bool Checking_Account::withdraw(double amount)
{
    if (Account::withdraw(amount+1.5))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &checking_account)
{
    os << "[Checking_Account: " << checking_account.name << ": " << checking_account.balance  << "]";
    return os;
}