#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_020ad61c {
    char pad0[0x44];
    Vector3i vec44;
    char pad1[0x168 - 0x44 - 12];
    int unknown_168_;
    char pad2[0x178 - 0x168 - 4];
    int unknown_178_;
};

// USA: func_020ae398
extern "C" ARM void func_020ae398(struct Struct_020ad61c* obj) {
    Vector3i local;
    local = obj->vec44;
    local.y -= 0x199;
    obj->vec44 = local;
    obj->unknown_168_ -= 0x199;
    obj->unknown_178_ -= 0x199;
}
