from dataclasses import dataclass, field
from typing import Any

from ._account import lib


@dataclass
class Account:
    _context: Any = field(repr=False, init=False, compare=False)

    def __post_init__(self):
        self._context = lib.account_new()

    def __del__(self):
        lib.account_free(self._context)

    @property
    def balance(self) -> float:
        return lib.account_get_balance(self._context)

    def deposit(self, amount: float) -> None:
        lib.account_deposit(self._context, amount)

    def withdraw(self, amount: float) -> None:
        lib.account_withdraw(self._context, amount)
