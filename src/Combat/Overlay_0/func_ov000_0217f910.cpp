#include <globaldefs.h>

struct Struct_ov000_0217f910 {
    char pad0[0xc];
    short hp;
    char pad1[0x4c - 0xe];
    int combatantId;
#if defined(jpn)
    char pad2[0xc7 - 0x50];
#else
    char pad2[0x87 - 0x50];
#endif
    unsigned char active;
    char pad3[0x445 - 0x88];
    unsigned char unknown_445_;
    char pad4[0x448 - 0x446];
};

struct Struct_ov000_0217f910_2 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Struct_ov000_0217f910 unknown_958_[1];
};

// USA: func_ov000_0217f910
extern "C" ARM int func_ov000_0217f910(struct Struct_ov000_0217f910_2* battle) {
    struct Struct_ov000_0217f910* c;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        c = &battle->unknown_958_[battle->order[i]];
        int var3 = 0;
        int id = c->combatantId;
        if (id >= 0 && id <= 3) var3 = 1;
        if (var3 && c->active && c->hp != 0 && c->unknown_445_) {
            count++;
        }
    }
    return count;
}
