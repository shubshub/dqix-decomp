#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

struct Elem0205d5d0 {
    char pad[0xc4];
    unsigned char fieldC4;
};

struct StructA0205d5d0 {
    char pad0[0x98];
    int field98;
    Elem0205d5d0* field9c;
    char pad2[0x13];
    unsigned char countB3;
};

int WindowPane_IsOpen(unsigned char* obj);
void ApplyElemFields0205d904(unsigned char* obj);
#if defined(jpn)
extern "C" void func_0204cb20(void* elem, int c, int d);
#else
extern "C" void func_0204cb20(void* elem, int c, int d, unsigned char e);
#endif

// Main, originally TryApplyElemFields0205d5d0 (USA 0x0205d5d0, EUR 0x0205d5e0, JPN 0x0205e8e8)
ARM int Window_SetPaneText(struct StructA0205d5d0* a, int b, int c, int d
#if !defined(jpn)
, unsigned char e
#endif
) {
    Elem0205d5d0* elem;
    unsigned char i;

    if (c == 0) return 1;
    if (a->field98 == 0) return 1;
    if (a->field9c == 0) return 1;

    for (i = 0; i < a->countB3; i++) {
        elem = (Elem0205d5d0*)((char*)a->field9c + i * 0xe0);
        if (!WindowPane_IsOpen((unsigned char*)elem)) continue;
        if (b != elem->fieldC4) continue;
#if defined(jpn)
        func_0204cb20(elem, c, d);
#else
        func_0204cb20(elem, c, d, e);
#endif
        ApplyElemFields0205d904((unsigned char*)a);
        return 0;
    }
    return 1;
}
