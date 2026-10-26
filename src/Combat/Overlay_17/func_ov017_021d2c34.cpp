#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d2c34 {
    unsigned char v0;
    unsigned char v1;
    unsigned char v2;
};

struct Struct_ov017_021d2c34_2 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021d2c34 sub;
    unsigned char pad2[13];
};

// USA: func_ov017_021d2c34
extern "C" ARM void func_ov017_021d2c34(unsigned char a, unsigned char b, unsigned char c) {
    Struct_ov017_021d2c34_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    Struct_ov017_021d2c34* s = &buf.sub;
    buf.tag = 0x24;
    s->v0 = a;
    s->v1 = b;
    s->v2 = c;
    func_0205e330(p, &buf, 0);
}
