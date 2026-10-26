#include <globaldefs.h>

struct Struct_020951d8 { unsigned char pad[0x28]; void* link; };
struct Struct_020951d8_2 { unsigned char pad[0xa4]; struct Struct_020951d8* slot; };

// USA: func_02095910
extern "C" ARM void func_02095910(struct Struct_020951d8_2* owner, struct Struct_020951d8* node) {
    struct Struct_020951d8* old = owner->slot;
    owner->slot = node;
    if (old != NULL) {
        node->link = old;
    }
}
