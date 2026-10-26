#include <globaldefs.h>

struct Struct_020bc084 {
    int field0;
};

static inline bool inline_020bc084(struct Struct_020bc084* const* slot) {
    return *slot != NULL;
}

// USA: func_020bc084
extern "C" ARM void func_020bc084(struct Struct_020bc084** slot) {
    if (!inline_020bc084(slot)) {
        return;
    }
    (*slot)->field0 = 0;
    *slot = NULL;
}
