#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_02159bb0_256 = 0xf8 };
#else
enum { Enum_ov006_02159bb0_256 = 0x100 };
#endif

struct Struct_ov006_02157a60 {
    char unk_0[Enum_ov006_02159bb0_256];
    char layout_[0x4c];
};

extern "C" short func_ov023_021e29d0(void* layout);

// USA: func_ov006_02159bb0
extern "C" ARM unsigned char func_ov006_02159bb0(Struct_ov006_02157a60* self) {
    int var0 = 0;
    int var1 = 0;
    int var2 = 0;
    int names = 0;
    short element = func_ov023_021e29d0(self->layout_);
    if (element >= 0) {
        if (element == 0x41)
            var0 = 1;
        var1 = element == 0x42 ? 1 : 0;
        var2 = element == 0x13 ? 1 : 0;
        names = element == 0x26 ? 1 : 0;
    } else {
        if (g_keyManager.TestKeysPressed(4))
            var2 = 1;
        if (g_keyManager.TestKeysPressed(0x300))
            names = 1;
    }
    if (var2)
        return 1;
    if (var0)
        return 2;
    if (var1)
        return 3;
    if (names)
        return 4;
    return 0;
}
