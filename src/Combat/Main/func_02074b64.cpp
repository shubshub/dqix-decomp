#include <globaldefs.h>

struct Struct_02074b64 {
    char pad0[2];
    volatile unsigned short unknown_2_;
    char pad4[2];
    volatile unsigned short unknown_6_;
    char pad8[2];
    volatile unsigned short unknown_a_;
    char unknown_c_[2];
    volatile unsigned short unknown_e_;
    char pad10;
    unsigned char initialized;
};

// USA: func_02074b64
extern "C" ARM void func_02074b64(struct Struct_02074b64* obj) {
    if (obj->initialized != 0) return;
    unsigned short* const reg = (unsigned short*)0x4001008;
    volatile short v0, v1, v2, v3;
    {
        unsigned short raw = *(volatile unsigned short*)&reg[0];
        v0 = raw;
        obj->unknown_2_ = raw;
        v0;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[1];
        obj->unknown_6_ = raw;
        v1 = raw;
        v1;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[2];
        v2 = raw;
        v2;
        obj->unknown_a_ = raw;
        v2;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[3];
        obj->unknown_e_ = raw;
        v3 = raw;
        v3;
    }
    obj->initialized = 1;
}
