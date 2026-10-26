#include <globaldefs.h>

struct Struct_02087574_2 {
    unsigned char pad[0x10];
    signed char id;
    unsigned char pad2[3];
};

struct Struct_02087574 {
    unsigned char pad[0xf2c];
    struct Struct_02087574_2 entries[3];
};

// USA: func_02087574
extern "C" ARM struct Struct_02087574_2* func_02087574(struct Struct_02087574* obj, int id) {
    int i;
    if (id >= 0) {
        for (i = 0; i < 3; i++) {
            if (id == obj->entries[i].id) {
                return &obj->entries[i];
            }
        }
    }
    return 0;
}
