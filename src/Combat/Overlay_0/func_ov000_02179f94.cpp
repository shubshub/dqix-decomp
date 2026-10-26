#include <globaldefs.h>

#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xAA];
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char pad1[0xC2 - 0xB0];
    short unknown_c2_;
    unsigned char fieldC4;
    char pad2[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* unknown_9c_;
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char fieldB4;
};

struct Struct_ov000_02179f94 {
    char pad0[0x188];
    struct Struct_0205d81c elems;
};

extern "C" int MessageSystem_GetInstance();
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_0217a19c(struct Struct_ov000_02179f94* obj, void* entry);
extern "C" void func_ov000_0217c638(struct Struct_ov000_02179f94* obj, int a, int b);
extern "C" void func_ov000_0217a2dc(struct Struct_ov000_02179f94* obj, void* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif

static inline short inline_ov000_02179f94(const struct Elem_0205d81c* p) { return p->unknown_aa_; }
static inline short inline_ov000_02179f94_2(const struct Elem_0205d81c* p) { return p->unknown_ac_; }
static inline short inline_ov000_02179f94_3(const struct Elem_0205d81c* p) { return p->unknown_ae_; }

// USA: func_ov000_02179f94
extern "C" ARM void func_ov000_02179f94(struct Struct_ov000_02179f94* obj, void* entry, int a, int b) {
    func_ov000_0217a19c(obj, entry);
    func_ov000_0217c638(obj, a, b);
    struct Struct_0205d81c* s = &obj->elems;
    s->unknown_a0_ = 0x16;
    s->unknown_a2_ = 6;
    s->unknown_a4_ = 5;
#if defined(jpn)
    s->unknown_a6_ = 6;
#else
    s->unknown_a6_ = 5;
#endif
    s->unknown_a8_ = 0xc;
#if defined(jpn)
    s->unknown_aa_ = 0xa;
#else
    s->unknown_aa_ = 8;
#endif
    s->unknown_ac_ = 0xa;
    s->unknown_ae_ = 0xe;
    s->unknown_b1_ = 0x17;
#if defined(jpn)
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x28);
    memset(buf, 0, 0x800);
#else
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x5c);
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217a2dc(obj, entry, buf);
#if defined(jpn)
    Window_OpenPane(s, buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(s, buf, 0, 1, 0, 1, 0, 0);
#endif
    struct Elem_0205d81c* e = func_0205d81c(s, 0x18);
    if (e == 0) {
        return;
    }
    e->unknown_c2_ = 0;
    const struct Elem_0205d81c* var3 = func_0205d81c(s, 0x17);
    if (var3 == 0) {
        return;
    }
    short top = inline_ov000_02179f94_2(var3);
    short bottom = inline_ov000_02179f94_3(var3) + inline_ov000_02179f94(var3);
    e->unknown_ac_ = top;
    e->unknown_ae_ = bottom;
}
