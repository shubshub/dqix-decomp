#include <globaldefs.h>

struct Elem0216dee4 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x22 - 0x1c];
    unsigned char f22;
    char pad2[0x25 - 0x23];
    unsigned char f25;
    unsigned char unknown_26_;
};

struct Struct_ov003_0216dee4 {
    char pad0[0x40];
    struct Elem0216dee4* arr;
};

extern "C" void SpriteContext_DrawSprite(void*, struct Elem0216dee4*);

// USA: func_ov003_0216dee4
extern "C" ARM void func_ov003_0216dee4(struct Struct_ov003_0216dee4* obj, int idx, int v14, int v18, int arg4, int arg5, int arg6) {
    struct Elem0216dee4* e = (struct Elem0216dee4*)((char*)obj->arr + idx * 0x28);
    if (e == 0) return;
    e->f14 = v14 << 12;
    e->f18 = v18 << 12;
    if (arg4 >= 0) e->f22 = (unsigned char)arg4;
    if (arg5 >= 0) e->f25 = (unsigned char)arg5;
    if (arg6 >= 0) e->unknown_26_ = (unsigned char)arg6;
    SpriteContext_DrawSprite(obj, e);
}
