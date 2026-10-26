#include <globaldefs.h>

struct Struct_ov016_0218f330 {
    char pad[0x88];
    int entries[2];
    int index;
};

// USA: func_ov016_0218f330
extern "C" ARM int func_ov016_0218f330(void* obj) {
    Struct_ov016_0218f330* self = (Struct_ov016_0218f330*)obj;
    return self->entries[self->index];
}
