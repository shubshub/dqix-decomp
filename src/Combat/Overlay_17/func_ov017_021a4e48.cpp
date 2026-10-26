#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov017_021a4e48_17236 = 0x4134 };
#else
enum { Enum_ov017_021a4e48_17236 = 0x4354 };
#endif

struct Struct_ov017_021a4e48 {
    unsigned char unknown0[Enum_ov017_021a4e48_17236];
    signed char counter;
};

// USA: func_ov017_021a4e48
extern "C" ARM void func_ov017_021a4e48(unsigned char* obj) {
    Struct_ov017_021a4e48* owner = (Struct_ov017_021a4e48*)obj;
    owner->counter--;
    if (owner->counter < 0) {
        owner->counter = 0;
    }
}
