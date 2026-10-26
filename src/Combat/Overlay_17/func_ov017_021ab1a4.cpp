#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0207fdcc_2;

struct Struct_ov017_021aa59c_6 {
    char pad[0x18];
    struct Struct_0207fdcc_2* unknown_18_;
};

extern "C" int func_02080d54(struct Struct_0207fdcc_2* obj, int key, int px, int arg3);

// USA: func_ov017_021ab1a4
extern "C" ARM int func_ov017_021ab1a4(struct Struct_ov017_021aa59c_6* ctx) {
    int flag = 0;
    if (g_keyManager.TestKeysPressed(0x2)) {
        flag = 1;
    }
    if (g_touchInput.pressed_ != 0) {
        int a, b;
        g_touchInput.GetTouchPoint(&a, &b);
        if (!func_02080d54(ctx->unknown_18_, 0, (short)a, (short)b)) {
            if (!func_02080d54(ctx->unknown_18_, 1, (short)a, (short)b)) {
                flag = 1;
            }
        }
    }
    return flag;
}
