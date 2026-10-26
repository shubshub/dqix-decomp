#include <globaldefs.h>
#include "std_library_functions.h"

typedef void (*Callback0204adb4)(void*, int, int);

// Main, originally CopyWordAndInvokeCallback0204adb4 (USA 0x0204adb4, EUR 0x0204adc4, JPN 0x0204bbd4)
extern "C" ARM void BackgroundScreen_Upload(unsigned char* dst, Callback0204adb4 callback, unsigned char* src) {
    memcpy(dst + 0x8, src + 0xc, 4);
    callback(src + 0x10, 0, *(int*)(dst + 0x8));
}
