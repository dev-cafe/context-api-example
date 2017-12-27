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

    void stop_if_uninitialized() const;
    bool is_initialized = false;
};
