#include <globaldefs.h>

struct Struct_ov011_02184a84 {
    char pad[0xbc];
    unsigned short flagA;
    unsigned short unknown_be_;
};

struct Struct_ov011_02184694_2 {
    char pad0[0x1b4];
    int (**table)(void*);
};

// USA: func_ov011_02184a84
extern "C" ARM void func_ov011_02184a84(struct Struct_ov011_02184694_2* obj) {
    struct Struct_ov011_02184a84* sub = (struct Struct_ov011_02184a84*)((char*)obj + 0x100);
    unsigned short idx = sub->flagA;
    if (idx != 0) {
        int r = obj->table[idx](obj);
        if (r == 0) {
            ((struct Struct_ov011_02184a84*)((char*)obj + 0x100))->flagA = 0;
        }
        return;
    }
    idx = sub->unknown_be_;
    if (idx == 0) return;
    obj->table[idx](obj);
}
