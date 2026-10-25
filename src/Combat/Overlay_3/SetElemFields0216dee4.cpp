#include <globaldefs.h>

struct Elem0216dee4 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x22 - 0x1c];
    unsigned char f22;
    char pad2[0x25 - 0x23];
    unsigned char f25;
    unsigned char f26;
};

struct Obj0216dee4 {
    char pad0[0x40];
    struct Elem0216dee4* arr;
};

extern "C" void SpriteContext_DrawSprite(void*, struct Elem0216dee4*);

// USA: func_ov003_0216dee4
ARM void SetElemFields0216dee4(struct Obj0216dee4* obj, int idx, int v14, int v18, int v22, int v25, int v26) {
    struct Elem0216dee4* e = (struct Elem0216dee4*)((char*)obj->arr + idx * 0x28);
    if (e == 0) return;
    e->f14 = v14 << 12;
    e->f18 = v18 << 12;
    if (v22 >= 0) e->f22 = (unsigned char)v22;
    if (v25 >= 0) e->f25 = (unsigned char)v25;
    if (v26 >= 0) e->f26 = (unsigned char)v26;
    SpriteContext_DrawSprite(obj, e);
}
