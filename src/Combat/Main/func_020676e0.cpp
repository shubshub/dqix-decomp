#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_020676e0 {
    char unknown_0_[0x23c];
    int unknown_23c_;
    char unknown_240_[4];
    unsigned char unknown_244_;
};
struct Struct_020676e0_2 { char unknown_0_[0xda]; unsigned short unknown_da_; };
struct Struct_020676e0_3 { char unknown_0_[(IS_JPN ? 0x5a68 : 0x5cc8)]; unsigned char unknown_5cc8_; };
struct Struct_020676e0_4 {
    char unknown_0_[(IS_JPN ? 0x4c : 0x8c)];
    Struct_020676e0_2* unknown_8c_;
    unsigned char unknown_90_[(IS_JPN ? 0x824 - 0x50 : 0x954 - 0x90)];
    int unknown_954_;
    char unknown_958_[(IS_JPN ? 0x85c - 0x828 : 0x98c - 0x958)];
    int unknown_98c_;
    char unknown_990_[(IS_JPN ? 0x870 - 0x860 : 0x9a0 - 0x990)];
    int unknown_9a0_;
    char unknown_9a4_[(IS_JPN ? 0x17ea - 0x874 : 0x19ba - 0x9a4)];
    unsigned char unknown_19ba_;
    char unknown_19bb_[(IS_JPN ? 0x17ff - 0x17eb : 0x19d2 - 0x19bb)];
    #if defined(jpn)
    unsigned char unknown_17ff_0_ : 4;
    unsigned char unknown_19d2_ : 1;
    unsigned char unknown_17ff_5_ : 3;
#else
    unsigned char unknown_19d2_;
#endif
};
typedef void (Struct_020676e0_4::*Type_02000c9c_11)(int);
#if defined(jpn)
extern Type_02000c9c_11 data_020f079c[2];
#define data_020f08b8 data_020f079c
#else
extern Type_02000c9c_11 data_020f08b8[2];
#endif
void SetupAndDispatch0205c904(unsigned char*, int);
int CheckGlobalObjState2AndInit0205cde8(unsigned char*);
void InitGlobalObjAndSelfPointer0205cd94(unsigned char*);
int GameState_GetFollowCamera(char*);
int GetIntAt0x23c(IntField0x23c_020a27c4*);
int IsFieldNotPositive_021a4e70(unsigned char*);
int GetScaledSumIfActive0205cecc(void*);
int CallFunc0205c570AtField0x1c_0205cb64(void*);

// USA: func_020676e0
extern "C" ARM void func_020676e0(Struct_020676e0_4* arg0, int arg1) {
    if (arg0->unknown_9a0_ != 6) return;
    if (!arg0->unknown_19ba_) return;
    func_0205c904(arg0->unknown_90_, arg1);
    if (!func_0205cde8(arg0->unknown_90_)) {
        func_0205cd94(arg0->unknown_90_);
        return;
    }
    int enabled = 1;
    bool pressed = g_keyManager.TestKeysPressed(0x401) != 0;
    bool cancelled = g_keyManager.TestKeysPressed(2) != 0;
    GameState* game;
    unsigned char* resource;
    int mode = state->mode;
    game = GameState::GetInstance();
    IntField0x23c_020a27c4* field = (IntField0x23c_020a27c4*)GameState_GetFollowCamera((char*)game);
    resource = (unsigned char*)(int)game->GetResources();
    if (mode != 1 && state->alternateInput) {
        if (field) {
            if ((field->flags & 2) || !GetIntAt0x23c(field))
                pressed |= g_keyManager.TestKeysPressed(0x200);
        } else {
            var1 |= g_keyManager.TestKeysPressed(0x200);
        }
    }
    int var7 = 0;
    if (((Struct_020676e0_3*)var3)->unknown_5cc8_ == 2) var7 = 1;
    if (!var7 && var4 && !func_ov017_021a4e70(var4)) {
        var1 = 0;
        var2 = 0;
        var0 = 0;
    }
    if (!var7 && arg0->unknown_8c_ && (arg0->unknown_8c_->unknown_da_ & 0x20)) {
        var1 = 0;
        var2 = 0;
        var0 = 0;
    }
    int var8 = -1;
    if (var0) var8 = func_0205cecc(arg0->unknown_90_);
    if (var1) var8 = func_0205cb64(arg0->unknown_90_);
    else if (var2) var8 = -2;
    arg0->unknown_954_ = var8;
    (arg0->*data_020f08b8[var5])(var8);
}
