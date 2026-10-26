#include <globaldefs.h>

struct Base02019508;
extern "C" struct Entry02019508* Zone3D_FindSceneElement(struct Base02019508* base, int key1, int key2);

struct Thing0201ba1c {
    unsigned char pad0[0x2];
    unsigned short f2;
    unsigned char pad4[0x20];
    short* f24;
    unsigned char pad28[0xc];
    unsigned short f34;
    unsigned short unknown_36_;
    unsigned char unknown_38_[0x1c];
    int unknown_54_;
};

// USA: func_0201ba1c
extern "C" ARM void func_0201ba1c(struct Base02019508* base, int key1, int key2) {
    struct Thing0201ba1c* p = (struct Thing0201ba1c*)Zone3D_FindSceneElement(base, key1, key2);
    if (p == NULL || p->unknown_54_ == 0) return;
    if (p->f24 == NULL) return;
    if (*p->f24 != 2) return;
    p->f34 = 0;
    p->unknown_36_ = 0;
    p->f2 |= 0x100;
}
