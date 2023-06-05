#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

    private: // cannot be access directly by derived classes
        static constexpr const char *def_name = "Unamed Account";
        static constexpr double def_balance = 0.0;
    protected:
        std::string name;
        double balance;
    public:
        Account(std::string name = def_name, double balance = def_balance);
        bool deposit(double amount);
        bool withdraw(double amount);
        double get_balance() const; // this should not touch the object using this method at all.
};

#endif