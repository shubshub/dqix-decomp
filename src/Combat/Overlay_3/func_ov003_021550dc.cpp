#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_021550dc_54 = 0x2a };
enum { Enum_ov003_021550dc_486 = 0x1e2 };
#else
enum { Enum_ov003_021550dc_54 = 0x36 };
enum { Enum_ov003_021550dc_486 = 0x1e6 };
#endif

struct Struct_020e28dc;

struct Struct_ov000_0217ab8c {
    char unk_0[Enum_ov003_021550dc_54];
    short cursor_;
};

extern "C" int func_020e28dc(struct Struct_020e28dc* o);
extern "C" int func_020e2918(signed char* param);
extern "C" int func_02080dd4(void* obj, int p1, int arg2, int arg3, unsigned char* outFlag, unsigned char extra);
extern "C" void func_020813ec(void* obj, int key);

struct Struct_ov003_021550dc {
    char unk_0[0x8];
    short* cursor_;
    char unk_c[0x18 - 0xc];
    Struct_ov000_0217ab8c* menu_;
    Struct_020e28dc* choice_;
    char unk_20[Enum_ov003_021550dc_486 - 0x20];
    short unknown_1e6_;
    short unknown_1e8_;
};

// USA: func_ov003_021550dc
extern "C" ARM unsigned char func_ov003_021550dc(Struct_ov003_021550dc* self) {
    unsigned char var0 = 0;
    if (g_keyManager.TestKeysPressed(0x401)) {
        var0 = 1;
    }
    if (self->choice_ != NULL && func_020e28dc(self->choice_)) {
        int choice = func_020e2918((signed char*)self->choice_);
        if (choice >= 0) {
            var0 = 1;
            *self->cursor_ = choice + 6;
        }
    } else if (g_touchInput.pressed_ != 0 && self->cursor_ != NULL) {
        Struct_ov000_0217ab8c* menu = self->menu_;
        int x, y;
        g_touchInput.GetTouchPoint(&x, &y);
        self->unknown_1e8_ = *self->cursor_;
        int item = func_02080dd4(menu, self->unknown_1e6_, (short)x, (short)y, &var0, 1);
        if (item < 0) {
            return 0;
        }
        *self->cursor_ = item;
        short cursor = *self->cursor_;
        if (self->unknown_1e8_ != cursor) {
            menu->cursor_ = cursor;
            func_020813ec(menu, self->unknown_1e6_);
        }
    }
    return var0;
}
