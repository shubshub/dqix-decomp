#include <globaldefs.h>

struct Struct_0203e5d8_2 {
    char pad[0x50];
    int unknown_50_;
};

struct Struct_0203e5d8_3 {
    char pad[0x14];
    struct Struct_0203e5d8_2* field14;
};

struct Struct_0203e5d8 {
    char pad[0xc];
    struct Struct_0203e5d8_3* arr[0x20];
};

// USA: func_0203e5d8
extern "C" ARM void func_0203e5d8(struct Struct_0203e5d8* root, int flag) {
    struct Struct_0203e5d8_3** p = root->arr;
    int i;
    for (i = 0; i < 0x20; i++, p++) {
        struct Struct_0203e5d8_3* a = *p;
        if (a != 0) {
            struct Struct_0203e5d8_2* b = a->field14;
            if (b != 0) {
                if (flag) {
                    b->unknown_50_ &= ~0x10;
                } else {
                    b->unknown_50_ |= 0x10;
                }
            }
        }
    }
}
