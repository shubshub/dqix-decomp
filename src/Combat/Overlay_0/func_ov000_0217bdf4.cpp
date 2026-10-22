#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
#define data_ov000_02183658 data_ov000_02184714
#endif
struct Struct_0205c570;
struct Struct_0205def8;
struct SePlayer;

int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int clear, int key);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void* GetFieldAt0x150_02053c6c(unsigned char* obj);
void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern "C" void* func_02079e2c(char* arg0, int arg1);
extern "C" int func_ov000_0217ab48(void* arg0);
extern "C" void func_ov000_021718a4(void* arg0);
extern "C" void func_ov000_0217629c(void* arg0);
extern "C" void func_ov000_0217ab8c(void* arg0, int arg1, int arg2);
extern "C" void func_ov000_02176e3c(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5);

struct Struct_ov000_0217bdf4_4 {
    char unknown_0_[0x188];
#if defined(jpn)
    char unknown_188_[0x1faa - 0x188];
#else
    char unknown_188_[0x1d72 - 0x188];
#endif
    unsigned short unknown_1d72_;
};

struct Struct_ov000_02184294_8 {
#if defined(jpn)
    Struct_ov000_0217bdf4_4* unknown_8_;
    int unknown_0_;
    int unknown_4_;
#else
    int unknown_0_;
    int unknown_4_;
    Struct_ov000_0217bdf4_4* unknown_8_;
#endif
};

struct Struct_ov000_0217bdf4 {
    int unknown_0_;
    unsigned int unknown_4_0_ : 12;
};

struct Struct_ov000_0217bdf4_2 {
#if defined(jpn)
    char unknown_0_[0x8b8];
#else
    char unknown1_0_[0x950];
#endif
    int unknown_950_;
};

struct Struct_ov000_0217bdf4_3 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x1d - 0x19];
    signed char unknown_1d_;
    char unknown_1e_[0x23 - 0x1e];
    signed char unknown_23_;
    char unknown_24_[0x26 - 0x24];
    unsigned short unknown_26_;
    char unknown_28_[0x38 - 0x28];
    void* unknown_38_;
    char unknown_3c_[0x4c - 0x3c];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x484 - 0x50];
#else
    char unknown1_50_[0x444 - 0x50];
#endif
    unsigned char unknown_444_;
};

extern MenuGlobals_0217bdf4 data_ov000_02184294;
extern char g_sePlayer;
extern short data_ov000_02183658[];

// USA: func_ov000_0217bdf4
extern "C" ARM int func_ov000_0217bdf4(Struct_ov000_0217bdf4_3* arg0, int arg1, int arg2) {
    data_ov000_02184294.unknown_8_->unknown_1d72_ |= 0x100;
    arg0->unknown_23_ = func_0205d794((struct Struct_0205c570*)arg0->unknown_38_);
    Struct_ov000_0217bdf4_4* var0 = data_ov000_02184294.unknown_8_;
    func_0205def8((struct Struct_0205def8*)var0->unknown_188_, 1, 0x16);
    int var1 = g_keyManager.TestKeysPressed(0x601);
    int var2 = (var1 | func_0205da38((struct Struct_0205da38*)arg0->unknown_38_, 0x14)) != 0;
    if (var2 || arg0->unknown_444_ != 0) {
        GameObject* var3 = GameState::GetInstance()->GetPartyMemberByIndex(arg0->unknown_4c_);
        if (var3 == NULL) {
            return -1;
        }
        int kind = ((MemberInfo_0217bdf4*)GetFieldAt0x150_02053c6c((unsigned char*)member))->spellKind;
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        obj->field1d = 0;
        ActionDataTables* data = GetData02108e10_020797dc();
        if (data == NULL) {
            return -1;
        }
        Struct_ov000_0217bdf4* var6 = (Struct_ov000_0217bdf4*)func_02079e2c((char*)var5, data_ov000_02183658[var4]);
        if (var6 == NULL) {
            return -1;
        }
        arg0->unknown_26_ = var6->unknown_4_0_;
        func_ov000_021718a4(arg0);
        func_0205def8((struct Struct_0205def8*)var0->unknown_188_, 0, 0x16);
        return arg0->unknown_10_[arg0->unknown_18_];
    }
    if (func_ov000_0217ab48(arg0)) {
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_--;
        arg0->unknown_23_ = -1;
        arg0->unknown_1d_ = -1;
        arg0->unknown_26_ = 0;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.unknown_8_, arg0, arg0->unknown_10_[arg0->unknown_18_], data_ov000_02184294.unknown_4_, data_ov000_02184294.unknown_0_, 0);
    }
    return -1;
}
