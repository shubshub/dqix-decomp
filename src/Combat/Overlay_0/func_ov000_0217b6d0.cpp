#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_0205c570;
struct Struct_0205def8;
struct SePlayer;

int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int clear, int key);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int IsBitFlagSet0217c4e8(void* obj, int bit);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_ov000_021716d0(void* obj);
void* GetFieldAt0x150_02053c6c(unsigned char* obj);
int CheckFlagsOrField_0217ab48_0217ab48(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct Struct_ov000_0217b6d0_4 {
    char unknown_0_[0x188];
#if defined(jpn)
    char unknown_188_[0x1faa - 0x188];
#else
    char unknown1_188_[0x1d72 - 0x188];
#endif
    unsigned short unknown_1d72_;
};

struct Struct_ov000_02184294_5 {
#if defined(jpn)
    Struct_ov000_0217b6d0_4* unknown_0_;
    int unknown_4_;
    int unknown_8_;
    Struct_ov000_0217b6d0_4* const& inline_ov000_0217b6d0() const {
        return unknown_0_;
    }
#else
    int unknown1_0_;
    int unknown1_4_;
    Struct_ov000_0217b6d0_4* unknown1_8_;
#endif
    short unknown_c_;
};

struct Struct_ov000_0217b6d0 {
#if defined(jpn)
    char unknown_0_[0x8ca];
#else
    char unknown1_0_[0x962];
#endif
    unsigned short unknown_962_;
};

struct Struct_ov000_0217b6d0_2 {
    char unknown_0_[0xb8];
    unsigned char unknown_b8_;
};

struct Struct_ov000_0217b6d0_3 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x1e - 0x19];
    short unknown_1e_;
    char unknown_20_[0x26 - 0x20];
    unsigned short unknown_26_;
    char unknown_28_[0x38 - 0x28];
    Struct_ov000_0217b6d0_2* unknown_38_;
    char unknown_3c_[0x4c - 0x3c];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x484 - 0x50];
#else
    char unknown1_50_[0x444 - 0x50];
#endif
    unsigned char unknown_444_;
#if defined(jpn)
    const short& inline_ov000_0217b6d0_2() const {
        return unknown_1e_;
    }
#endif
};

extern MenuGlobals_0217b6d0 data_ov000_02184294;
extern char g_sePlayer;

#if defined(jpn)
// USA: func_ov000_0217b6d0
extern "C" ARM int func_ov000_0217b6d0(Struct_ov000_0217b6d0_3* arg0, int arg1, int arg2) {
    Struct_ov000_0217b6d0_4* var0;
    enum Enum_ov000_0217b518 { Enum_ov000_0217b518_m32768 = -32768, Enum_ov000_0217b518_32767 = 32767 };
    Enum_ov000_0217b518 var1;
    data_ov000_02184294.unknown_0_->unknown_1d72_ |= 0x100;
    const short var2 = arg0->inline_ov000_0217b6d0_2();
    var1 = (Enum_ov000_0217b518)(short)func_0205d794((struct Struct_0205c570*)arg0->unknown_38_);
    arg0->unknown_1e_ = var1;
    {
    var0 = data_ov000_02184294.inline_ov000_0217b6d0();
    func_0205def8((struct Struct_0205def8*)var0->unknown_188_, 1, 0x23);
    if (var2 != var1) {
        return -1;
    }
    int var3 = g_keyManager.TestKeysPressed(0x601);
    bool var4 = (var3 | func_0205da38((struct Struct_0205da38*)arg0->unknown_38_, 0x14)) != 0;
    if (var4 || arg0->unknown_444_ != 0) {
        if (!func_ov000_0217c4e8(arg0, var1)) {
            return arg0->unknown_10_[arg0->unknown_18_];
        }
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)ctx->list, 0, 0x23);
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        func_ov000_021716d0(obj);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member != NULL) {
            MemberInfo_0217b6d0* info = (MemberInfo_0217b6d0*)GetFieldAt0x150_02053c6c((unsigned char*)member);
            if (info != NULL) {
                info->lastSpell = obj->actionId;
            }
        }
        if (arg0->unknown_10_[arg0->unknown_18_] != 0x64) {
            arg0->unknown_38_->unknown_b8_ = 0x10;
        }
        return arg0->unknown_10_[arg0->unknown_18_];
    }
    if (func_ov000_0217ab48(arg0)) {
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_--;
        arg0->unknown_1e_ = -1;
        arg0->unknown_26_ = 0;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.unknown_0_, arg0, arg0->unknown_10_[arg0->unknown_18_], data_ov000_02184294.unknown_8_, data_ov000_02184294.unknown_4_, 0);
    }
    return -1;
    }
}
#else
// USA: func_ov000_0217b6d0
extern "C" ARM int func_ov000_0217b6d0(Struct_ov000_0217b6d0_3* arg0, int arg1, int arg2) {
    Struct_ov000_0217b6d0_4* var7;
    short var8;
    data_ov000_02184294.unknown1_8_->unknown_1d72_ |= 0x100;
    short var9 = arg0->unknown_1e_;
    var8 = func_0205d794((struct Struct_0205c570*)arg0->unknown_38_);
    arg0->unknown_1e_ = var8;
    var7 = data_ov000_02184294.unknown1_8_;
    func_0205def8((struct Struct_0205def8*)var7->unknown1_188_, 1, 0x23);
    if (var9 != var8) {
        return -1;
    }
    int var10 = g_keyManager.TestKeysPressed(0x601);
    int var11 = (var10 | func_0205da38((struct Struct_0205da38*)arg0->unknown_38_, 0x14)) != 0;
    if (var11 || arg0->unknown_444_ != 0) {
        if (!func_ov000_0217c4e8(arg0, var8)) {
            return arg0->unknown_10_[arg0->unknown_18_];
        }
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)ctx->list, 0, 0x23);
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        func_ov000_021716d0(obj);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member != NULL) {
            MemberInfo_0217b6d0* info = (MemberInfo_0217b6d0*)GetFieldAt0x150_02053c6c((unsigned char*)member);
            if (info != NULL) {
                info->lastSpell = obj->actionId;
            }
        }
        if (arg0->unknown_10_[arg0->unknown_18_] != 0x64) {
            arg0->unknown_38_->unknown_b8_ = 0x10;
        }
        return arg0->unknown_10_[arg0->unknown_18_];
    }
    if (func_ov000_0217ab48(arg0)) {
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_--;
        arg0->unknown_1e_ = -1;
        arg0->unknown_26_ = 0;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.unknown1_8_, arg0, arg0->unknown_10_[arg0->unknown_18_], data_ov000_02184294.unknown1_4_, data_ov000_02184294.unknown1_0_, 0);
    }
    return -1;
}
#endif
