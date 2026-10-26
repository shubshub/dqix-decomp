#include <globaldefs.h>

struct Struct_ov023_021dceac {
#if defined(jpn)
    char padding[0x700];
#else
    char padding[0x784];
#endif
    const char* names[3];
    unsigned char unknown_790_[3];
    unsigned char unknown_793_[3];
    unsigned char unknown_796_[3];
};

// USA: func_ov023_021dceac
extern "C" ARM void func_ov023_021dceac(char* obj, int idx, int val, unsigned char b1, unsigned char b2, unsigned char b3) {
    Struct_ov023_021dceac* rows = (Struct_ov023_021dceac*)obj;
    rows->names[idx] = (const char*)val;
    rows->unknown_790_[idx] = b1;
    rows->unknown_793_[idx] = b2;
    rows->unknown_796_[idx] = b3;
}
