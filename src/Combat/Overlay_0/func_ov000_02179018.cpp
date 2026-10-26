#include <globaldefs.h>

#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xC2];
    short unknown_c2_;
    unsigned char fieldC4;
    char pad1[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char pad0[0x54];
    char field54[0x98 - 0x54];
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

struct Struct_ov000_02179018 {
    char pad0[0x188];
    struct Struct_0205d81c elems;
};

struct Struct_ov000_02179018_2 {
    char pad0[0x44];
    int x;
    int y;
};

extern "C" int MessageSystem_GetInstance();
extern "C" int GridCursor_GetCount(void* obj);
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_02179194(struct Struct_ov000_02179018* obj, struct Struct_ov000_02179018_2* entry);
extern "C" void func_ov000_0217ab8c(struct Struct_ov000_02179018_2* entry, int a, int b);
extern "C" void func_ov000_0217936c(struct Struct_ov000_02179018* obj, struct Struct_ov000_02179018_2* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(struct Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif
extern "C" void func_ov000_02176210(struct Struct_0205d81c* s, int a, int key);

// USA: func_ov000_02179018
extern "C" ARM void func_ov000_02179018(struct Struct_ov000_02179018* obj, struct Struct_ov000_02179018_2* entry, int a, int b) {
    func_ov000_02179194(obj, entry);
    int x = entry->x;
    int y = entry->y;
    func_ov000_0217ab8c(entry, a, b);
    struct Struct_0205d81c* s = &obj->elems;
#if defined(jpn)
    s->unknown_a0_ = 0xe;
#else
    s->unknown_a0_ = 0x10;
#endif
    s->unknown_a2_ = 9;
#if defined(jpn)
    s->unknown_a4_ = (x >> 3) + 9;
#else
    s->unknown_a4_ = (x >> 3) + 0x10;
#endif
    s->unknown_a6_ = y >> 3;
    s->unknown_a8_ = 0xc;
    s->unknown_aa_ = 8;
    s->unknown_ac_ = 0xa;
    s->unknown_ae_ = 0xc;
    s->unknown_b1_ = 0x10;
    int many = 0;
    if (GridCursor_GetCount(s->field54) > 4) {
        many = 1;
    }
#if defined(jpn)
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x28);
    memset(buf, 0, 0x800);
#else
    void* buf = *(void**)(MessageSystem_GetInstance() + 0x5c);
    memset(buf, 0, 0x960);
#endif
    func_ov000_0217936c(obj, entry, buf);
#if defined(jpn)
    Window_OpenPane(s, buf, 0, 0, many, 1, 0);
#else
    Window_OpenPane(s, buf, 0, 0, many, 1, 0, 0);
#endif
    struct Elem_0205d81c* e = func_0205d81c(s, 0x23);
    if (e != 0) {
        e->unknown_c2_ = 0;
    }
    func_ov000_02176210(&obj->elems, 0x10, 0x23);
}
