#include <fstream>

#include "cpp_implementation.h"

Account::Account()
{
    balance = 0.0;
    is_initialized = true;
}

Account::~Account()
{
    check_valid_context();
    balance = 0.0;
    is_initialized = false;
}

void Account::check_valid_context() const
{
    if (not is_initialized)
    {
        fprintf(stderr, "ERROR: context is not initialized\n");
        exit(-1);
    }
}

void Account::deposit(const double amount)
{
    check_valid_context();
    balance += amount;
}

void Account::withdraw(const double amount)
{
    check_valid_context();
    balance -= amount;
}

double Account::get_balance() const
{
    check_valid_context();
    return balance;
}
