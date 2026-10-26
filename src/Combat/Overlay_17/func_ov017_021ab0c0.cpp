#if defined(jpn)
enum { Enum_ov017_021ab0c0_54 = 0x2a };
#else
enum { Enum_ov017_021ab0c0_54 = 0x36 };
#endif

#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov017_021aa59c_5 {
    char pad0[0x18];
    void* unknown_18_;
    char pad1[0x44 - 0x1c];
    short* unknown_44_;
    char pad2[0x48 - 0x48];
    short unknown1_48_;
    char pad3[0x4e - 0x4a];
    short s4e;
};

extern "C" int func_02080dd4(void* obj, int p1, int arg2, int arg3, unsigned char* outFlag, unsigned char extra);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov017_021ab0c0
extern "C" ARM int func_ov017_021ab0c0(struct Struct_ov017_021aa59c_5* ctx) {
    unsigned char flag = 0;
    if (g_keyManager.TestKeysPressed(0x401)) {
        flag = 1;
    }
    if (g_touchInput.pressed_ != 0 && ctx->unknown_44_ != NULL) {
        void* obj = ctx->unknown_18_;
        int a, b;
        g_touchInput.GetTouchPoint(&a, &b);
        ctx->s4e = *ctx->unknown_44_;
        int result = func_02080dd4(obj, ctx->unknown1_48_, (short)a, (short)b, &flag, 1);
        if (result < 0) {
            return 0;
        }
        *ctx->unknown_44_ = (short)result;
        short cur = *ctx->unknown_44_;
        if (ctx->s4e != cur) {
            *(short*)((char*)obj + Enum_ov017_021ab0c0_54) = cur;
            func_020813ec(obj, ctx->unknown1_48_);
        }
    }
    return flag;
}
