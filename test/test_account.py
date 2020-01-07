import pytest

from account import Account


def test_account():
    account1 = Account()
    account1.deposit(100.0)
    account1.deposit(100.0)

    account2 = Account()
    account2.deposit(200.0)
    account2.deposit(200.0)

    account1.withdraw(50.0)

    assert account1.balance == pytest.approx(150.0)

    assert account2.balance == pytest.approx(400.0)
