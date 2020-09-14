#include "slp.h"

#include <cstdio>
#include "bitcoin.h"
#include "math.cpp"
#include "strings.cpp"



static char debugStr[DEBUG_STR_LEN];
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
    genesis[b++] = OP_FALSE;
    genesis[b++] = OP_RETURN;

    genesis[b++] = 0x04;
    genesis[b++] = 'S';
    genesis[b++] = 'L';
    genesis[b++] = 'P';
    genesis[b++] = 0x00;

    genesis[b++] = 0x01;
    genesis[b++] = SLP_TOKEN_TYPE_1;

    genesis[b++] = 0x07;
    genesis[b++] = 'G';
    genesis[b++] = 'E';
    genesis[b++] = 'N';
    genesis[b++] = 'E';
    genesis[b++] = 'S';
    genesis[b++] = 'I';
    genesis[b++] = 'S';

    genesis[b++] = (u8)tickerLen;

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

char* debugString(BytesResult br) {
    for (int i = 0; i < DEBUG_STR_LEN; ++i) {
        debugStr[i] = 0;
    }

    // prev character was a letter
    bool prevCharWasAscii = false;
    // -1 to ensure null terminator in result
    int processLen = mins64(br.length, MAX_GENESIS_LEN);
    s64 j = 0;
    for (s64 i = 0; i < processLen; ++i)
    {
        // TODO: Check j position

        u8 c = br.bytes[i];
        if (isViewableAscii(c))
        {
            if (j > 0 && !prevCharWasAscii) {
                debugStr[j++] = ' ';
            }
            debugStr[j++] = c;

            prevCharWasAscii = true;
        }
        else
        {
            if (j > 0 && prevCharWasAscii) {
                debugStr[j++] = ' ';
            }
            sprintf((char*)&(debugStr[j]), "%02x", c);
            j += 2;
            prevCharWasAscii = false;
        }

    }

    return debugStr;
}