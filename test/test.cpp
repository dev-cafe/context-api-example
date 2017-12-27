#include <cassert>

#include "account.h"

int main()
{
    Account *account1 = account_new();

    account_deposit(account1, 100.0);
    account_deposit(account1, 100.0);

    Account *account2 = account_new();

    account_deposit(account2, 200.0);
    account_deposit(account2, 200.0);

    account_withdraw(account1, 50.0);

    assert(account_get_balance(account1) == 150.0);
    account_free(account1);

    assert(account_get_balance(account2) == 400.0);
    account_free(account2);

    return 0;
}
