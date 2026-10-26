#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d1810 {
    unsigned short v0;
    unsigned short v2;
    unsigned char v4;
};

struct Struct_ov017_021d1810_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021d1810 sub;
    unsigned char pad2[10];
};

// USA: func_ov017_021d1810
extern "C" ARM void func_ov017_021d1810(int a, int b, signed char c) {
    Struct_ov017_021d1810_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0xad;
    Struct_ov017_021d1810* s = &buf.sub;
    s->v0 = a;
    s->v2 = b;
    s->v4 = c;
    func_0205e330(p, &buf, 0);
}
