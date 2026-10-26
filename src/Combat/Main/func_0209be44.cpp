#include <globaldefs.h>

struct Struct_02073ec4_2;
struct Struct_0209ba70 { unsigned short a; short b; };
struct Struct_0209be44 {
    unsigned short key;
    unsigned short count;
    int unknown_4_;
    struct Struct_0209ba70 sub[6];
};
extern "C" struct Struct_0209be44* func_0209bd94(struct Struct_02073ec4_2*, int);

// USA: func_0209be44
extern "C" ARM void func_0209be44(struct Struct_02073ec4_2* table, int key, struct Struct_0209ba70* src) {
    struct Struct_0209be44* p = func_0209bd94(table, key);
    struct Struct_0209ba70* arr;
    struct Struct_0209ba70* e;
    int i;
    if (p == NULL) return;
    i = p->count;
    arr = p->sub;
    p->count = i + 1;
    e = &arr[i];
    e->a = src->a;
    e->b = src->b;
}
