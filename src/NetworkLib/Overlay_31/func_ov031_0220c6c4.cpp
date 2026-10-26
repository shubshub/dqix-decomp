#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern void* (*data_ov031_0224c994)(unsigned int);
extern void (*data_ov031_0224c9c0)(void*);

extern "C" int func_ov031_0220bb24(unsigned short*, int);
extern "C" void func_ov031_0220bd64(unsigned short*, unsigned short*, int, int);
extern "C" void func_ov031_0220c450(unsigned short*, unsigned short*, unsigned short*, int, unsigned short*);
extern "C" void func_ov031_0220be38(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220c0dc(unsigned short*, unsigned short*, unsigned short*, unsigned short*, int, unsigned short*);
extern "C" void func_ov031_0220c59c(unsigned short*, unsigned short*, unsigned short*, int, int, unsigned short*, unsigned short*, unsigned short*, unsigned short*);

// USA: func_ov031_0220c6c4
extern "C" ARM void func_ov031_0220c6c4(unsigned short* output, unsigned short* base,
    unsigned short* arg2, int count, unsigned short* arg4)
{
    int var0 = count * 22;
    unsigned short* storage = static_cast<unsigned short*>(data_ov031_0224c994(var0));
    if (!storage) {
        return;
    }
    VectorizedMemset(storage, 0, var0);
    int var2;
    int bit;
    unsigned short* scratch;
    unsigned short* var5;
    unsigned short* var6;
    unsigned short* var7;
    unsigned short* var8;
    unsigned short* accumulator;
    var5 = storage + count;
    var6 = var5 + count;
    var7 = var6 + count;
    var8 = var7 + count;
    accumulator = var8 + count;
    scratch = accumulator + count;
    var2 = func_ov031_0220bb24(arg4, count);
    storage[var2] = 1;
    func_ov031_0220c450(var5, storage, arg4, count, var6);
    func_ov031_0220be38(var7, storage, var5, count);
    func_ov031_0220bd64(var5, var7, 1, count);
    func_ov031_0220c0dc(var5, var5, arg4, 0, count, scratch);
    func_ov031_0220be38(var6, base, storage, count);
    func_ov031_0220c0dc(0, var6, arg4, var6, count, scratch);
    func_ov031_0220c0dc(0, storage, arg4, output, count, scratch);
    for (bit = 0; bit < (unsigned int)var2 * 16; bit++) {
        func_ov031_0220c59c(output, accumulator, (unsigned short*)1,
            count, var2, arg4, var5, var7, var8);
        if (arg2[var2 - (bit >> 4) - 1] & (0x8000u >> (bit & 15))) {
            func_ov031_0220c59c(output, accumulator, var6, count,
                var2, arg4, var5, var7, var8);
        }
    }
    func_ov031_0220c59c(output, accumulator, 0, count, var2,
        arg4, var5, var7, var8);
    data_ov031_0224c9c0(storage);
}
