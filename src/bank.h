#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

class Bank
{
  public:
    Bank();
    ~Bank();

    void deposit(const double f);
    double get_balance() const;

  private:
    Bank(const Bank &rhs);            // not implemented
    Bank &operator=(const Bank &rhs); // not implemented

    double balance;

    void check_that_context_is_initialized() const;
    bool is_initialized = false;
};

#endif
