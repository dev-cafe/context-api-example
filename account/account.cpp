#include <cstdio>
#include <fstream>
#include <numeric>
#include <stdlib.h>

#include "account.h"
#include "example.h"

#define AS_TYPE(Type, Obj) reinterpret_cast<Type *>(Obj)
#define AS_CTYPE(Type, Obj) reinterpret_cast<const Type *>(Obj)

example_context_t *example_new()
{
    return AS_TYPE(example_context_t, new Account());
}
Account::Account()
{
    balance = 0.0;
    is_initialized = true;
}

void example_free(example_context_t *context)
{
    if (!context)
        return;
    delete AS_TYPE(Account, context);
}
Account::~Account()
{
    balance = 0.0;
    is_initialized = false;
}

void Account::check_that_context_is_initialized() const
{
    if (not is_initialized)
    {
        fprintf(stderr, "ERROR: context is not initialized\n");
        exit(-1);
    }
}

void example_deposit(example_context_t *context, const double f)
{
    return AS_TYPE(Account, context)->deposit(f);
}
void example_withdraw(example_context_t *context, const double f)
{
    return AS_TYPE(Account, context)->deposit(-f);
}
void Account::deposit(const double f)
{
    check_that_context_is_initialized();
    balance += f;
}

double example_get_balance(const example_context_t *context)
{
    return AS_CTYPE(Account, context)->get_balance();
}
double Account::get_balance() const
{
    check_that_context_is_initialized();
    return balance;
}
