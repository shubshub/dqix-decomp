#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0220bb4c(unsigned short*, int);
extern "C" void func_ov031_0220c0dc(unsigned short*, unsigned short*, unsigned short*, unsigned short*, int, unsigned short*);
extern "C" void func_ov031_0220be38(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220bcbc(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220bb7c(unsigned short*, unsigned short*, unsigned short*, int);

// USA: func_ov031_0220c450
extern "C" ARM void func_ov031_0220c450(unsigned short* output, unsigned short* input, unsigned short* arg2, int length, unsigned short* arg4) {
    unsigned short* var0 = arg4 + length;
    unsigned short* previous = var0 + length;
    unsigned short* coefficient = previous + length;
    unsigned short* var3 = coefficient + length;
    unsigned short* var4 = var3 + length;
    unsigned short* scratch = var4 + length;
    unsigned int var6 = length * 2;
    VectorizedInvertedMemcpy(input, arg4, var6);
    VectorizedInvertedMemcpy(arg2, previous, var6);
    coefficient[0] = 1;
    if (func_ov031_0220bb4c(arg4, length) > 0) {
        do {
            func_ov031_0220c0dc(var0, previous, arg4, var4, length, scratch);
            VectorizedInvertedMemcpy(arg4, previous, var6);
            VectorizedInvertedMemcpy(var4, arg4, var6);
            func_ov031_0220be38(var4, var0, coefficient, length);
            func_ov031_0220bcbc(var4, var3, var4, length);
            VectorizedInvertedMemcpy(coefficient, var3, var6);
            VectorizedInvertedMemcpy(var4, coefficient, var6);
        } while (func_ov031_0220bb4c(arg4, length) > 0);
    }
    func_ov031_0220bb7c(var3, var3, arg2, length);
    func_ov031_0220c0dc(NULL, var3, arg2, output, length, scratch);
}
