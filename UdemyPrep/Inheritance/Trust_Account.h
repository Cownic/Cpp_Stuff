#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
    friend std::ostream &operator<<(std::ostream &os , const Trust_Account &trust_account);

    private:
        static constexpr const char *def_name = "Unnamed Savings Account";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
        static constexpr int max_withdrawal = 3;
        static constexpr double limit_per_withdraw = 0.2;
        static constexpr double bonus = 50.0;
        static constexpr double bonus_req = 5000;
    protected:
        int num_of_withdrawals;
    public:
        Trust_Account(std::string name=def_name, double balance= def_balance, double int_rate=def_int_rate);
        bool withdraw(double amount);
        bool deposit(double amount);


};

#endif