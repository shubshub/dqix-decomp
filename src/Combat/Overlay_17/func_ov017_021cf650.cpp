#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cf650 {
    int valB;
    int unknown_4_;
    unsigned short valA;
};

struct Struct_ov017_021cf650_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021cf650 sub;
    unsigned char pad2[2];
};

// USA: func_ov017_021cf650
extern "C" ARM void func_ov017_021cf650(unsigned short a, int b, int c) {
    Struct_ov017_021cf650_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x6d;
    Struct_ov017_021cf650* s = &buf.sub;
    s->valB = b;
    s->unknown_4_ = c;
    s->valA = a;
    func_0205e330(p, &buf, 0);
}
