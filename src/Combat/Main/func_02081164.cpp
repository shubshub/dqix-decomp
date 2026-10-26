#include <globaldefs.h>

struct Struct_0207f0ac;

struct Struct_02081164_2 {
    char pad[0x15];
    unsigned char flags;
};

extern "C" struct Struct_02081164_2* func_0207f0ac(struct Struct_0207f0ac* list, int id);

struct Struct_02081164 {
    char pad[0xc];
};

// USA: func_02081164
extern "C" ARM void func_02081164(struct Struct_02081164* owner, int id, int enable) {
    struct Struct_02081164_2* e = func_0207f0ac((struct Struct_0207f0ac*)((char*)owner + 0xc), id);
    if (e == NULL) {
        return;
    }
    if (enable) {
        e->flags |= 0x2;
    } else {
        e->flags &= ~0x2;
    }
}
