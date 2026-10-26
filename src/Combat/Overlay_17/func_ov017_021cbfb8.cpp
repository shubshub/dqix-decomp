#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cbfb8 {
    unsigned short valA;
    unsigned char valB;
};

struct Struct_ov017_021cbfb8_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021cbfb8 sub;
    unsigned char pad2[9];
};

// USA: func_ov017_021cbfb8
extern "C" ARM void func_ov017_021cbfb8(unsigned short a, unsigned char b) {
    Struct_ov017_021cbfb8_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x81;
    Struct_ov017_021cbfb8* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    func_0205e330(p, &buf, 0);
}
