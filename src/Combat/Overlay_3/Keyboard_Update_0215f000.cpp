#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov003_0215f000_2 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[0xc - 4];
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    char unknown_f_;
    short unknown_10_;
    char unknown_12_[0x14 - 0x12];
};

struct Struct_ov003_0215f000 {
    struct Struct_ov003_0215f000_2* unknown_0_;
    char unknown_4_[2];
    short unknown_6_;
};

struct Struct_ov003_0215e8f4 {
    struct Struct_ov003_0215f000_2* unknown_0_;
    struct Struct_ov003_0215f000* unknown_4_;
    char unknown_8_[0x18 - 8];
    int unknown_18_;
    unsigned short unknown_1c_;
    unsigned char unknown_1e_;
    char unknown_1f_[0x22 - 0x1f];
    unsigned char unknown_22_;
    unsigned char unknown_23_;
    unsigned char unknown_24_;
};

struct Struct_ov003_0215e930;

extern "C" struct Struct_ov003_0215e930* func_ov003_0215e8f4(struct Struct_ov003_0215e8f4* arg0);
extern "C" int func_ov003_0215e930(struct Struct_ov003_0215e930* arg0, short arg1, signed char* arg2, signed char* arg3);
extern "C" void func_ov003_0215e9ec(struct Struct_ov003_0215e8f4* arg0, int arg1, int arg2);
extern "C" int func_ov003_0215ef54(struct Struct_ov003_0215e8f4* arg0);
extern "C" int func_ov003_0215eeb8(struct Struct_ov003_0215e8f4* arg0);
extern "C" void func_ov003_0215ec68(int arg0, short* arg1, short* arg2);

// USA: func_ov003_0215f000
extern "C" ARM int func_ov003_0215f000(struct Struct_ov003_0215e8f4* arg0, int arg1) {
    struct Struct_ov003_0215f000_2* var0 = arg0->unknown_0_;
    int var1;
    short var2;
    struct Struct_ov003_0215f000_2* var3;
    unsigned char var4;
    int var5;

    if (arg0->unknown_0_ == 0) {
        var5 = 0;
        arg0->unknown_18_ = 0;
        arg0->unknown_1c_ = 0;
    } else {
        if (g_keyManager.TestKeysPressed(0x40)) {
            func_ov003_0215e9ec(arg0, 0, -1);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x40;
        } else if (g_keyManager.TestKeysPressed(0x80)) {
            func_ov003_0215e9ec(arg0, 0, 1);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x80;
        } else if (g_keyManager.TestKeysPressed(0x20)) {
            func_ov003_0215e9ec(arg0, -1, 0);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x20;
        } else if (g_keyManager.TestKeysPressed(0x10)) {
            func_ov003_0215e9ec(arg0, 1, 0);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x10;
        }

        if (arg0->unknown_24_) {
            unsigned short var6 = arg0->unknown_1c_;
            if (var6 != 0 && g_keyManager.TestKeysHeld(0xf0)) {
                int var7 = arg0->unknown_18_ - arg1;
                if (var7 <= 0) {
                    var7 = 10;
                    switch (var6) {
                    case 0x40:
                        func_ov003_0215e9ec(arg0, 0, -1);
                        break;
                    case 0x80:
                        func_ov003_0215e9ec(arg0, 0, 1);
                        break;
                    case 0x20:
                        func_ov003_0215e9ec(arg0, -1, 0);
                        break;
                    case 0x10:
                        func_ov003_0215e9ec(arg0, 1, 0);
                        break;
                    }
                    if (arg0->unknown_24_) {
                        signed char var8;
                        signed char var9;
                        signed char var10;
                        signed char var11;
                        struct Struct_ov003_0215e930* var12 = func_ov003_0215e8f4(arg0);
                        struct Struct_ov003_0215f000_2* var13 = arg0->unknown_0_;
                        if (func_ov003_0215e930(var12, var0->unknown_10_, &var11, &var10) == 0
                            && func_ov003_0215e930(var12, var13->unknown_10_, &var9, &var8) == 0) {
                            switch (var6) {
                            case 0x40:
                                if (var10 < var8) arg0->unknown_0_ = var0;
                                break;
                            case 0x80:
                                if (var10 > var8) arg0->unknown_0_ = var0;
                                break;
                            case 0x20:
                                if (var11 < var9) arg0->unknown_0_ = var0;
                                break;
                            case 0x10:
                                if (var11 > var9) arg0->unknown_0_ = var0;
                                break;
                            }
                        }
                    }
                }
                arg0->unknown_18_ = var7;
            } else {
                arg0->unknown_18_ = 0;
                arg0->unknown_1c_ = 0;
            }
        }
        if (var0 == arg0->unknown_0_) {
            var5 = 0;
        } else {
            var5 = 1;
        }
    }

    if (var5 == 0) {
        unsigned char var14 = arg0->unknown_22_;
        unsigned char var15 = arg0->unknown_23_;
        if (g_keyManager.TestKeysPressed(1)
            || (var14 && g_keyManager.TestKeysPressed(0x200))) {
            var5 = func_ov003_0215ef54(arg0);
        } else if (var15 && g_keyManager.TestKeysPressed(2)) {
            var5 = func_ov003_0215eeb8(arg0);
        } else {
            var5 = 0;
        }

        if (var5 == 0) {
            var4 = arg0->unknown_1e_;
            if (g_touchInput.pressed_) {
                int var16;
                int var17;
                g_touchInput.GetTouchPoint(&var17, &var16);
                struct Struct_ov003_0215f000* var18 = arg0->unknown_4_;
                var3 = var18->unknown_0_;
                var2 = var18->unknown_6_;
                for (var1 = 0; var1 < var2; var1++, var3++) {
                    if (var3->unknown_c_ & var4) {
                        short var19;
                        short var20;
                        func_ov003_0215ec68(var3->unknown_e_, &var20, &var19);
                        if (var3->unknown_2_ <= var16 && var16 < var3->unknown_2_ + var19 && var3->unknown_0_ <= var17 && var17 < var3->unknown_0_ + var20) {
                            goto found;
                        }
                    }
                }
            }
            var3 = 0;
        found:
            if (var3 != 0) {
                arg0->unknown_0_ = var3;
                var5 = func_ov003_0215ef54(arg0);
            }
        }
    }
    return var5;
}
