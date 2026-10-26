#include <globaldefs.h>

struct Struct_ov026_021dae60 {
    char unk[0x4c];
    int id;
#if defined(jpn)
    char rest[0x488 - 0x4c - 4];
#else
    char rest[0x448 - 0x4c - 4];
#endif
};

struct Container_021dae60 {
    char unk[0x958];
    struct Struct_ov026_021dae60 slots[4];
};

// USA: func_ov026_021dae60
extern "C" ARM void* func_ov026_021dae60(struct Container_021dae60* c, int id) {
    int var0 = (id >= 0 && id <= 3);
    if (!var0) {
        goto fail;
    }
    for (int i = 0; i < 4; i++) {
        if (c->slots[i].id == id) {
            return &c->slots[i];
        }
    }
fail:
    return NULL;
}
