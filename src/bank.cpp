#include <cstdio>
#include <numeric>

#include "bank.h"
#include "example.h"

#define AS_TYPE(Type, Obj) reinterpret_cast<Type *>(Obj)
#define AS_CTYPE(Type, Obj) reinterpret_cast<const Type *>(Obj)

example_context_t *example_new()
{
    return AS_TYPE(example_context_t, new Bank());
}
Bank::Bank() {}

void example_free(example_context_t *context)
{
    if (!context)
        return;
    delete AS_TYPE(Bank, context);
}
Bank::~Bank() { history.clear(); }

void example_deposit(example_context_t *context, const double f)
{
    return AS_TYPE(Bank, context)->deposit(f);
}
void example_withdraw(example_context_t *context, const double f)
{
    return AS_TYPE(Bank, context)->deposit(-f);
}
void Bank::deposit(const double f) { history.push_back(f); }

double example_get_balance(const example_context_t *context)
{
    return AS_CTYPE(Bank, context)->get_balance();
}
double Bank::get_balance() const
{
    return std::accumulate(history.begin(), history.end(), 0.0);
}

void example_print_history(const example_context_t *context)
{
    return AS_CTYPE(Bank, context)->print_history();
}
void Bank::print_history() const
{
    printf("transaction history:\n");
    for (int i = 0; i < history.size(); i++)
    {
        printf("    %f\n", history[i]);
    }
}
