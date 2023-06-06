#include "Trust_Account.h"
#include <iostream>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate): Savings_Account(name, balance, int_rate) {
    num_of_withdrawals = 0;
}

bool Trust_Account::withdraw(double amount)
{
    if ((num_of_withdrawals < max_withdrawal) && amount <= (limit_per_withdraw*balance))
    {
        num_of_withdrawals++;
        return Savings_Account::withdraw(amount);
    }
    else 
    {
        return false;
    }
}

bool Trust_Account::deposit(double amount)
{
    if (amount >= bonus_req)
    {
        return Savings_Account::deposit(amount + bonus);
    }
    else 
    {
        return Savings_Account::deposit(amount);
    }
}

std::ostream &operator<<(std::ostream &os , const Trust_Account &trust_account)
{
    os << "[Trust Account: " << trust_account.name << ": " << trust_account.balance << ", " << trust_account.int_rate 
        << "%, withdrawals: " << trust_account.num_of_withdrawals<<  "]";
    return os;
}