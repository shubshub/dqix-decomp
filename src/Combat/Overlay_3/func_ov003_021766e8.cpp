#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_021766e8_2204 = 0x818 };
enum { Enum_ov003_021766e8_4094 = 0xf7a };
enum { Enum_ov003_021766e8_2208 = 0x81c };
#else
enum { Enum_ov003_021766e8_2204 = 0x89c };
enum { Enum_ov003_021766e8_4094 = 0xffe };
enum { Enum_ov003_021766e8_2208 = 0x8a0 };
#endif

struct Struct_020e28dc;
struct Struct_0207fdcc_2;

extern "C" int func_020e28dc(struct Struct_020e28dc* o);
extern "C" int func_020e2984(struct Struct_020e28dc* window);
extern "C" int func_02080d54(struct Struct_0207fdcc_2* obj, int key, int px, int arg3);

struct Struct_ov003_021766e8 {
    struct Struct_020e28dc* ptr0;
    char pad0[Enum_ov003_021766e8_2204 - 0x4];
    struct Struct_0207fdcc_2* unknown_89c_;
    char pad1[Enum_ov003_021766e8_4094 - Enum_ov003_021766e8_2208];
    short unknown_ffe_;
};

// USA: func_ov003_021766e8
extern "C" ARM int func_ov003_021766e8(struct Struct_ov003_021766e8* self) {
    int flag = 0;
    if (g_keyManager.TestKeysPressed(2)) flag = 1;

    if (self->ptr0 != NULL && func_020e28dc(self->ptr0)) {
        if (func_020e2984(self->ptr0)) {
            flag = 1;
        }
    } else if (g_touchInput.pressed_ != 0) {
        int a, b;
        g_touchInput.GetTouchPoint(&a, &b);
        if (!func_02080d54(self->unknown_89c_, self->unknown_ffe_, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}
