#include <globaldefs.h>

struct Struct_ov015_02190d08 {
    char pad[0x1a4];
    int state;
};

// USA: func_ov015_02190d08
extern "C" ARM int func_ov015_02190d08(struct Struct_ov015_02190d08* obj) {
    int val = obj->state;
    if (val == 0x11) return 1;
    if (val == 0x14) return 1;
    if (val == 0x17) return 1;
    if (val == 0x18) return 1;
    if (val == 0x19) return 1;
    if (val == 0x1a) return 1;
    if (val == 0x1b) return 1;
    if (val == 0x1c) return 1;
    return val == 0x16;
}
