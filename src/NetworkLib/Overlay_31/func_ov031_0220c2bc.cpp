#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0220bb24(unsigned short*, int);
extern "C" void func_ov031_0220bf5c(unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220c0dc(unsigned short*, unsigned short*, unsigned short*, unsigned short*, int, unsigned short*);
extern "C" void func_ov031_0220be38(unsigned short*, unsigned short*, unsigned short*, int);
extern void* (*data_ov031_0224c994)(unsigned int);
extern void (*data_ov031_0224c9c0)(void*);

// USA: func_ov031_0220c2bc
extern "C" ARM void func_ov031_0220c2bc(unsigned short* result, unsigned short* base, unsigned short* arg2, int length, unsigned short* arg4) {
    unsigned short* var0 = (unsigned short*)data_ov031_0224c994(length * 8);
    if (!var0) return;
    unsigned short* scratch = var0 + length;
    VectorizedMemset(result + 1, 0, (length - 1) * 2);
    result[0] = 1;
    int bit = (length - func_ov031_0220bb24(arg2, length)) * 16;
    if ((unsigned int)bit < (unsigned int)(length << 4)) { do {
        if ((arg2 + (length - (bit >> 4)))[-1] & (0x8000u >> (bit & 15))) {
            VectorizedInvertedMemcpy(base, result, length * 2);
            ++bit;
            break;
        }
        ++bit;
    } while ((unsigned int)bit < (unsigned int)(length << 4)); }
    if ((unsigned int)bit < (unsigned int)(length << 4)) { do {
        func_ov031_0220bf5c(var0, result, length);
        VectorizedInvertedMemcpy(var0, result, length * 2);
        if (arg4) func_ov031_0220c0dc(0, result, arg4, result, length, scratch);
        if ((arg2 + (length - (bit >> 4)))[-1] & (0x8000u >> (bit & 15))) {
            func_ov031_0220be38(var0, result, base, length);
            VectorizedInvertedMemcpy(var0, result, length * 2);
            if (arg4) func_ov031_0220c0dc(0, result, arg4, result, length, scratch);
        }
        ++bit;
    } while ((unsigned int)bit < (unsigned int)(length << 4)); }
    data_ov031_0224c9c0(var0);
}
