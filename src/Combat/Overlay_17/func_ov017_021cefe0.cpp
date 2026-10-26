#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cefe0 {
    unsigned short valA;
    unsigned char valB;
    unsigned char unknown_3_;
};

struct Struct_ov017_021cefe0_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021cefe0 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021cefe0
extern "C" ARM void func_ov017_021cefe0(unsigned short a, unsigned char b, unsigned char c) {
    Struct_ov017_021cefe0_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x6c;
    Struct_ov017_021cefe0* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    s->unknown_3_ = c;
    func_0205e330(p, &buf, 0);
}
