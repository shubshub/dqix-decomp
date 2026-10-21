#include "Input/Input.h"

#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Struct_0205bacc;
struct Struct_02108760;
extern "C" void func_0205bef8(Struct_0205bef8*);
extern "C" void func_0205ba68(Struct_0205ba68*, int, int, int);
extern "C" void func_0205bacc(Struct_0205bacc*, int);
extern "C" int func_0205bafc(void*);
extern "C" int func_0205bb84(Struct_0205bb84*);
extern "C" void func_0205eaa0(Struct_02108760*, int, int);
extern "C" int func_020e0434(Struct_0201099c_3*, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" int func_ov009_0218a8b4(Struct_ov009_021842a0*, int, int);
extern "C" int func_ov009_0218aab0(Struct_ov009_021842a0*, unsigned char);
extern "C" void func_ov009_0218ad0c(void*);
extern "C" void func_ov009_0218b200(CharacterCreationUI*, int);
extern "C" void func_ov009_0218b850(CharacterCreationUI*);
extern "C" void func_0205bb04(CreationNavigation*, int);
extern "C" int func_0205bf58(CreationNavigation*, unsigned int);
extern "C" void func_ov009_02188c2c(CharacterCreationUI*);
extern "C" void func_ov009_02188e70(CharacterCreationUI*, int);
extern "C" void func_ov009_02188944(CharacterCreationUI*, int);
extern "C" int menuSlotToStyleIndex(CharacterCreationUI*, int, int);

struct Struct_ov009_02187b34 {
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_, unknown_18_, unknown_1a_;
};
struct Struct_ov005_0215840c_2 { char unknown_0_[0x488]; Struct_ov009_02187b34 unknown_488_; };
extern Struct_02108760 data_02108760;

#define RESET_NAVIGATION(columns, rows, total, selected) \
    Struct_ov009_02188c2c* navigation = &arg0->unknown_bec_; \
    func_0205bef8((Struct_0205bef8*)navigation); \
    func_0205ba68((Struct_0205ba68*)navigation, columns, rows, 1); \
    func_0205bacc((Struct_0205bacc*)navigation, total); \
    navigation->unknown_4_ = 1; \
    func_0205bb04(navigation, selected); \
    navigation->unknown_3d_ = 0

#define TAB_CURSOR(selected) \
    arg0->unknown_c4c_ = ((selected) << 4) + 0x78; \
    arg0->unknown_c4e_ = 8; \
    arg0->unknown_c50_ = 16; \
    arg0->unknown_c52_ = 16

static inline unsigned char inline_ov009_02188ee8(Struct_ov009_021842a0* arg0) { return arg0->unknown_daa_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_2(Struct_ov009_021842a0* arg0) { return arg0->unknown_da8_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_3(Struct_ov009_021842a0* arg0) { return arg0->unknown_dae_[arg0->unknown_da3_]; }

extern "C" ARM int func_ov009_02188ee8(Struct_ov009_021842a0* arg0)
{
    arg0->unknown_d9c_ &= ~0x20;
    arg0->unknown_d9c_ &= ~0x40;
    int var0 = -1;
    int var1 = -1;
    int var2, var3;
    g_touchInput.GetTouchPoint(&var2, &var3);
    int var4 = 0;
    if (g_touchInput.pressed_) {
        var4 = 1;
        var1 = func_ov009_0218a8b4(arg0, var2, var3);
        arg0->unknown_d8c_ = var1;
        if ((unsigned int)(var1 + 3) <= 1) {
            if (var1 == -2) arg0->unknown_d9c_ |= 0x20;
            else if (var1 == -3) arg0->unknown_d9c_ |= 0x40;
            var0 = var1;
            func_0205eaa0(&data_02108760, 1, 0);
        } else if (var1 >= 101 && var1 <= 108) {
            var0 = var1;
            if (var1 - 100 <= arg0->unknown_da0_[arg0->unknown_da3_] && var1 - 100 != arg0->unknown_c58_)
                func_0205eaa0(&data_02108760, 1, 0);
        } else if (var1 >= 0) {
            func_0205bb04(&arg0->unknown_bec_, var1);
            if (arg0->unknown_c58_ == 8) {
                func_ov009_0218aab0(arg0, (unsigned char)var1);
                if (arg0->unknown_d9c_ & 0x200000) {
                    arg0->unknown_d9c_ &= ~0x200000;
                    var0 = -2;
                }
                arg0->unknown_d9c_ |= 0x100;
            }
            arg0->unknown_c54_ = arg0->unknown_c4c_;
            arg0->unknown_c56_ = arg0->unknown_c4e_;
        }
    } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) var4 = 1;
    else if (g_touchInput.released_) var4 = 1;
    if (!var4) {
        unsigned int var5 = GameState::GetInstance()->GetTickCount();
        if (!var5) var5 = 1;
        int var6 = arg0->unknown_bec_.unknown_1c_;
        if (func_0205bf58(&arg0->unknown_bec_, var5))
            var1 = func_0205bb84((Struct_0205bb84*)&arg0->unknown_bec_);
        if (arg0->unknown_c58_ == 8) {
            int var7 = arg0->unknown_bec_.unknown_c_;
            int var8 = func_0205bafc(&arg0->unknown_bec_);
            if (var7 == 1 && var8 == 8) {
                if (var1 >= arg0->unknown_da0_[arg0->unknown_da3_]) {
                    func_0205bb04(&arg0->unknown_bec_, arg0->unknown_da0_[arg0->unknown_da3_] - 1);
                    var1 = arg0->unknown_da0_[arg0->unknown_da3_] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    RESET_NAVIGATION(11, 6, 66, arg0->unknown1_d8c_);
                    func_0205bb04(&arg0->unknown_bec_, arg0->unknown_bec_.unknown_18_);
                    arg0->unknown1_d8c_ = func_0205bb84((Struct_0205bb84*)&arg0->unknown_bec_);
                    arg0->unknown_d9c_ |= 0x2000;
                    func_ov009_02188e70(arg0, func_0205bb84((Struct_0205bb84*)&arg0->unknown_bec_));
                    return -1;
                }
                if (var1 >= 0) { TAB_CURSOR(var1); }
                if (g_keyManager.TestKeysPressed(1)) {
                    var0 = func_0205bb84((Struct_0205bb84*)&arg0->unknown_bec_) + 101;
                    if (var0 - 100 <= arg0->unknown_da0_[arg0->unknown_da3_] && var0 - 100 != arg0->unknown_c58_)
                        func_0205eaa0(&data_02108760, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) {
                    if (func_02001aec(arg0->unknown_d74_[arg0->unknown_da3_], (const void*)func_020e0434(&arg0->unknown_e0_, 0x4272), 10) == 0)
                        var0 = -3;
                    else {
                        func_ov009_0218b200(arg0, 0);
                        arg0->unknown_d9c_ |= 0x8100;
                    }
                }
                return var0;
            } else if (var7 == 6) {
                if (g_keyManager.TestKeysPressed(0x40) && var6 == 0) {
                    RESET_NAVIGATION(8, 1, 8, arg0->unknown_c58_ - 1);
                    navigation->unknown_3c_ = 0;
                    TAB_CURSOR(arg0->unknown_c58_ - 1);
                    arg0->unknown_d9c_ |= 0x2000;
                    return -1;
                }
                if (g_keyManager.TestKeysPressed(8)) {
                    func_ov009_0218ad0c(arg0);
                } else if (g_keyManager.TestKeysPressed(4)) {
                    func_ov009_0218b850(arg0);
                    arg0->unknown_d9c_ |= 0x8100;
                } else if (g_keyManager.TestKeysPressed(1)) {
                    if (func_ov009_0218aab0(arg0, arg0->unknown1_d8c_) && arg0->unknown_d8a_[arg0->unknown_da3_] == 5) {
                        var1 = 65;
                        func_0205bb04(&arg0->unknown_bec_, var1);
                    }
                    if (!(arg0->unknown_d9c_ & 0x200000)) arg0->unknown_d9c_ |= 0xa100;
                    else {
                        func_ov009_0218ad0c(arg0);
                        arg0->unknown_d9c_ &= ~0x200000;
                    }
                } else if (g_keyManager.TestKeysPressed(2)) {
                    if (func_02001aec(arg0->unknown_d74_[arg0->unknown_da3_], (const void*)func_020e0434(&arg0->unknown_e0_, 0x4272), 10) == 0)
                        var0 = -3;
                    else {
                        func_ov009_0218b200(arg0, 0);
                        arg0->unknown_d9c_ |= 0x8100;
                    }
                }
            }
        } else if (arg0->unknown_c58_ != 8) {
            int var9 = arg0->unknown_bec_.unknown_c_;
            int var10 = func_0205bafc(&arg0->unknown_bec_);
            if (var9 == 1 && var10 == 8) {
                if (var1 >= arg0->unknown_da0_[arg0->unknown_da3_]) {
                    func_0205bb04(&arg0->unknown_bec_, arg0->unknown_da0_[arg0->unknown_da3_] - 1);
                    var1 = arg0->unknown_da0_[arg0->unknown_da3_] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    func_ov009_02188c2c(arg0);
                    arg0->unknown_d9c_ |= 0x2000;
                    func_ov009_02188e70(arg0, func_0205bb84((Struct_0205bb84*)&arg0->unknown_bec_));
                    return -1;
                }
                if (var1 >= 0) { TAB_CURSOR(var1); }
                if (g_keyManager.TestKeysPressed(1)) {
                    var0 = func_0205bb84((Struct_0205bb84*)&arg0->unknown_bec_) + 101;
                    if (var0 - 100 <= arg0->unknown_da0_[arg0->unknown_da3_] && var0 - 100 != arg0->unknown_c58_)
                        func_0205eaa0(&data_02108760, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) var0 = -3;
                return var0;
            }
            if (g_keyManager.TestKeysPressed(0x40) && var6 == 0) {
                RESET_NAVIGATION(8, 1, 8, arg0->unknown_c58_ - 1);
                navigation->unknown_3c_ = 0;
                TAB_CURSOR(arg0->unknown_c58_ - 1);
                arg0->unknown_d9c_ |= 0x2000;
                return -1;
            }
            if (g_keyManager.TestKeysPressed(1)) {
                var0 = -2;
                func_0205eaa0(&data_02108760, 1, 0);
            } else if (g_keyManager.TestKeysPressed(2)) var0 = -3;
        }
    }
    arg0->unknown_d9c_ &= ~0x10;
    if (var1 >= 0 && !(var1 >= 101 && var1 <= 108)) {
        switch (arg0->unknown_c58_) {
        case 1: if (arg0->unknown_da3_ != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown_da3_ = var1; break;
        case 2: if (arg0->unknown_da4_[arg0->unknown_da3_] != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown_da4_[arg0->unknown_da3_] = var1; break;
        case 3: if (arg0->unknown_dac_[arg0->unknown_da3_] != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown_dac_[arg0->unknown_da3_] = var1; break;
        case 4: if (arg0->unknown_dae_[arg0->unknown_da3_] != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown_dae_[arg0->unknown_da3_] = var1; break;
        case 5: if (arg0->unknown_da6_[arg0->unknown_da3_] != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown_da6_[arg0->unknown_da3_] = var1; break;
        case 6: if (arg0->unknown_daa_[arg0->unknown_da3_] != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown_daa_[arg0->unknown_da3_] = var1; break;
        case 7: if (arg0->unknown_da8_[arg0->unknown_da3_] != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown_da8_[arg0->unknown_da3_] = var1; break;
        case 8: if (arg0->unknown1_d8c_ != var1) arg0->unknown_d9c_ |= 0x10; arg0->unknown1_d8c_ = var1; break;
        }
    }
    if (self->flags & 0x10) {
        if (self->state != 8 || !touched) DispatchWithShortB4_0205eaa0(&data_02108760, 2, 0);
        func_ov009_02188944(self, choice);
        if (self->state == 1) {
            PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance;
            self->flags |= 0x60000;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->models[2] = menuSlotToStyleIndex(self, 5, self->faceStyle[self->sex]) + 0x233c;
            appearance->models[3] = menuSlotToStyleIndex(self, 3, self->hairStyle[self->sex]) + 0x2328;
        }
        if (!var4) func_ov009_02188e70(arg0, var1);
        arg0->unknown_d9c_ |= 0x6100;
    }
    return var0;
}
#undef RESET_NAVIGATION
#undef TAB_CURSOR

#else
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Struct_0205bacc;
struct Struct_02108760;
extern "C" void func_0205bef8(Struct_0205bef8*);
extern "C" void func_0205ba68(Struct_0205ba68*, int, int, int);
extern "C" void func_0205bacc(Struct_0205bacc*, int);
extern "C" int func_0205bafc(void*);
extern "C" int func_0205bb84(Struct_0205bb84*);
extern "C" void func_0205eaa0(Struct_02108760*, int, int);

struct Struct_02000c9c_93 {
    char unknown_0_[0x24];
    unsigned short unknown_24_;
    char unknown_26_[0x2e];
    unsigned char unknown_54_;
    unsigned char unknown_55_;
    char unknown_56_[9];
    unsigned char unknown_5f_;
};
struct Struct_ov009_02188ee8 {
    int unknown_0_, unknown_4_, unknown_8_, unknown_c_, unknown_10_, unknown_14_, unknown_18_, unknown_1c_;
    char unknown_20_[0x18];
    unsigned short unknown_38_;
    char unknown_3a_[2];
    unsigned char unknown_3c_, unknown_3d_;
    char unknown_3e_[2];
};
struct Struct_ov009_02188ee8_2 { void* unknown_0_; char unknown_4_[0x14]; int unknown_18_; unsigned short unknown_1c_; };
struct Struct_ov009_02187b34 {
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_, unknown_18_, unknown_1a_;
};
struct Struct_ov005_0215840c_2 { char unknown_0_[0x488]; Struct_ov009_02187b34 unknown_488_; };
struct Struct_ov009_02188ee8_3 { char unknown_0_[0x800]; Struct_ov009_02188ee8 unknown_800_; };
struct Struct_ov009_021842a0_2 {
    char unknown_0_[0xbc];
    void* unknown_bc_;
    Struct_ov009_02188ee8_2* unknown_c0_;
    char unknown_c4_[0x3ec - 0xc4];
    Struct_ov009_02188ee8_3 unknown_3ec_;
    char unknown_c2c_[0x20];
    short unknown_c4c_, unknown_c4e_, unknown_c50_, unknown_c52_, unknown_c54_, unknown_c56_;
    signed char unknown_c58_;
    char unknown_c59_[0xd88 - 0xc59];
    Struct_ov005_0215840c_2* unknown_d88_;
    int unknown_d8c_;
    char unknown_d90_[0xc];
    unsigned int unknown_d9c_;
    signed char unknown_da0_[3];
    unsigned char unknown_da3_;
    unsigned char unknown_da4_[2], unknown_da6_[2], unknown_da8_[2], unknown_daa_[2], unknown_dac_[2], unknown_dae_[2];
    char unknown_db0_[5];
    unsigned char unknown_db5_;
};
extern Obj0205eaa0 data_02108760;
extern "C" int func_ov009_02189854(CharacterCreation*, int, int);
extern "C" void func_0205bb04(Navigation*, int);
extern "C" int func_0205bf58(Navigation*, unsigned int);
extern "C" void func_ov009_02188c2c(CharacterCreation*);
extern "C" void func_ov009_02188e70(CharacterCreation*, int);
extern "C" void func_ov009_02188944(CharacterCreation*, int);
extern "C" int menuSlotToStyleIndex(CharacterCreation*, int, int);

#define RESET_NAVIGATION(columns, rows, total, selected) \
    Struct_ov009_02188ee8_3* controls = &arg0->unknown_3ec_; \
    func_0205bef8((Struct_0205bef8*)&controls->unknown_800_); \
    func_0205ba68((Struct_0205ba68*)&controls->unknown_800_, columns, rows, 1); \
    func_0205bacc((Struct_0205bacc*)&controls->unknown_800_, total); \
    controls->unknown_800_.unknown_4_ = 1; \
    func_0205bb04(&controls->unknown_800_, selected); \
    controls->unknown_800_.unknown_3d_ = 0

#define TAB_CURSOR(selected) \
    arg0->unknown_c4c_ = ((selected) << 4) + 0x78; \
    arg0->unknown_c4e_ = 8; \
    arg0->unknown_c50_ = 16; \
    arg0->unknown_c52_ = 16

static inline unsigned char inline_ov009_02188ee8(Struct_ov009_021842a0_2* arg0) { return arg0->unknown_daa_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_2(Struct_ov009_021842a0_2* arg0) { return arg0->unknown_da8_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_3(Struct_ov009_021842a0_2* arg0) { return arg0->unknown_dae_[arg0->unknown_da3_]; }

// USA: func_ov009_02188ee8
extern "C" ARM int func_ov009_02188ee8(Struct_ov009_021842a0_2* arg0) {
    arg0->unknown_d9c_ &= ~0x60;
    int var15 = -1;
    int var16 = -1;
    int var17, var18;
    g_touchInput.GetTouchPoint(&var17, &var18);
    int var19 = 0;
    if (g_touchInput.pressed_) {
        var19 = 1;
        var16 = func_ov009_02189854(arg0, var17, var18);
        arg0->unknown_d8c_ = var16;
        if ((unsigned int)(var16 + 3) <= 1) {
            if (var16 == -2) arg0->unknown_d9c_ |= 0x20;
            else if (var16 == -3) arg0->unknown_d9c_ |= 0x40;
            var15 = var16;
            func_0205eaa0(&data_02108760, 1, 0);
        } else if (var16 >= 101 && var16 <= 108) {
            var15 = var16;
            if (var16 - 100 <= arg0->unknown_da0_[arg0->unknown_da3_] && var16 - 100 != arg0->unknown_c58_)
                func_0205eaa0(&data_02108760, 1, 0);
        } else if (var16 >= 0) {
            func_0205bb04(&arg0->unknown_3ec_.unknown_800_, var16);
            if (arg0->unknown_c58_ == 8) {
                if (arg0->unknown_d9c_ & 0x200000) {
                    arg0->unknown_d9c_ &= ~0x200000;
                    var15 = -2;
                }
                arg0->unknown_d9c_ |= 0x100;
            }
            arg0->unknown_c54_ = arg0->unknown_c4c_;
            arg0->unknown_c56_ = arg0->unknown_c4e_;
        }
    } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) var19 = 1;
    else if (g_touchInput.released_) var19 = 1;
    if (!var19) {
        unsigned int var20 = GameState::GetInstance()->GetTickCount();
        if (!var20) var20 = 1;
        int var21 = arg0->unknown_3ec_.unknown_800_.unknown_1c_;
        if (func_0205bf58(&arg0->unknown_3ec_.unknown_800_, var20)) var16 = func_0205bb84((Struct_0205bb84*)&arg0->unknown_3ec_.unknown_800_);
        if (arg0->unknown_c58_ == 8) {
            int var22 = arg0->unknown_3ec_.unknown_800_.unknown_c_;
            int var23 = func_0205bafc(&arg0->unknown_3ec_.unknown_800_);
            if (var22 == 1 && var23 == 8) {
                if (var16 >= arg0->unknown_da0_[arg0->unknown_da3_]) {
                    func_0205bb04(&arg0->unknown_3ec_.unknown_800_, arg0->unknown_da0_[arg0->unknown_da3_] - 1);
                    var16 = arg0->unknown_da0_[arg0->unknown_da3_] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    RESET_NAVIGATION(11, 6, 66, 0);
                    arg0->unknown_d9c_ |= 0x2000;
                    if (arg0->unknown_bc_) arg0->unknown_c0_->unknown_0_ = arg0->unknown_bc_;
                    arg0->unknown_c0_->unknown_18_ = 0;
                    arg0->unknown_c0_->unknown_1c_ = 0;
                    return -1;
                }
                if (var16 >= 0) { TAB_CURSOR(var16); }
                if (g_keyManager.TestKeysPressed(1)) {
                    var15 = func_0205bb84((Struct_0205bb84*)&arg0->unknown_3ec_.unknown_800_) + 101;
                    if (var15 - 100 <= arg0->unknown_da0_[arg0->unknown_da3_] && var15 - 100 != arg0->unknown_c58_)
                        func_0205eaa0(&data_02108760, 1, 0);
                }
                return var15;
            }
            if (!arg0->unknown_db5_ && g_keyManager.TestKeysPressed(0x40)) {
                arg0->unknown_bc_ = arg0->unknown_c0_->unknown_0_;
                arg0->unknown_c0_->unknown_0_ = 0;
                RESET_NAVIGATION(8, 1, 8, arg0->unknown_c58_ - 1);
                controls->unknown_800_.unknown_3c_ = 0;
                TAB_CURSOR(arg0->unknown_c58_ - 1);
            }
        } else if (arg0->unknown_c58_ != 8) {
            int var24 = arg0->unknown_3ec_.unknown_800_.unknown_c_;
            int var25 = func_0205bafc(&arg0->unknown_3ec_.unknown_800_);
            if (var24 == 1 && var25 == 8) {
                if (var16 >= arg0->unknown_da0_[arg0->unknown_da3_]) {
                    func_0205bb04(&arg0->unknown_3ec_.unknown_800_, arg0->unknown_da0_[arg0->unknown_da3_] - 1);
                    var16 = arg0->unknown_da0_[arg0->unknown_da3_] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    func_ov009_02188c2c(arg0);
                    arg0->unknown_d9c_ |= 0x2000;
                    func_ov009_02188e70(arg0, func_0205bb84((Struct_0205bb84*)&arg0->unknown_3ec_.unknown_800_));
                    return -1;
                }
                if (var16 >= 0) { TAB_CURSOR(var16); }
                if (g_keyManager.TestKeysPressed(1)) {
                    var15 = func_0205bb84((Struct_0205bb84*)&arg0->unknown_3ec_.unknown_800_) + 101;
                    if (var15 - 100 <= arg0->unknown_da0_[arg0->unknown_da3_] && var15 - 100 != arg0->unknown_c58_)
                        func_0205eaa0(&data_02108760, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) var15 = -3;
                if (var15 == 108) func_0205ba68((Struct_0205ba68*)&arg0->unknown_3ec_.unknown_800_, 11, 6, 0);
                return var15;
            }
            if (g_keyManager.TestKeysPressed(0x40) && var21 == 0) {
                RESET_NAVIGATION(8, 1, 8, arg0->unknown_c58_ - 1);
                controls->unknown_800_.unknown_3c_ = 0;
                TAB_CURSOR(arg0->unknown_c58_ - 1);
                arg0->unknown_d9c_ |= 0x2000;
                return -1;
            }
            if (g_keyManager.TestKeysPressed(1)) {
                var15 = -2;
                func_0205eaa0(&data_02108760, 1, 0);
            } else if (g_keyManager.TestKeysPressed(2)) var15 = -3;
        }
    }
    arg0->unknown_d9c_ &= ~0x10;
    if (var16 >= 0 && !(var16 >= 101 && var16 <= 108)) {
        unsigned char* var26 = &arg0->unknown_da3_;
        switch (arg0->unknown_c58_) {
        case 8: break;
        case 1: { if (*var26 != var16) arg0->unknown_d9c_ |= 0x10; *var26 = var16; break; }
        case 2: { unsigned char* var27 = arg0->unknown_da4_; int var28 = arg0->unknown_da3_; unsigned char var29 = var27[var28]; if (var29 != var16) arg0->unknown_d9c_ |= 0x10; var27[var28] = var16; break; }
        case 3: { unsigned char* var30 = arg0->unknown_dac_; int var31 = arg0->unknown_da3_; unsigned char var32 = var30[var31]; if (var32 != var16) arg0->unknown_d9c_ |= 0x10; var30[var31] = var16; break; }
        case 4: { unsigned char* var33 = arg0->unknown_dae_; int var34 = arg0->unknown_da3_; unsigned char var35 = var33[var34]; if (var35 != var16) arg0->unknown_d9c_ |= 0x10; var33[var34] = var16; break; }
        case 5: { unsigned char* var36 = arg0->unknown_da6_; int var37 = arg0->unknown_da3_; unsigned char var38 = var36[var37]; if (var38 != var16) arg0->unknown_d9c_ |= 0x10; var36[var37] = var16; break; }
        case 6: { unsigned char* var39 = arg0->unknown_daa_; int var40 = arg0->unknown_da3_; unsigned char var41 = var39[var40]; if (var41 != var16) arg0->unknown_d9c_ |= 0x10; var39[var40] = var16; break; }
        case 7: { unsigned char* var42 = arg0->unknown_da8_; int var43 = arg0->unknown_da3_; unsigned char var44 = var42[var43]; if (var44 != var16) arg0->unknown_d9c_ |= 0x10; var42[var43] = var16; break; }
        }
    }
    if (self->flags & 0x10) {
        if (self->state != 8 || !touched) DispatchWithShortB4_0205eaa0(&data_02108760, 2, 0);
        func_ov009_02188944(self, choice);
        if (self->state == 1) {
            PartyMemberAppearance* appearance = &self->member->appearance;
            self->flags |= 0x60000;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->models[2] = menuSlotToStyleIndex(self, 5, self->face[self->gender]) + 0x233c;
            appearance->models[3] = menuSlotToStyleIndex(self, 3, self->hair[self->gender]) + 0x2328;
        }
        if (!var19) func_ov009_02188e70(arg0, var16);
        arg0->unknown_d9c_ |= 0x6100;
    }
    if (var15 == 108 && var15 - 100 <= arg0->unknown_da0_[arg0->unknown_da3_] && var15 - 100 != arg0->unknown_c58_)
        func_0205ba68((Struct_0205ba68*)&arg0->unknown_3ec_.unknown_800_, 11, 6, 0);
    return var15;
}

#endif
