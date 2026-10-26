#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"

#if defined(jpn)
enum { Enum_020409e0_724 = 0x2c8 };
#else
enum { Enum_020409e0_724 = 0x2d4 };
#endif
extern "C" int func_0203cdf8(struct Struct_0203cdf8*);

// USA: func_020409e0
extern "C" ARM int func_020409e0(Struct_0203dce4* obj) {
    if (obj->child14) {
        return func_0203cdf8((struct Struct_0203cdf8*)(obj->child14));
    }
    if (obj->unknown_18_) {
        return *(int*)((char*)obj->unknown_18_ + 0xb0);
    }
    if (obj->child1c) {
        return *(int*)((char*)obj->child1c + Enum_020409e0_724);
    }
    return 0;
}
