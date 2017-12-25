#pragma once

class Account
{
  public:
    Account();
    ~Account();

    Account(const Account &rhs) = delete;
    Account &operator=(const Account &rhs) = delete;

    void deposit(const double f);
    double get_balance() const;

  private:
    double balance;

    void check_that_context_is_initialized() const;
    bool is_initialized = false;
};
