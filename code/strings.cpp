//
//  strings.cpp
//  Multiplatform Test iOS
//
//  Created by Brendon Duncan on 4/09/20.
//  Copyright © 2020 Brendon Duncan. All rights reserved.
//

#include "types.h"

inline u64 strlen(const char* s) {
    char c;
    u64 i = 0;
    do {
        c = s[i++];
    } while (c != 0);
        
    return i;
}
