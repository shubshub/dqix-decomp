#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d27a0 {
    unsigned char v0;
    unsigned char v1;
    unsigned char v2;
};

struct Struct_ov017_021d27a0_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021d27a0 sub;
    unsigned char pad2[13];
};

// USA: func_ov017_021d27a0
extern "C" ARM void func_ov017_021d27a0(int a, int b, int c) {
    Struct_ov017_021d27a0_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x22;
    Struct_ov017_021d27a0* s = &buf.sub;
    s->v0 = a;
    s->v1 = b;
    s->v2 = c;
    func_0205e330(p, &buf, 0);
}
