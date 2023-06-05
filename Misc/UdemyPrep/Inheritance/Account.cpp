#include "Account.h"

Account::Account(std::string name , double balance):name{name}, balance{balance}
{
    std::cout << "Account Constructor called" << std::endl;
}

bool Account::deposit(double amount)
{
    balance+=amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (amount > balance)
    {
        return false;
    }
    balance-=amount;
    return true;
}

double Account::get_balance() const
{
    return balance;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os<< "[Account: " << account.name << " Balance: " << account.balance << "]\n";
    return os;
}