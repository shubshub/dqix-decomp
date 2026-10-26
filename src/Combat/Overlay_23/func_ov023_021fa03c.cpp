#include <globaldefs.h>

struct Struct_ov023_021fa03c_2 { char pad0[2]; unsigned char flag; char pad1[0x25]; };
struct Struct_ov023_021fa03c {
    char pad0[0x20];
    unsigned short count;
    char pad1[2];
    struct Struct_ov023_021fa03c_2* arr;
};

// USA: func_ov023_021fa03c
extern "C" ARM struct Struct_ov023_021fa03c_2* func_ov023_021fa03c(struct Struct_ov023_021fa03c* obj) {
    int i;
    for (i = 0; i < obj->count; i++) {
        struct Struct_ov023_021fa03c_2* e = &obj->arr[i];
        if (e->flag == 0) return e;
    }
    return NULL;
}
