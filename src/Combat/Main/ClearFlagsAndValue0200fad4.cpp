#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct State0200fad4 {
    unsigned char key[6];
    unsigned char active : 1;
    unsigned char flags : 7;
    unsigned char pad7;
    float elapsed;
};

// USA: func_0200fad4
// Zeroes the first 6 bytes, clears the flag bits at +0x6, and clears the word at +0x8.
ARM void ClearFlagsAndValue0200fad4(struct State0200fad4* timer) {
    VectorizedMemset(timer->key, 0, sizeof(timer->key));
    timer->active = 0;
    timer->flags = 0;
    timer->elapsed = 0.0f;
}
