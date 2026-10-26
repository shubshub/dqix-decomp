#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ceae4 {
    unsigned char valA;
    unsigned char valB;
    unsigned char pad;
    unsigned char unknown_3_;
};

struct Struct_ov017_021ceae4_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021ceae4 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021ceae4
extern "C" ARM void func_ov017_021ceae4(unsigned char a, unsigned char b, unsigned char c) {
    Struct_ov017_021ceae4_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    Struct_ov017_021ceae4* s = &buf.sub;
    buf.tag = 0x33;
    s->valA = a;
    s->valB = b;
    s->unknown_3_ = c;
    func_0205e330(p, &buf, 0);
}
