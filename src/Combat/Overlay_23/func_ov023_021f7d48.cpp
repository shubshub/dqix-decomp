#include <globaldefs.h>
#include "Graphics/Vector.h"

#if defined(jpn)
enum { Enum_ov023_021f7d48_80 = 0x4c, Enum_ov023_021f7d48_78 = 0x4e };
#else
enum { Enum_ov023_021f7d48_80 = 0x50, Enum_ov023_021f7d48_82 = 0x52 };
#endif

struct Struct_ov023_021f7d48 {
    unsigned char unknown0[Enum_ov023_021f7d48_80];
    short x;
    short y;
};

// USA: func_ov023_021f7d48
extern "C" ARM Vector3fix func_ov023_021f7d48(void* element) {
    const Struct_ov023_021f7d48* position = (const Struct_ov023_021f7d48*)element;
    Vector3fix result;
    result.x = position->x * 4096;
    result.y = position->y * 4096;
    result.z = 0;
    return result;
}
