#include <globaldefs.h>

struct Struct_ov011_021849bc { char pad[0x114]; int unknown_114_; };

// USA: func_ov011_021849bc
extern "C" ARM int func_ov011_021849bc(struct Struct_ov011_021849bc* obj, int mask) {
    return obj->unknown_114_ & mask;
}
