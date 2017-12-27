#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#ifndef ACCOUNT_API
#include "c_account_export.h"
#define ACCOUNT_API C_ACCOUNT_EXPORT
#endif

#ifdef __cplusplus
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

    void check_valid_context() const;
    bool is_initialized = false;
};
#else
struct account_context;
typedef struct account_context Account;
#endif

#ifdef __cplusplus
extern "C" {
#endif

ACCOUNT_API
Account *account_new();

ACCOUNT_API
void account_free(Account *context);

ACCOUNT_API
void account_deposit(Account *context, const double amount);

ACCOUNT_API
void account_withdraw(Account *context, const double amount);

ACCOUNT_API
double account_get_balance(const Account *context);

#ifdef __cplusplus
}
#endif

#endif /* ACCOUNT_H_INCLUDED */
