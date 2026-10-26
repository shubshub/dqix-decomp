#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0215e27c_1000 = 0x400 };
#else
enum { Enum_ov003_0215e27c_1000 = 0x3e8 };
#endif
struct Struct_ov003_0215c924 { char unk[Enum_ov003_0215e27c_1000]; int counter; };

// USA: func_ov003_0215e27c
#pragma optimize_for_size off
extern "C" ARM int func_ov003_0215e27c(struct Struct_ov003_0215c924* obj, int amount) {
    if (obj->counter > amount) {
        obj->counter -= amount;
    } else {
        obj->counter = 0;
        return 0;
    }
    return 1;
}
