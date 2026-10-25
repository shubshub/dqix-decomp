#include <globaldefs.h>
#include "std_library_functions.h"

typedef void (*Type_0204aa64)(void*, int, unsigned int);

struct Struct_0204aa64 {
    unsigned char  unknown_0_;
    unsigned char  unknown_1_;
    unsigned short unknown_2_;
};

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

// Main, originally func_0204aa64 (USA 0x0204aa64, EUR 0x0204aa74, JPN 0x0204b884)
extern "C" ARM int Background_LoadPalette(Obj0204aa64* obj, Cb0204aa64 cb, unsigned char* src, void* extra) {
    int val;
    int tmp;
    char three[3];
    memcpy(&tmp, src, 4);
    memcpy(obj, src + 4, 1);
    memcpy(three, src + 5, 3);
    memcpy(&val, src + 8, 4);
    if (obj->f2 == 0xffff) {
        CleanInvalidateCacheRange(src + 0xc, val);
        cb(src + 0xc, 0, val);
    } else {
        int var3 = arg0->unknown_2_ & 0xff;
        int var4;
        for (var4 = 0; var4 < 16; var4++) {
            if (var3 & 1) {
                CleanInvalidateCacheRange(arg2 + 0xc + var4 * 32, 32);
                arg1(arg2 + 0xc + var4 * 32, var4 * 32, 32);
            }
            var3 = (var3 >> 1) & 0xff;
        }
    }
    return 0;
}