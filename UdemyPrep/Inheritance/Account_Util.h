#ifndef _ACCOUNT_UTIL_H
#define _ACCOUNT_UTIL_H
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

// Utility helper function for Account class

void display(const std::vector<Account> &account);
void deposit(std::vector<Account> &account, double amount);
void withdraw(std::vector<Account> &account, double amount);

// Utility helper functions for Savings Account class
void display(const std::vector<Savings_Account> &savings_account);
void deposit(std::vector<Savings_Account> &savings_account, double amount);
void withdraw(std::vector<Savings_Account> &savings_account, double amount);

// Utility helper functions for Checking Account class
void display(const std::vector<Checking_Account> &checking_account);
void deposit(std::vector<Checking_Account> &checking_account, double amount);
void withdraw(std::vector<Checking_Account> &checking_account, double amount);

// Utility helper functions for Trust Account class
void display(const std::vector<Trust_Account> &trust_account);
void deposit(std::vector<Trust_Account> &trust_account, double amount);
void withdraw(std::vector<Trust_Account> &trust_account, double amount);

#endif