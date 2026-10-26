#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" void func_ov000_02162b90(void* self, int unused1, int c, int arg3, int arg4, signed char arg5, signed char p2);

struct Struct_ov017_021c6b04 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Struct_ov017_021c6b04_2 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    signed char fieldA;
    signed char fieldB;
};

// USA: func_ov017_021c6b04
extern "C" ARM void func_ov017_021c6b04(int unused0, Struct_ov017_021c6b04_2* evt, int arg2, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    void* table = *(void**)(base + 0x3000 + regionalOffset0);
    Struct_ov017_021c6b04* a = (Struct_ov017_021c6b04*)func_ov017_021b8478(table);
    if (!a) return;
    void* b = func_ov017_021b8468(table);
    if (!b) return;
    void* work = func_ov017_021b8470(table);
    if (!work) return;
    if (a->field8 != evt->field4) return;
    func_ov000_02162b90(b, *(short*)&evt->field4, evt->field6, evt->field8, evt->field9, evt->fieldA, evt->fieldB);
}
