#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205d81c {
    char unknown_0_[0xb0];
    unsigned char selected;
};

extern "C" int func_0205d97c(Struct_0205d81c* elements);

struct Struct_ov012_02186a7c {
#if defined(jpn)
    char unknown_0_[0x90];
#else
    char unknown1_0_[0xac];
#endif
    Struct_0205d81c elements;
};

extern "C" ARM int func_ov023_021e6e20(Struct_ov012_02186a7c* selection) {
    int var0 = g_keyManager.TestKeysPressed(2);
    int var1 = func_0205d97c(&selection->elements) == 2;
    return (var0 | var1) != 0;
}
