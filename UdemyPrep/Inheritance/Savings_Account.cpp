#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name,double balance,double int_rate): Account(name,balance), int_rate{int_rate}
{
    std::cout << "Saving Account Constructor called" << std::endl;
}

bool Savings_Account::deposit(double amount)
{
    double incremnted_val = amount + (amount * (int_rate/100));
    return Account::deposit(incremnted_val);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &savings_account)
{
    os << "[Account: " << savings_account.name << " Balance: " << savings_account.balance << " INT_RATE: " << savings_account.int_rate << "]\n";
    return os;
}