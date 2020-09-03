#if !defined(TYPES_H)
#define TYPES_H

#include <stdint.h>

typedef int8_t s8;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint64_t u64;


#define OUTPUT_MAX_LEN 128 // 1024
struct BytesResult {
    //u8 bytes[OUTPUT_MAX_LEN];
    const u8* bytes;
    s64 length;
    u64 error;
};

#endif // TYPES_H
