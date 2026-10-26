#include <globaldefs.h>

struct Struct_02094d88 { unsigned char pad[0xc]; void* link; };
struct Struct_02109418 { unsigned char pad[0xa0]; struct Struct_02094d88* slot; };

// USA: func_020958fc
extern "C" ARM void func_020958fc(struct Struct_02109418* owner, struct Struct_02094d88* node) {
    struct Struct_02094d88* old = owner->slot;
    owner->slot = node;
    if (old != NULL) {
        node->link = old;
    }
}
