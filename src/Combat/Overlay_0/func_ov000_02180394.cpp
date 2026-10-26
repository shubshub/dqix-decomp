#include <globaldefs.h>

extern "C" void func_ov000_0217f480(char* self);

struct Struct_ov000_02180394_2 {
    char pad0[0x4c];
    int combatantId;
#if defined(jpn)
    char pad1[0xc7 - 0x50];
#else
    char pad1[0x87 - 0x50];
#endif
    unsigned char active;
    char pad2[0x448 - 0x88];
};

struct Struct_ov000_02180394 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Struct_ov000_02180394_2 unknown_958_[1];
};

// USA: func_ov000_02180394
extern "C" ARM void func_ov000_02180394(struct Struct_ov000_02180394* battle) {
    for (int i = 0; i < 4; i++) {
        struct Struct_ov000_02180394_2* c = &battle->unknown_958_[battle->order[i]];
        int var2 = 0;
        int id = c->combatantId;
        if (id >= 0 && id <= 3) var2 = 1;
        if (var2 && c->active) {
            func_ov000_0217f480((char*)c);
        }
    }
}
