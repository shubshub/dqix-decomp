#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov001_02154974 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_1_;
    short unknown_2_;
    char unknown_4_[4];
    int unknown_8_;
    char unknown_c_[0x11 - 0xc];
    char unknown_11_[0x34 - 0x11];
    struct Struct_ov001_02154974* unknown_34_;
};

struct Struct_ov001_02154974_2 {
    unsigned char unknown_0_;
    char unknown_1_[0x28 - 1];
    struct Struct_ov001_02154974_2* unknown_28_;
};

struct Struct_ov001_02154974_3 {
#if defined(jpn)
    char unknown_0_[0xcc];
#else
    char unknown1_0_[0xd0];
#endif
    struct Struct_ov001_02154974* unknown_d0_;
    struct Struct_ov001_02154974_2* unknown_d4_;
    char unknown_d8_[0xf8 - 0xd8];
    unsigned int unknown_f8_0_ : 27;
};

struct Struct_ov001_02154974_4 {
    char unknown_0_[0x98];
    unsigned int unknown_98_;
};

struct Struct_ov001_02154974_5 {
    unsigned int unknown_0_;
    char unknown_4_[0x18 - 4];
    GameObject* unknown_18_;
};

struct Struct_ov001_02154974_6 {
    char unknown_0_[0xd4];
    unsigned char unknown_d4_0_ : 1;
};

extern "C" {
struct Struct_ov001_02154974_4* func_0203cf4c(void);
void func_0200fd48(GameState* arg0, int arg1);
struct Struct_ov001_02154974_5* func_0203df78(void* arg0, int arg1);
int* func_0203dce4(void* arg0, int arg1);
int func_02040404(void* arg0, const char* arg1);
void func_0204039c(void* arg0, int arg1);
void func_02040504(int* arg0);
void func_0203dd10(void* arg0, int arg1, int arg2);
void func_ov001_0215acd4(int arg0);
}

extern "C" void* func_0203d004(void* arg0);

#if defined(jpn)
#define data_ov001_02164bd1 data_ov001_02166171
#endif
extern char data_ov001_02164bd1[];

// USA: func_ov001_02154974
extern "C" ARM void func_ov001_02154974(struct Struct_ov001_02154974_3* arg0) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_ov001_02154974_4* var1 = func_0203cf4c();
    GameResources* var2 = GetGameResources();
    struct Struct_ov001_02154974_2* var3;
    struct Struct_ov001_02154974* var4;
    struct Struct_ov001_02154974* var5;
    int var6;

    for (var3 = arg0->unknown_d4_; var3 != 0; var3 = var3->unknown_28_) {
        for (var5 = arg0->unknown_d0_; var5 != 0; var5 = var5->unknown_34_) {
            if (var5->unknown_1_ != var3->unknown_0_) {
                continue;
            }
            if (walk->kind == 0 || walk->kind == 1 || walk->kind == 9 || walk->kind == 0xb || walk->kind == 0xc ||
                walk->kind == 0xd || walk->kind == 0xa || walk->kind == 4) {
                GameObject* obj = gs->GetGameObjectByIndex(walk->slot);
                if (obj != 0) {
                    Object3D* o = &obj->obj3D_;
                    unsigned char animFlags = o->animationFlags_;
                    const char* animName = (const char*)o->activeAnimationRecord_;
                    o->RemoveAnimationPackageByID(3);
                    if (o->SetAnimationByName(animName, animFlags) == false) {
                        o->SetAnimationByName(data_ov001_02164bd1, 0);
                    }
                }
            }
            break;
        }
    }

    var6 = 0;
    for (var4 = arg0->unknown_d0_; var4 != 0; var4 = var4->unknown_34_) {
        switch (var4->unknown_0_0_) {
        case 5: {
            struct Struct_ov001_02154974_5* var11 = func_0203df78(var1, var4->unknown_8_);
            if (var11 != 0) {
                var11->unknown_0_ &= ~0x10000;
            }
            break;
        }
        case 4: {
            func_0200fd48(var0, var4->unknown_2_);
            struct Struct_ov001_02154974_5* var12 = func_0203df78(var1, var4->unknown_8_);
            if (var12 != 0 && var12->unknown_18_ != 0) {
                ((struct Struct_ov001_02154974_6*)var12->unknown_18_)->unknown_d4_0_ = 0;
                var12->unknown_0_ &= ~0x10000;
            }
            break;
        }
        case 2:
        case 6:
        case 7:
        case 8:
            if (var0->GetGameObjectByIndex(var4->unknown_2_) != 0) {
                func_0200fd48(var0, var4->unknown_2_);
            }
            break;
        case 3: {
            int* var13 = func_0203dce4(var1, var4->unknown_2_);
            if (var13 != 0) {
                void* var14 = func_0203d004(var1);
                func_0204039c(
                    var14, func_02040404(var14, var4->unknown_11_));
                func_02040504(var13);
                func_0203dd10(var1, var4->unknown_2_, var6);
            }
            break;
        }
        case 13:
        case 12:
        case 11:
        case 10:
            break;
        }
        func_ov001_0215acd4(var4->unknown_1_);
    }

    if (arg0->unknown_f8_0_ == 0) {
        return;
    }
    if (arg0->unknown_f8_0_ & 1) {
        ClearFlags04(var2, 8);
    }
    if (arg0->unknown_f8_0_ & 2) {
        ClearFlags04(var2, 0x10);
    }
    if (arg0->unknown_f8_0_ & 4) {
        int var15;
        for (var15 = 0; var15 < 4; var15++) {
            GameObject* var16 = var0->GetGameObjectByIndex(var15);
            if (var16 != 0) {
                var16->obj3D_.DisableFlag(1);
            }
        }
    }
    if (arg0->unknown_f8_0_ & 8) {
        ClearFlags04(var2, 0x400);
    }
    if (arg0->unknown_f8_0_ & 0x20) {
        func_0203cf4c()->unknown_98_ &= ~2;
    }
}
