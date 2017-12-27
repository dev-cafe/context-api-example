#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED

#ifndef EXAMPLE_API
#include "c_example_export.h"
#define EXAMPLE_API C_EXAMPLE_EXPORT
#endif

#ifdef __cplusplus
class example_context_t
{
  public:
    example_context_t();
    ~example_context_t();

    example_context_t(const example_context_t &rhs) = delete;
    example_context_t &operator=(const example_context_t &rhs) = delete;

    void deposit(const double f);
    double get_balance() const;

  private:
    double balance;

    void stop_if_uninitialized() const;
    bool is_initialized = false;
};
#else
//#ifndef __cplusplus
struct example_context_s;
typedef struct example_context_s example_context_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

EXAMPLE_API
example_context_t *example_new();

EXAMPLE_API
void example_free(example_context_t *context);

EXAMPLE_API
void example_deposit(example_context_t *context, const double f);

EXAMPLE_API
void example_withdraw(example_context_t *context, const double f);

EXAMPLE_API
double example_get_balance(const example_context_t *context);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLE_H_INCLUDED */
