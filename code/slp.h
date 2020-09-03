#if !defined(SLP_H)
#define SLP_H

#include "types.h"

#define CHARACTER_MAX_LEN 4 // UTF-8
#define MAX_TICKER_CHARACTERS 6 // Arbitrary, may need to increase this
#define MAX_TICKER_LEN (MAX_TICKER_CHARACTERS * CHARACTER_MAX_LEN) + 1 // +1 for null terminator

#define MAX_GENESIS_LEN 1024

#ifdef __cplusplus
extern "C" {
#endif

s64 add3(s64 a);

struct BytesResult createGenesis(const char* ticker);

#ifdef __cplusplus
}
#endif

#endif // SLP_H

