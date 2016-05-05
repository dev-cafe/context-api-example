def _example(lib):
    account1 = lib.example_new()

    lib.example_deposit(account1, 100.0)
    lib.example_deposit(account1, 100.0)

    account2 = lib.example_new()

    lib.example_deposit(account2, 200.0)
    lib.example_deposit(account2, 200.0)

    lib.example_withdraw(account1, 50.0)

    assert lib.example_get_balance(account1) == 150.0
    assert lib.example_get_balance(account2) == 400.0

    lib.example_free(account1)
    lib.example_free(account2)


def test_fortran():
    from example import f_lib
    _example(f_lib)


def test_cpp():
    from example import c_lib
    _example(c_lib)
