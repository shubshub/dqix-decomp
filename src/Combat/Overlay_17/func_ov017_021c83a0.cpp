#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c83a0 {
    unsigned char pad0[5];
    unsigned char field5;
    unsigned char pad1[2];
    unsigned short field8;
};

struct Struct_ov017_021c83a0_2 {
    unsigned short field4;
    unsigned char field6;
    unsigned char pad;
    unsigned int field8;
};

struct Struct_ov017_021c83a0_3 {
    unsigned char tag;
    unsigned char pad[3];
    Struct_ov017_021c83a0_2 tail;
    unsigned char pad2[8];
};

// USA: func_ov017_021c83a0
extern "C" ARM void func_ov017_021c83a0(void) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    GameResources* ov = GetGameResources();
    void* h = *(void**)((char*)ov + 0x3000 + regionalOffset0);
    Struct_ov017_021c83a0* r = (Struct_ov017_021c83a0*)func_ov017_021b8478(h);
    void* work = func_ov017_021b8470(h);
    void* p = LinkMessageQueue_GetInstance();

    Struct_ov017_021c83a0_3 buf;
    buf.tag = 0x75;
    Struct_ov017_021c83a0_2* t = &buf.tail;
    t->field4 = r->field8;
    t->field8 = *(unsigned int*)((char*)work + 0x8000 + 0xe20);
    t->field6 = r->field5;
    func_0205e330(p, &buf, 0);
}
