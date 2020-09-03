#include "slp.h"

#include "strings.cpp"

static u8 genesis[MAX_GENESIS_LEN];

s64 add3(s64 a) {
    return a + 3;
}

BytesResult createGenesis(const char* ticker) {
    for (int i = 0; i < MAX_GENESIS_LEN; ++i) {
        genesis[i] = 0;
    }
    BytesResult br = { genesis };
    
    // Do input validation here
    u64 tickerLen = strlen(ticker);
    if (tickerLen > MAX_TICKER_LEN) {
        br.error = 1;  // TODO: Error number
        return br;
    }
    
    u64 b = 0;
    genesis[b++] = 'S';
    genesis[b++] = 'L';
    genesis[b++] = 'P';
    
    for (u64 i = 0; i < MAX_TICKER_LEN; ++i) {
        char c = ticker[i];
        if (!c) {
            break;
        }
        genesis[b++] = c;
    }
    
    br.length = b;
    
    return br;
}
