#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_ov009_0218aa28 { int unknown_0_; int unknown_4_; int unknown_8_; };
struct Struct_02010604;
struct Struct_02033b68;
struct Struct_02033b58;
struct Struct_02033834_2;
struct Struct_0201e8fc_2;
struct Struct_02038138;

struct Struct_02038138_2 {
    char unknown_0_[0x18];
    short unknown_18_;
};

struct Struct_02038138_3 {
    char unknown_0_[0x220];
    unsigned char unknown_220_;
    unsigned char unknown_221_;
    unsigned char unknown_222_;
    unsigned char unknown_223_;
    unsigned char unknown_224_;
};

struct Struct_020a78dc {
    char unknown_0_[0x44];
    struct Struct_ov009_0218aa28 unknown_44_;
    char unknown_50_[0xbe - 0x50];
    unsigned char unknown_be_;
    char unknown_bf_;
    unsigned char unknown_c0_;
    char unknown_c1_[0x134 - 0xc1];
    int unknown_134_;
    char unknown_138_[0x154 - 0x138];
    unsigned char unknown_154_;
    char unknown_155_[0x158 - 0x155];
    unsigned char unknown_158_;
    char unknown_159_[0x15d - 0x159];
    signed char unknown_15d_;
    short unknown_15e_;
};

struct Struct_020e90a8 { int unknown_0_[8]; };

extern "C" char* Zone3D_GetInstance();
struct Field4328* GetField4328_0218d268(void*);
int IsField0Null_02046b08(void** p);
void SetByte0xbeShiftPrev(struct Bytes02033b88*, int);
void GameObject_SetMotionState(struct Obj02033b68*, int);
void SetByteSavingPrevious(struct Foo02033b58*, unsigned char);
int GetField0x70_0202e7f0(void*);
int fix32ReduceAngle0To2Pi(int);
extern "C" struct Struct_02038138_2* func_0201e8fc(struct Struct_0201e8fc_2*, struct Struct_ov009_0218aa28*);
int fix32SignedAngleDistance(int, int);
int fix32abs(int);
void GameObject_SetFacing(struct Obj02033834*, int);
short GetShortAt0x22e(struct ShortField0x22e_020968c4*);

#if defined(jpn)
#define data_020e90a8 data_020e91b4
#endif
extern struct Struct_020e90a8 data_020e90a8;

// USA: func_020a78dc
extern "C" ARM void func_020a78dc(struct Struct_020a78dc* arg0) {
    char* var0;
    void* var1;
    char* var2;
    struct Struct_02038138_3* var3;
    void** var4;

    camera = GameState::GetInstance()->GetCamera();
    ov = (char*)GetGameResources();
#if defined(jpn)
    enum { Enum_020a78dc_14076 = 0x34ec, Enum_020a78dc_108 = 0x8c };
#else
    enum { Enum_020a78dc_14076 = 0x36fc, Enum_020a78dc_108 = 0x6c };
#endif
    list = *(void***)(ov + regionalOffset0);
    world = Zone3D_GetInstance();
    f = GetField4328_0218d268(ov);
    struct AngleTable table = data_020e90a8;

    arg0->unknown_134_ = 0;
    if (g_keyManager.IsUpHeld() && g_keyManager.IsLeftHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 0xc;
    } else if (g_keyManager.IsUpHeld() && g_keyManager.IsRightHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 0xd;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsLeftHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 0xe;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsRightHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 0xf;
    } else if (g_keyManager.IsUpHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 8;
    } else if (g_keyManager.IsDownHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 9;
    } else if (g_keyManager.IsLeftHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 0xa;
    } else if (g_keyManager.IsRightHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_158_ = 0xb;
    }

    if (g_touchInput.timeHeld_ >= 5) {
        arg0->unknown_134_ = 2;
        struct Struct_ov009_0218aa28 var6;
        struct Struct_ov009_0218aa28 var7;
        int var8 = var3->unknown_222_;
        int var9 = var3->unknown_220_;
        int var10 = var3->unknown_223_;
        int var11 = var3->unknown_221_;
        int var12 = var10 << 12;
        var7.unknown_0_ = var8 << 12;
        var7.unknown_4_ = var12;
        var7.unknown_8_ = 0;
        var6.unknown_0_ = var9 << 12;
        var6.unknown_4_ = var11 << 12;
        var6.unknown_8_ = 0;
        Vector3fix_Subtract((Vector3fix*)&var7, (Vector3fix*)&var6, (Vector3fix*)&var7);
        if (Vector3fix_Length((Vector3fix*)&var7) < 0x8000) {
            arg0->unknown_134_ = 0;
        }
    }

    if (arg0->unknown_154_ == 0 || func_02046b08(var4) == 0) {
        arg0->unknown_134_ = 0;
    }

    if (arg0->unknown_134_ == 0) {
        if (arg0->unknown_158_ >= 8) {
            arg0->unknown_158_ -= 8;
        }
        if (arg0->unknown_be_ != 0) {
            func_02033b88((struct Struct_02010604*)arg0, 0);
        }
        self->lockedDir = -1;
    } else if (self->mode == 1) {
        if (self->fc0 == 0 || self->fc0 == 0xa) {
            GameObject_SetMotionState((struct Obj02033b68*)self, 1);
        } else {
            func_02033b58((struct Struct_02033b58*)arg0, 1);
        }
        int var13 = var5.unknown_0_[arg0->unknown_158_ - 8];
        int var14 = fix32ReduceAngle0To2Pi(var13 + func_0202e7f0(var1));
        if (arg0->unknown_15d_ == arg0->unknown_158_) {
            var14 = arg0->unknown_15e_;
        } else {
            struct Struct_ov009_0218aa28 var15 = arg0->unknown_44_;
            struct Struct_02038138_2* var16 = func_0201e8fc((struct Struct_0201e8fc_2*)(var0 + Enum_020a78dc_108), &var15);
            if (var16) {
                if (fix32abs(fix32SignedAngleDistance(var14, var16->unknown_18_)) < 0xc91) {
                    arg0->unknown_15d_ = arg0->unknown_158_;
                    arg0->unknown_15e_ = var16->unknown_18_;
                } else {
                    short var17 = fix32ReduceAngle0To2Pi(var16->unknown_18_ + 0x3244);
                    if (fix32abs(fix32SignedAngleDistance(var14, var17)) < 0xc91) {
                        arg0->unknown_15d_ = arg0->unknown_158_;
                        arg0->unknown_15e_ = var17;
                        var14 = arg0->unknown_15e_;
                    }
                }
            } else {
                arg0->unknown_15d_ = -1;
            }
        }
        GameObject_SetFacing((struct Obj02033834*)self, angle);
    } else if (self->mode == 2) {
        if (self->fc0 == 0) {
            GameObject_SetMotionState((struct Obj02033b68*)self, 1);
        } else {
            func_02033b58((struct Struct_02033b58*)arg0, 1);
        }
        struct Field4328* g = GetField4328_0218d268(ov);
        if (g->active != 0) {
            GameObject_SetFacing((struct Obj02033834*)self, GetShortAt0x22e((struct ShortField0x22e_020968c4*)g));
        }
        arg0->unknown_15d_ = -1;
    }
}
