#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

struct Struct_0205d5d0_2 {
    char pad[0xc4];
    unsigned char fieldC4;
};

struct StructA0205d5d0 {
    char pad0[0x98];
    int field98;
    Struct_0205d5d0_2* unknown_9c_;
    char pad2[0x13];
    unsigned char unknown_b3_;
};

extern "C" int WindowPane_IsOpen(unsigned char* obj);
extern "C" void func_0205d904(unsigned char* obj);
#if defined(jpn)
extern "C" void func_0204cb20(void* elem, int c, int d);
#else
extern "C" void func_0204cb20(void* elem, int c, int d, unsigned char e);
#endif

// Main, originally TryApplyElemFields0205d5d0 (USA 0x0205d5d0, EUR 0x0205d5e0, JPN 0x0205e8e8)
extern "C" ARM int Window_SetPaneText(struct StructA0205d5d0* a, int b, int c, int d
#if !defined(jpn)
, unsigned char e
#endif
) {
    Struct_0205d5d0_2* elem;
    unsigned char i;

    if (c == 0) return 1;
    if (a->field98 == 0) return 1;
    if (a->unknown_9c_ == 0) return 1;

    for (i = 0; i < a->unknown_b3_; i++) {
        elem = (Struct_0205d5d0_2*)((char*)a->unknown_9c_ + i * 0xe0);
        if (!WindowPane_IsOpen((unsigned char*)elem)) continue;
        if (b != elem->fieldC4) continue;
#if defined(jpn)
        func_0204cb20(elem, c, d);
#else
        func_0204cb20(elem, c, d, e);
#endif
        func_0205d904((unsigned char*)a);
        return 0;
    }
    return 1;
}
