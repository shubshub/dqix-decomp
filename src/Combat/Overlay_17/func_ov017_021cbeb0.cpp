#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cbeb0 {
    unsigned char valA;
    unsigned char pad;
    unsigned short valB;
};

struct Struct_ov017_021cbeb0_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021cbeb0 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021cbeb0
extern "C" ARM void func_ov017_021cbeb0(unsigned char a, unsigned short b) {
    Struct_ov017_021cbeb0_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x7f;
    Struct_ov017_021cbeb0* s = &buf.sub;
    s->valA = a;
    s->valB = b;
    func_0205e330(p, &buf, 0);
}
