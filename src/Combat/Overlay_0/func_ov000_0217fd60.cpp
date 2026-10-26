#include <globaldefs.h>

struct Struct_ov000_0217fd60_2 {
    char pad0[0x24];
    unsigned char flags;
    char pad1[0x4c - 0x25];
    int id;
#if defined(jpn)
    char pad2[0x488 - 0x50];
#else
    char pad2[0x448 - 0x50];
#endif
};

struct Struct_ov000_0217fd60 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Struct_ov000_0217fd60_2 unknown_958_[4];
};

// USA: func_ov000_0217fd60
extern "C" ARM bool func_ov000_0217fd60(struct Struct_ov000_0217fd60* obj, int id) {
    bool result = false;
    if (id < 0) {
        int i;
        for (i = 0; i < 4; i++) {
            struct Struct_ov000_0217fd60_2* e = &obj->unknown_958_[obj->order[i]];
            if (e->id >= 0) {
                result |= (e->flags & 1) != 0;
            }
        }
    } else {
        int i;
        for (i = 0; i < 4; i++) {
            struct Struct_ov000_0217fd60_2* e = &obj->unknown_958_[obj->order[i]];
            if (id == e->id) {
                result = (e->flags & 1) != 0;
                break;
            }
        }
    }
    return result;
}
