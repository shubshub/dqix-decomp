#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Matrix.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#define data_020e780c data_020e8150
#else
#define RG(usa, jpn) (usa)
#endif

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
    char unknown_0_[0x224];
    unsigned char unknown_224_;
    unsigned char unknown_225_;
};

struct Struct_02038138_4 {
    char unknown_0_[0x44];
    struct Struct_ov009_0218aa28 unknown_44_;
    char unknown_50_[0xbe - 0x50];
    unsigned char unknown_be_;
    char unknown_bf_;
    unsigned char unknown_c0_;
    char unknown_c1_[RG(0x250, 0x244) - 0xc1];
    unsigned char unknown_250_;
    char unknown_251_;
    unsigned char unknown_252_;
    char unknown_253_[0x255 - 0x253];
    signed char unknown_255_;
    short unknown_256_;
};

extern "C" char* Zone3D_GetInstance();
struct Field4328* GetField4328_0218d268(void*);
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

extern int data_020e780c[8];

// USA: func_02038138
extern "C" ARM void func_02038138(struct Actor02038138* self) {
    char* world;
    void* camera;
    GameResources* ov;
    int mode;
    camera = GameState::GetInstance()->GetCamera();
    ov = GetGameResources();
    world = Zone3D_GetInstance();
    mode = 0;

    if (g_keyManager.IsUpHeld() && g_keyManager.IsLeftHeld()) {
        arg0->unknown_250_ = 0xc;
        var3 = 1;
    } else if (g_keyManager.IsUpHeld() && g_keyManager.IsRightHeld()) {
        arg0->unknown_250_ = 0xd;
        var3 = 1;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsLeftHeld()) {
        arg0->unknown_250_ = 0xe;
        var3 = 1;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsRightHeld()) {
        arg0->unknown_250_ = 0xf;
        var3 = 1;
    } else if (g_keyManager.IsUpHeld()) {
        arg0->unknown_250_ = 8;
        var3 = 1;
    } else if (g_keyManager.IsDownHeld()) {
        arg0->unknown_250_ = 9;
        var3 = 1;
    } else if (g_keyManager.IsLeftHeld()) {
        arg0->unknown_250_ = 0xa;
        var3 = 1;
    } else if (g_keyManager.IsRightHeld()) {
        arg0->unknown_250_ = 0xb;
        var3 = 1;
    }

    struct Struct_02038138_3* var4 = func_ov017_0218d268(var2);
    if (g_touchInput.timeHeld_ >= 5 && var4->unknown_225_ != 0 && var4->unknown_224_ != 0) {
        var3 = 2;
        int var5;
        int var6;
        g_touchInput.GetTouchPoint(&var5, &var6);
        Vector3fix var7;
        Vector3fix var8;
        var7.x = var5 << 12;
        var7.y = var6 << 12;
        var7.z = 0;
        var5 = g_touchInput.pressX_;
        var6 = g_touchInput.pressY_;
        var8.x = var5 << 12;
        var8.y = var6 << 12;
        var8.z = 0;
        if (Vector3fix_Distance(&var7, &var8) < 0x8000) {
            var3 = 0;
        }
    }

    if (arg0->unknown_252_ == 0 || IsMainBrightnessTransitionActive(var2) != 0) {
        var3 = 0;
    }

    if (var3 == 0) {
        if (arg0->unknown_250_ >= 8) {
            arg0->unknown_250_ -= 8;
        }
        if (arg0->unknown_252_ != 0 && arg0->unknown_be_ == 1) {
            func_02033b88((struct Struct_02010604*)arg0, 0);
        }
        self->lockedDir = -1;
    } else if (mode == 1) {
        if (self->fc0 == 0 || self->fc0 == 0xa) {
            GameObject_SetMotionState((struct Obj02033b68*)self, 1);
        } else {
            func_02033b58((struct Struct_02033b58*)arg0, 1);
        }
        int var9 = data_020e780c[arg0->unknown_250_ - 8];
        int var10 = fix32ReduceAngle0To2Pi(var9 + func_0202e7f0(var1));
        if (arg0->unknown_255_ == arg0->unknown_250_) {
            var10 = arg0->unknown_256_;
        } else {
            struct Struct_02038138_2* var11 = func_0201e8fc((struct Struct_0201e8fc_2*)(var0 + RG(0x6c, 0x8c)), &arg0->unknown_44_);
            if (var11) {
                if (fix32abs(fix32SignedAngleDistance(var10, var11->unknown_18_)) < 0xc91) {
                    arg0->unknown_255_ = arg0->unknown_250_;
                    arg0->unknown_256_ = var11->unknown_18_;
                } else {
                    short var12 = fix32ReduceAngle0To2Pi(var11->unknown_18_ + 0x3244);
                    if (fix32abs(fix32SignedAngleDistance(var10, var12)) < 0xc91) {
                        arg0->unknown_255_ = arg0->unknown_250_;
                        arg0->unknown_256_ = var12;
                        var10 = arg0->unknown_256_;
                    }
                }
            } else {
                arg0->unknown_255_ = -1;
            }
        }
        GameObject_SetFacing((struct Obj02033834*)self, angle);
    } else if (mode == 2) {
        if (self->fc0 == 0) {
            GameObject_SetMotionState((struct Obj02033b68*)self, 1);
        } else {
            func_02033b58((struct Struct_02033b58*)arg0, 1);
        }
        if (f->active != 0) {
            GameObject_SetFacing((struct Obj02033834*)self, GetShortAt0x22e((struct ShortField0x22e_020968c4*)f));
        }
        arg0->unknown_255_ = -1;
    }
}
