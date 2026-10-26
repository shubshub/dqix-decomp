#include <globaldefs.h>

struct Struct_0201c470 { unsigned char v[31]; };
struct Struct_0201c3a4_2 { struct Struct_0201c470 name; unsigned char flag; };
struct Struct_0201c470_2 {
    struct Struct_0201c3a4_2* base;   // 0x0
    int cap;                     // 0x4
    int count;                   // 0x8
};

// USA: func_0201c470
extern "C" ARM void func_0201c470(struct Struct_0201c470_2* obj, struct Struct_0201c3a4_2* src) {
    struct Struct_0201c3a4_2* base = obj->base;
    if (base != NULL) {
        struct Struct_0201c3a4_2* dst;
        if (obj->count >= obj->cap) return;
        dst = &base[obj->count];
        dst->name = src->name;
        dst->flag = src->flag;
        obj->count++;
        return;
    }
    obj->count++;
}
