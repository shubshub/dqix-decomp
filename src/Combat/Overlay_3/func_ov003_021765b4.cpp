#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_021765b4_54 = 0x2a };
enum { Enum_ov003_021765b4_2204 = 0x818 };
enum { Enum_ov003_021765b4_4088 = 0xf74 };
enum { Enum_ov003_021765b4_2208 = 0x81c };
enum { Enum_ov003_021765b4_4094 = 0xf7a };
enum { Enum_ov003_021765b4_4092 = 0xf78 };
#else
enum { Enum_ov003_021765b4_54 = 0x36 };
enum { Enum_ov003_021765b4_2204 = 0x89c };
enum { Enum_ov003_021765b4_4088 = 0xff8 };
enum { Enum_ov003_021765b4_2208 = 0x8a0 };
enum { Enum_ov003_021765b4_4094 = 0xffe };
enum { Enum_ov003_021765b4_4092 = 0xffc };
#endif

struct Struct_020e28dc;

struct Struct_ov000_0217ab8c {
    char unk_0[Enum_ov003_021765b4_54];
    short cursor_;
};

extern "C" {
void func_020813ec(Struct_ov000_0217ab8c*, int);
}

extern "C" int func_020e28dc(Struct_020e28dc*);
extern "C" int func_020e2918(signed char*);
extern "C" int func_02080dd4(void*, int, int, int, unsigned char*, unsigned char);

struct Struct_ov003_021765b4 {
    Struct_020e28dc* choice_;
    char pad0[Enum_ov003_021765b4_2204 - 0x4];
    Struct_ov000_0217ab8c* menu_;
    char pad1[Enum_ov003_021765b4_4088 - Enum_ov003_021765b4_2208];
    short* cursor_;
    char pad2[Enum_ov003_021765b4_4094 - Enum_ov003_021765b4_4092];
    short unknown_ffe_;
    short unknown_1000_;
};

// USA: func_ov003_021765b4
extern "C" ARM unsigned char func_ov003_021765b4(Struct_ov003_021765b4* self)
{
    unsigned char var0 = 0;
    if (g_keyManager.TestKeysPressed(0x401))
        var0 = 1;
    if (self->choice_ != 0 && func_020e28dc(self->choice_))
    {
        int choice = func_020e2918((signed char*)self->choice_);
        if (choice >= 0)
        {
            var0 = 1;
            *self->cursor_ = choice + 2;
        }
    }
    else if (g_touchInput.pressed_ && self->cursor_ != 0)
    {
        int x;
        int y;
        Struct_ov000_0217ab8c* menu = self->menu_;
        g_touchInput.GetTouchPoint(&x, &y);
        self->unknown_1000_ = *self->cursor_;
        int item = func_02080dd4(menu, self->unknown_ffe_, (short)x, (short)y, &var0, 1);
        if (item < 0)
            return 0;
        *self->cursor_ = item;
        short cursor = *self->cursor_;
        if (self->unknown_1000_ != cursor)
        {
            menu->cursor_ = cursor;
            func_020813ec(menu, self->unknown_ffe_);
        }
    }
    return var0;
}
