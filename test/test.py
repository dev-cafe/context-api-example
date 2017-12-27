def _test_implementation(lib):
    account1 = lib.account_new()

    lib.account_deposit(account1, 100.0)
    lib.account_deposit(account1, 100.0)

    account2 = lib.account_new()

    lib.account_deposit(account2, 200.0)
    lib.account_deposit(account2, 200.0)

    lib.account_withdraw(account1, 50.0)

    assert lib.account_get_balance(account1) == 150.0
    lib.account_free(account1)

    assert lib.account_get_balance(account2) == 400.0
    lib.account_free(account2)


def test_fortran():
    from account import f_lib
    _test_implementation(f_lib)


def test_cpp():
    from account import c_lib
    _test_implementation(c_lib)
