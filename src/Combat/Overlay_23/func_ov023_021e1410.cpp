#include <globaldefs.h>

struct Struct_021e12cc {
    int a;
    int b;
    short c;
    unsigned short d;
    unsigned short e;
    unsigned char bit0 : 1;
    unsigned char unknown_e_1_ : 1;
    unsigned char rest : 6;
    unsigned char f;
};

struct Struct_ov023_021e1410 {
    char pad0[4];
    struct Struct_021e12cc* entries;
    short count;
    short capacity;
};

// USA: func_ov023_021e1410
extern "C" ARM void func_ov023_021e1410(Struct_ov023_021e1410* list, struct Struct_021e12cc* src) {
    if (list->capacity <= list->count) return;
    struct Struct_021e12cc* dst = &list->entries[list->count];
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    *(unsigned char*)((char*)dst + 0xe) = *(unsigned char*)((char*)src + 0xe);
    dst->f = src->f;
    list->count = list->count + 1;
}
