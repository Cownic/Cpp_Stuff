#ifndef _ACCOUNT_UTIL_H
#define _ACCOUNT_UTIL_H
#include <vector>
#include "Account.h"
#include "Savings_Account.h"

// Utility helper function for Account class

void display(const std::vector<Account> &account);
void deposit(std::vector<Account> &account, double amount);
void withdraw(std::vector<Account> &account, double amount);

// Utility helper functions for Savings Account class
void display(const std::vector<Savings_Account> &savings_account);
void deposit(std::vector<Savings_Account> &savings_account, double amount);
void withdraw(std::vector<Savings_Account> &savings_account, double amount);

#endif