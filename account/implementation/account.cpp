#include <cstdio>
#include <fstream>
#include <numeric>
#include <stdlib.h>

#include "account.h"

#define AS_TYPE(Type, Obj) reinterpret_cast<Type *>(Obj)
#define AS_CTYPE(Type, Obj) reinterpret_cast<const Type *>(Obj)

Account *account_new()
{
    return AS_TYPE(Account, new Account());
}
Account::Account()
{
    balance = 0.0;
    is_initialized = true;
}

void account_free(Account *context)
{
    delete AS_TYPE(Account, context);
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

void account_deposit(Account *context, const double amount)
{
    return AS_TYPE(Account, context)->deposit(amount);
}
void Account::deposit(const double amount)
{
    check_valid_context();
    balance += amount;
}

void account_withdraw(Account *context, const double amount)
{
    return AS_TYPE(Account, context)->withdraw(amount);
}
void Account::withdraw(const double amount)
{
    check_valid_context();
    balance -= amount;
}

double account_get_balance(const Account *context)
{
    return AS_CTYPE(Account, context)->get_balance();
}
double Account::get_balance() const
{
    check_valid_context();
    return balance;
}
