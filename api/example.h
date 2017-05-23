#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED

#ifndef EXAMPLE_API
#include "c_example_export.h"
#define EXAMPLE_API C_EXAMPLE_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct example_context_s;
typedef struct example_context_s example_context_t;

EXAMPLE_API example_context_t *example_new();
EXAMPLE_API void example_free(example_context_t *context);
EXAMPLE_API void example_deposit(example_context_t *context, const double f);
EXAMPLE_API void example_withdraw(example_context_t *context, const double f);
EXAMPLE_API double example_get_balance(const example_context_t *context);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLE_H_INCLUDED */
