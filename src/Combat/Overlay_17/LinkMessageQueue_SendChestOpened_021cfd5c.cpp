#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cfd5c {
    unsigned short valB;
    unsigned short unknown_2_;
    unsigned char valA;
};

struct Struct_ov017_021cfd5c_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021cfd5c sub;
    unsigned char pad2[7];
};

// Overlay 17, originally EnqueueEventTag164_021cfd5c (USA/EUR 0x021cfd5c, JPN 0x021d020c)
extern "C" ARM void LinkMessageQueue_SendChestOpened(unsigned char a, unsigned short b, unsigned short c) {
    Struct_ov017_021cfd5c_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0xa4;
    Struct_ov017_021cfd5c* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    s->unknown_2_ = c;
    func_0205e330(p, &buf, 0);
}
