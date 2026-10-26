#include <globaldefs.h>

struct Struct_020cfaf4;
extern "C" void func_020cfaf4(struct Struct_020cfaf4* out, int time);

extern "C" void func_020cf9f4(void* out, int arg1);
extern "C" int _ll_mod(unsigned int lo, unsigned int hi, unsigned int arg2, unsigned int arg3);
extern "C" int _ll_sdiv(unsigned int lo, unsigned int hi, unsigned int arg2, unsigned int arg3);

// USA: func_020cfb74
extern "C" ARM void func_020cfb74(void* arg0, struct Struct_020cfaf4* arg1, long long arg2) {
    if (arg2 < 0) {
        arg2 = 0;
    } else if (arg2 > 0xbc19137fLL) {
        arg2 = 0xbc19137fLL;
    }
    unsigned int lo = (unsigned int)arg2;
    unsigned int hi = (unsigned int)(arg2 >> 32);
    int var2 = _ll_mod(lo, hi, 0x15180, 0);
    func_020cfaf4(arg1, var2);
    int var3 = _ll_sdiv(lo, hi, 0x15180, 0);
    func_020cf9f4(arg0, var3);
}
