#include <globaldefs.h>

struct Struct_02040bfc {
    char unk[0x8c];
    int value;
};

struct Struct_02040bfc_2 {
    char unk[0xc8];
    int value;
};

struct Struct_02040bfc_3 {
#if defined(jpn)
    char unk[0x2e0];
#else
    char unk[0x2ec];
#endif
    int value;
};

struct Struct_0203d028_22 {
    char unk[0x14];
    struct Struct_02040bfc* a;
    struct Struct_02040bfc_2* b;
    struct Struct_02040bfc_3* c;
};

// USA: func_02040bfc
extern "C" ARM void func_02040bfc(struct Struct_0203d028_22* obj, int value) {
    if (obj->a != 0) {
        obj->a->value = value;
        return;
    }
    if (obj->b != 0) {
        obj->b->value = value;
        return;
    }
    if (obj->c != 0) {
        obj->c->value = value;
    }
}
