#include <globaldefs.h>

#if defined(jpn)
struct Struct_ov003_02166164 { char pad[0x228]; int flags; };
#else
struct Struct_ov003_02166164 { char pad[0x400]; int flags; };
#endif
struct Struct_ov003_02165c9c_5 { char pad[0x64]; Struct_ov003_02166164 sub; };

// USA: func_ov003_02166164
extern "C" ARM void func_ov003_02166164(Struct_ov003_02165c9c_5* obj, int set, int mask) {
    if (set) {
        obj->sub.flags |= mask;
    } else {
        obj->sub.flags &= ~mask;
    }
}
