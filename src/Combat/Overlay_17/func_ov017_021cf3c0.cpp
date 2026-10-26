#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cf3c0 {
    int a1;
    int a2;
    int a3;
};

struct Struct_ov017_021cf3c0_2 {
    unsigned char tag;
    unsigned char pad0[3];
    int a1;
    int a2;
    int a3;
    short a4;
    unsigned char bit0 : 1;
    unsigned char unknown_12_1_ : 1;
    unsigned char rest : 6;
    signed char a7;
};

// USA: func_ov017_021cf3c0
extern "C" ARM void func_ov017_021cf3c0(struct Struct_ov017_021cf3c0 v, short a4, unsigned char arg2, unsigned char e6, signed char arg4) {
    void* p = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021cf3c0_2 buf;
    buf.tag = 0x38;
    buf.a1 = v.a1;
    buf.a2 = v.a2;
    buf.a3 = v.a3;
    buf.a4 = a4;
    buf.bit0 = arg2;
    buf.unknown_12_1_ = e6;
    buf.a7 = arg4;
    func_0205e330(p, &buf, 0);
}
