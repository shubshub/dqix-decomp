#include <globaldefs.h>
#include "std_library_functions.h"

typedef void (*Cb0204aa64)(void*, int, unsigned int);

struct Obj0204aa64 {
    unsigned char  f0;
    unsigned char  pad1;
    unsigned short f2;
};

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

// Main, originally func_0204aa64 (USA 0x0204aa64, EUR 0x0204aa74, JPN 0x0204b884)
extern "C" ARM int Background_LoadPalette(Obj0204aa64* obj, Cb0204aa64 cb, unsigned char* src, void* extra) {
    int val;
    int tmp;
    char var2[3];
    memcpy(&tmp, src, 4);
    memcpy(obj, src + 4, 1);
    memcpy(var2, src + 5, 3);
    memcpy(&val, src + 8, 4);
    if (obj->f2 == 0xffff) {
        CleanInvalidateCacheRange(src + 0xc, val);
        cb(src + 0xc, 0, val);
    } else {
        int mask = obj->f2 & 0xff;
        int i;
        for (i = 0; i < 16; i++) {
            if (mask & 1) {
                CleanInvalidateCacheRange(src + 0xc + i * 32, 32);
                cb(src + 0xc + i * 32, i * 32, 32);
            }
            mask = (mask >> 1) & 0xff;
        }
    }
    return 0;
}