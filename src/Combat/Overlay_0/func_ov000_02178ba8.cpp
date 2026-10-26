#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xc2];
    short unknown_c2_;
};

struct Struct_0205d81c {
    char pad0[0x54];
    int field54;
    char pad1[0xa0 - 0x58];
    short unknown_a0_;
    short unknown_a2_;
    short x;
    short y;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char pad2;
    unsigned char unknown_b1_;
};

struct GlobalField1c {
    char pad0[REGION_OFFSET_0];
    void* buffer;
};

struct Struct_ov000_02178ba8_2 {
    char pad0[0x44];
    int x;
    int y;
};

struct Struct_ov000_02178ba8_3 {
    char pad0[0x188];
    Struct_0205d81c panel;
};

extern "C" GlobalField1c* MessageSystem_GetInstance();
extern "C" int GridCursor_GetCount(void* obj);
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c* s, int key);
extern "C" void func_ov000_02178d28(Struct_ov000_02178ba8_3* obj, Struct_ov000_02178ba8_2* entry);
extern "C" void func_ov000_0217ab8c(Struct_ov000_02178ba8_2* entry, int a, int b);
extern "C" void func_ov000_02178f28(Struct_ov000_02178ba8_3* obj, Struct_ov000_02178ba8_2* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(Struct_0205d81c* s, void* buf, int a, int b, int c, int d, int e, int f);
#endif
extern "C" void func_ov000_02176210(Struct_0205d81c* s, int a, int b);

// USA: func_ov000_02178ba8
extern "C" ARM void func_ov000_02178ba8(Struct_ov000_02178ba8_3* obj, Struct_ov000_02178ba8_2* entry, int arg2, int arg3) {
    func_ov000_02178d28(obj, entry);
    int x = entry->x;
    int y = entry->y;
    func_ov000_0217ab8c(entry, arg2, arg3);
    Struct_0205d81c* panel = &obj->panel;
#if defined(jpn)
    panel->unknown_a0_ = 0xd;
#else
    panel->unknown_a0_ = 0x10;
#endif
    panel->unknown_a2_ = 9;
#if defined(jpn)
    panel->x = (x >> 3) + 9;
#else
    panel->x = (x >> 3) + 0x10;
#endif
    panel->y = y >> 3;
    panel->unknown_a8_ = 0xc;
    panel->unknown_aa_ = 8;
    panel->unknown_ac_ = 0xa;
    panel->unknown_ae_ = 0xc;
    panel->unknown_b1_ = 0xf;
    int flag = 0;
    if (GridCursor_GetCount(&panel->field54) > 4) {
        flag = 1;
    }
    void* buf = MessageSystem_GetInstance()->buffer;
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_02178f28(obj, entry, buf);
#if defined(jpn)
    Window_OpenPane(panel, buf, 0, 0, flag, 1, 0);
#else
    Window_OpenPane(panel, buf, 0, 0, flag, 1, 0, 0);
#endif
    Elem_0205d81c* elem = func_0205d81c(panel, 0x22);
    if (elem != NULL) {
        elem->unknown_c2_ = 0;
    }
    func_ov000_02176210(&obj->panel, 0xf, 0x22);
}
