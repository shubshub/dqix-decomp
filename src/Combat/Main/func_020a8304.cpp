#include <globaldefs.h>

struct Struct_020a8304_3 { unsigned char byte0; unsigned char unknown_1_; char pad[0x2c - 2]; };
struct Struct_020a8304 {
    struct Struct_020a8304_3* arr;
    char pad4[2];
    unsigned short count;
};

extern "C" struct Struct_020a8304_3* func_020a8458(struct Struct_020a8304* obj);

struct Struct_020a8304_2 {
    struct Struct_020a8304_3* arr;
    char pad4[2];
    unsigned short count;
    struct Struct_020a8304_3* f8;
    unsigned short fc;
};

// USA: func_020a8304
extern "C" ARM void func_020a8304(struct Struct_020a8304_2* obj) {
    int i;
    for (i = 0; i < obj->count; i++) {
        struct Struct_020a8304_3* e = (struct Struct_020a8304_3*)((char*)obj->arr + i * 0x2c);
        e->unknown_1_ = 0xff;
    }
    obj->f8 = 0;
    obj->fc = 0;
    struct Struct_020a8304_3* cur = func_020a8458((struct Struct_020a8304*)obj);
    if (cur == 0) {
        return;
    }
    obj->f8 = cur;
    cur->unknown_1_ = 0;
    obj->fc = obj->fc + 1;
    unsigned char flag = 1;
    while (cur != 0) {
        struct Struct_020a8304_3* next = func_020a8458((struct Struct_020a8304*)obj);
        *(int*)((char*)cur + 0x28) = (int)next;
        if (next != 0) {
            next->unknown_1_ = flag;
            flag = (unsigned char)(flag + 1);
            obj->fc = obj->fc + 1;
        }
        cur = next;
    }
}
