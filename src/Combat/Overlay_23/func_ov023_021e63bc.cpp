#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Input/Input.h"

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown0[0xac];
    short x, y;
};
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c* s, int key);

#if defined(jpn)
enum { Enum_ov023_021e63bc_4977 = 0x1341, WindowOffset = 0x90 };
#else
enum { Enum_ov023_021e63bc_4977 = 0x1371, WindowOffset = 0xac };
#endif
namespace {
struct Struct_ov023_021e63bc {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknown_168_[Enum_ov023_021e63bc_4977 - WindowOffset - sizeof(CreationWindow)];
    unsigned char key;
};
}

// USA: func_ov023_021e63bc
// JPN: func_ov023_021e6630
extern "C" ARM int func_ov023_021e63bc(unsigned char* obj) {
    Struct_ov023_021e63bc* state = ((Struct_ov023_021e63bc*)(obj));
    int key = state->key;
    Elem_0205d81c* elem = func_0205d81c(((Struct_0205d81c*)(&state->window)), key);
    int var3 = g_touchInput.prevX_;
    int x = elem->x;
    int var5 = elem->y;
    x = (short)(x << 3) + 0xa;
    var5 = (short)(var5 << 3) + 0x10;
    int var6 = g_touchInput.prevY_;
    if (x <= var3 && var3 <= x + 0x10 && var5 <= var6 && var6 <= var5 + 8)
        return 1;
    if (x <= var3 && var3 <= x + 0x10 && var5 + 0xc <= var6 && var6 <= var5 + 0x14)
        return -1;
    return 0;
}
