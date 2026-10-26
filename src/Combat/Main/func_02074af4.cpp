#include <globaldefs.h>

struct Struct_02074af4 {
    volatile unsigned short unknown_0_;
    char pad2[2];
    volatile unsigned short unknown_4_;
    char pad6[2];
    volatile unsigned short unknown_8_;
    char padA[2];
    volatile unsigned short unknown_c_;
    char unknown_e_[2];
    unsigned char initialized;
};

// USA: func_02074af4
extern "C" ARM void func_02074af4(struct Struct_02074af4* obj) {
    if (obj->initialized != 0) return;
    unsigned short* const reg = (unsigned short*)0x4000008;
    volatile short v0, v1, v2, v3;
    {
        unsigned short raw = *(volatile unsigned short*)&reg[0];
        v0 = raw;
        v0;
        obj->unknown_0_ = raw;
        v0;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[1];
        obj->unknown_4_ = raw;
        v1 = raw;
        v1;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[2];
        v2 = raw;
        v2;
        obj->unknown_8_ = raw;
        v2;
    }
    {
        unsigned short raw = *(volatile unsigned short*)&reg[3];
        obj->unknown_c_ = raw;
        v3 = raw;
        v3;
    }
    obj->initialized = 1;
}
