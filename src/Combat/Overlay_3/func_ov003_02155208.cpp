#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_02155208_486 = 0x1e2 };
#else
enum { Enum_ov003_02155208_486 = 0x1e6 };
#endif

struct Struct_020e28dc;
struct Struct_0207fdcc_2;

extern "C" int func_020e28dc(struct Struct_020e28dc* o);
extern "C" int func_020e2984(struct Struct_020e28dc* window);
extern "C" int func_02080d54(struct Struct_0207fdcc_2* obj, int key, int px, int arg3);

struct Struct_ov003_02155208 {
    char pad0[0x18];
    struct Struct_0207fdcc_2* field18;
    struct Struct_020e28dc* unknown_1c_;
    char pad1[Enum_ov003_02155208_486 - 0x20];
    short unknown_1e6_;
};

// USA: func_ov003_02155208
extern "C" ARM int func_ov003_02155208(struct Struct_ov003_02155208* self) {
    int flag = 0;
    if (g_keyManager.TestKeysPressed(2)) flag = 1;

    if (self->unknown_1c_ != NULL && func_020e28dc(self->unknown_1c_)) {
        if (func_020e2984(self->unknown_1c_)) {
            flag = 1;
        }
    } else if (g_touchInput.pressed_ != 0) {
        int a, b;
        g_touchInput.GetTouchPoint(&a, &b);
        if (!func_02080d54(self->field18, self->unknown_1e6_, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}
