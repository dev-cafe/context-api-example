#pragma once

class Account
{
  public:
    Account();
    ~Account();

    Account(const Account &rhs) = delete;
    Account &operator=(const Account &rhs) = delete;

    void deposit(const double amount);
    void withdraw(const double amount);
    double get_balance() const;

  private:
    double balance;
};
