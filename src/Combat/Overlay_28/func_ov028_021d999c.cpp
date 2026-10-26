#include <globaldefs.h>

struct Struct_ov028_021d97d8 {
    short a;
    short b;
    int c;
    int d;
};

struct Struct_ov028_021d97d8_2 {
    char pad0[4];
    Struct_ov028_021d97d8* items;
    unsigned short count;
    unsigned short capacity;
};

// USA: func_ov028_021d999c
extern "C" ARM void func_ov028_021d999c(Struct_ov028_021d97d8_2* obj, Struct_ov028_021d97d8* item) {
    if (obj->capacity <= obj->count) {
        return;
    }
    if (item == NULL) {
        return;
    }
    Struct_ov028_021d97d8* dst = &obj->items[obj->count];
    dst->a = item->a;
    dst->b = item->b;
    dst->c = item->c;
    dst->d = item->d;
    obj->count = obj->count + 1;
}
