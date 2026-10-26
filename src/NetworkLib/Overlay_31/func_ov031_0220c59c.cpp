#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include <std_library_functions.h>

extern "C" void func_ov031_0220bf5c(unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220be38(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220bb7c(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" void func_ov031_0220bcbc(unsigned short*, unsigned short*, unsigned short*, int);
extern "C" int func_ov031_0220bdcc(unsigned short*, unsigned short*, int);

// USA: func_ov031_0220c59c
extern "C" ARM void func_ov031_0220c59c(unsigned short* value, unsigned short* backup,
    unsigned short* arg2, int count, int shift, unsigned short* arg5,
    unsigned short* arg6, unsigned short* arg7, unsigned short* arg8) {
    int bytes = count * 2;
    VectorizedInvertedMemcpy(value, backup, bytes);
    if (arg2 == (unsigned short*)1) func_ov031_0220bf5c(value, backup, count);
    else if (arg2) func_ov031_0220be38(value, backup, arg2, count);
    func_ov031_0220be38(arg7, value, arg6, shift);
    int var1 = (count - shift) * 2;
    VectorizedMemset(arg7 + shift, 0, var1);
    func_ov031_0220be38(arg8, arg7, arg5, count);
    func_ov031_0220bb7c(value, value, arg8, count);
    memmove(value, value + shift, var1);
    VectorizedMemset(value + count - shift, 0, shift * 2);
    int var2 = func_ov031_0220bdcc(value, arg5, count);
    switch (var2) {
    case 0:
        VectorizedMemset(value, 0, bytes);
        break;
    case 1:
        func_ov031_0220bcbc(value, value, arg5, count);
        break;
    }
}
