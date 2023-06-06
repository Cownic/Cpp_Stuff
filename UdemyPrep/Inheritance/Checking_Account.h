#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

class Checking_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &checking_account);

    private:
        static constexpr const double transaction_fee = 1.5;
        static constexpr const char *def_name = "Unnamed Checking Account";
        static constexpr double def_balance = 0.0;
    protected:
    public:
        Checking_Account(std::string name=def_name, double balance=def_balance);
        bool withdraw(double amount);
        // Inherit the deposit method from account class
};

#endif