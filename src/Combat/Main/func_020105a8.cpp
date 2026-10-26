#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" long long _ll_udiv(long long a, long long b);

struct Struct_020105a8 {
    unsigned char pad0[0x3e8];
    long long unknown_3e8_;   // 0x3e8
};

// USA: func_020105a8
extern "C" ARM void func_020105a8(Struct_020105a8* obj, int* out) {
    *out = (int)(_ll_udiv(GetCurrentTimestamp() << 6, 0x1ff6210)
               - _ll_udiv(obj->unknown_3e8_ << 6, 0x1ff6210));
}
