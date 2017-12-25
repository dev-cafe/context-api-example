#pragma once

class Bank
{
  public:
    Bank();
    ~Bank();

    Bank(const Bank &rhs) = delete;
    Bank &operator=(const Bank &rhs) = delete;

    void deposit(const double f);
    double get_balance() const;

  private:
    double balance;

    void check_that_context_is_initialized() const;
    bool is_initialized = false;
};
