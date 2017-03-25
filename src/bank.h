#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <vector>

class Bank
{
  public:
    Bank();
    ~Bank();

    void deposit(const double f);
    double get_balance() const;
    void print_history() const;

  private:
    Bank(const Bank &rhs);            // not implemented
    Bank &operator=(const Bank &rhs); // not implemented

    std::vector<double> history;
};

#endif
