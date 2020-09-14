//
//  strings.cpp
//  Multiplatform Test iOS
//
//  Created by Brendon Duncan on 4/09/20.
//  Copyright © 2020 Brendon Duncan. All rights reserved.
//

#include "types.h"


inline u64 strlen(const char* s) {
    u64 len = 0;
    for (; s[len]; len++);

    return len;
}

// Does not include space.
inline bool isViewableAscii(u8 c) {
    return (c >= 0x21 && c <= 0x7e);
}