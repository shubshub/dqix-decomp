#include <globaldefs.h>

struct Struct_020de714_3 {
    unsigned short a;
    unsigned short idx : 15;
    unsigned short flag : 1;
};

// USA: func_020de7a4
extern "C" ARM int func_020de7a4(struct Struct_020de714_3* obj) {
    int idx = obj->idx;
    int a = obj->a;
    int base = obj->flag ? 0x58 : 0;
    return base + idx * 32 + a * 32;
}
