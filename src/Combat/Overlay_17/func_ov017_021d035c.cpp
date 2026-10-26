#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d035c {
    unsigned char valA;
    unsigned char valB;
    unsigned char unknown_2_;
};

struct Struct_ov017_021d035c_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021d035c sub;
    unsigned char pad2[13];
};

// USA: func_ov017_021d035c
extern "C" ARM void func_ov017_021d035c(unsigned char a, unsigned char b, unsigned char c) {
    Struct_ov017_021d035c_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x96;
    Struct_ov017_021d035c* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    s->unknown_2_ = c;
    func_0205e330(p, &buf, 0);
}
