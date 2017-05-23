#include <cassert>

#include "example.h"


int main()
{
    example_context_t *account1 = example_new();

    example_deposit(account1, 100.0);
    example_deposit(account1, 100.0);

    example_context_t *account2 = example_new();

    example_deposit(account2, 200.0);
    example_deposit(account2, 200.0);

    example_withdraw(account1, 50.0);

    assert (example_get_balance(account1) == 150.0);
    assert (example_get_balance(account2) == 400.0);

    example_free(account1);
    example_free(account2);

    return 0;
}
