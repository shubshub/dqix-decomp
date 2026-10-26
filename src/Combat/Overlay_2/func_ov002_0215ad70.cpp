#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown0[0xac];
    short x, y;
};
struct ShortArrays0204c654;

struct Struct_ov002_0216c98a {
    short v[4];
};

extern "C" struct Elem_0205d81c *func_0205d81c(struct Struct_0205d81c *s, int key);
extern "C" void func_ov002_02154bcc(int a, int b, void *obj, int idx, unsigned char arg4, unsigned char arg5);
extern "C" void func_0204c654(ShortArrays0204c654 *arr, int idx, short a, short b, short c, short d);

#if defined(jpn)
enum { WindowOffset = 0xe20, Enum_ov002_0215ad70_6760 = 0x19c0, SelectionOffset = 0x1ace,
       Enum_ov002_0215ad70_28 = 0x1d, Enum_ov002_0215ad70_29 = 0x1e, Enum_ov002_0215ad70_22 = 0x18, Enum_ov002_0215ad70_17 = 0x13, Enum_ov002_0215ad70_20 = 0x16 };
#define data_ov002_0216c98a data_ov002_0216cfe6
#else
enum { WindowOffset = 0xec8, Enum_ov002_0215ad70_6760 = 0x1a68, SelectionOffset = 0x1c06,
       Enum_ov002_0215ad70_28 = 0x1c, Enum_ov002_0215ad70_29 = 0x1d, Enum_ov002_0215ad70_22 = 0x16, Enum_ov002_0215ad70_17 = 0x11, Enum_ov002_0215ad70_20 = 0x14 };
#endif
extern Struct_ov002_0216c98a data_ov002_0216c98a;

namespace {
struct Struct_ov002_0215ad70 {
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknown_f84_[Enum_ov002_0215ad70_6760 - WindowOffset - sizeof(CreationWindow)];
    void* renderer;
    unsigned char unknown_1a6c_[SelectionOffset - Enum_ov002_0215ad70_6760 - 4];
    short selection;
};
}

// USA: func_ov002_0215ad70
// JPN: func_ov002_0215c0d8
extern "C" ARM void func_ov002_0215ad70(unsigned char *obj) {
    Struct_ov002_0215ad70* state = ((Struct_ov002_0215ad70*)(obj));
    struct Elem_0205d81c *elem =
        func_0205d81c(((Struct_0205d81c*)(&state->window)), Enum_ov002_0215ad70_28);
    if (elem == 0) {
        return;
    }
    int var2             = static_cast<short>(elem->x * 8);
    int var3             = static_cast<short>(elem->y * 8);
    Struct_ov002_0216c98a var4 = data_ov002_0216c98a;
    unsigned char k       = 0;
    unsigned short tile   = Enum_ov002_0215ad70_22;
    for (unsigned char row = 0; row < 4; row++) {
        for (unsigned char col = 0; col < 4; col++) {
            short idx;
            int var10;
            short dx;
            dx       = var4.v[col];
            short dy = var4.v[row];
            short px = (short) (dx + var2);
            var10       = (short) (dy + var3);
            func_ov002_02154bcc(px, var10, state->renderer, tile++, (unsigned char) (k * 4 + 0xc),
                                              0xff);
            idx = (short) (col + row * 4);
            if (state->selection == idx) {
                func_ov002_02154bcc(px, var10, state->renderer, Enum_ov002_0215ad70_17, 8, 0xff);
            }
            func_0204c654(((ShortArrays0204c654*)(elem)), idx, dx, dy, 0x18, 0x18);
            k++;
        }
    }
    elem = func_0205d81c(((Struct_0205d81c*)(&state->window)), Enum_ov002_0215ad70_29);
    if (elem == 0) {
        return;
    }
    int x2 = elem->x;
    int y2 = elem->y;
    x2     = (short) (x2 * 8) + 0x10;
    y2     = (short) (y2 * 8) + 0x18;
    func_ov002_02154bcc(x2, y2, state->renderer, Enum_ov002_0215ad70_20, 0x54, 8);
}

#if defined(jpn)
#undef data_ov002_0216c98a
#endif
