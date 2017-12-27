#include <cstdio>
#include <fstream>
#include <numeric>
#include <stdlib.h>

#include "account.h"

#define AS_TYPE(Type, Obj) reinterpret_cast<Type *>(Obj)
#define AS_CTYPE(Type, Obj) reinterpret_cast<const Type *>(Obj)

example_context_t *example_new()
{
    return AS_TYPE(example_context_t, new example_context_t());
}
example_context_t::example_context_t()
{
    balance = 0.0;
    is_initialized = true;
}

void example_free(example_context_t *context)
{
    if (!context)
        return;
    delete AS_TYPE(example_context_t, context);
}
example_context_t::~example_context_t()
{
    balance = 0.0;
    is_initialized = false;
}

void example_context_t::stop_if_uninitialized() const
{
    if (not is_initialized)
    {
        fprintf(stderr, "ERROR: context is not initialized\n");
        exit(-1);
    }
}

void example_deposit(example_context_t *context, const double f)
{
    return AS_TYPE(example_context_t, context)->deposit(f);
}
void example_withdraw(example_context_t *context, const double f)
{
    return AS_TYPE(example_context_t, context)->deposit(-f);
}
void example_context_t::deposit(const double f)
{
    stop_if_uninitialized();
    balance += f;
}

double example_get_balance(const example_context_t *context)
{
    return AS_CTYPE(example_context_t, context)->get_balance();
}
double example_context_t::get_balance() const
{
    stop_if_uninitialized();
    return balance;
}
