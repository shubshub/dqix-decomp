#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include <std_library_functions.h>

extern "C" int func_ov031_0220bb24(unsigned short* arr, int len);
extern "C" unsigned long long func_ov031_0220c090(unsigned short* p);
extern "C" unsigned long long func_ov031_0220c09c(volatile unsigned short* p);
extern "C" unsigned long long func_ov031_0220c0ac(unsigned short* p);
extern "C" unsigned long long func_ov031_0220c0c0(unsigned short* p);
extern "C" void func_ov031_0220bee4(unsigned short* dst, unsigned short* src, int arg2, int len);
extern "C" int func_ov031_0220bdcc(unsigned short* a, unsigned short* b, int count);
extern "C" void func_ov031_0220bcbc(unsigned short* destination, unsigned short* left, unsigned short* right, int length);

// USA: func_ov031_0220c0dc
extern "C" ARM void func_ov031_0220c0dc(unsigned short* arg0, unsigned short* arg1,
    unsigned short* arg2, unsigned short* arg3, int count, unsigned short* work) {
    int i;
    unsigned int digit;
    int var2;
    unsigned short* q;
    unsigned short* r;
    int var5;
    unsigned long long top;
    int var7;

    q = work + count;
    r = q + count;
    VectorizedMemset(q, 0, count * 4);
    var5 = func_ov031_0220bb24(arg1, count);
    var2 = func_ov031_0220bb24(arg2, count);
    if (var5 > 0 && var2 > 0) {
        i = count - var5 + var2 - 1;
        if (i >= count) {
            VectorizedInvertedMemcpy(arg1, r, count * 2);
        } else {
            VectorizedInvertedMemcpy(arg1, q + i, var5 * 2);
            if (var2 > 2) top = func_ov031_0220c0ac(arg2 + var2 - 1);
            else if (var2 > 1) top = func_ov031_0220c09c(arg2 + var2 - 1);
            else top = func_ov031_0220c090(arg2 + var2 - 1);
            if (i < count) {
                var7 = (count * 2 - 1) * 2;
                do {
                    memmove(q + 1, q, var7);
                    digit = func_ov031_0220c0c0(r + var2) / top;
                    if (digit > 0xffff) digit = 0xffff;
                    while (1) {
                        func_ov031_0220bee4(work, arg2, (unsigned short)digit, count);
                        if (func_ov031_0220bdcc(r, work, count) >= 0) break;
                        digit--;
                    }
                    func_ov031_0220bcbc(r, r, work, count);
                    *q = digit;
                    i++;
                } while (i < count);
            }
        }
    }
    if (arg0) VectorizedInvertedMemcpy(q, arg0, count * 2);
    if (arg3) VectorizedInvertedMemcpy(r, arg3, count * 2);
}
