#include <globaldefs.h>

extern "C" void Background_CopyScreenRect(void*, void*, int, int, int, int, int, int, int, int);

struct Obj0204b8d0 {
    char pad0[0x10];
    int field10;
    void* field14;
    char pad18[5];
    unsigned char field1d;
};

// Main, originally DispatchEntry0204b8d0 (USA 0x0204b8d0, EUR 0x0204b8e0, JPN 0x0204c6f0)
ARM void Background_DrawScreen(struct Obj0204b8d0* obj, unsigned int a1, int a2, int a3,
                              short a4, short a5, short a6, short a7, unsigned short a8) {
    if (obj->field1d <= a1) return;
    int v = obj->field10;
    if (v == 0) return;
    v += a1 << 4;
    void* p = obj->field14;
    if (p == NULL) return;
    Background_CopyScreenRect(obj, p, v, a2, a3, a4, a5, a6, a7, a8);
}
