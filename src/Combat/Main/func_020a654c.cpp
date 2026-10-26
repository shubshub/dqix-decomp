#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_020a654c {
#if defined(jpn)
    char unknown_0_[0x34ec];
#else
    char unknown1_0_[0x36fc];
#endif
    void* unknown_36fc_;
};

struct Struct_020a654c_2 {
    char unknown_0_[3];
    unsigned char unknown_3_;
};

struct Struct_020a654c_3 {
    int unknown_0_;
    int unknown_4_;
};

extern "C" void* Zone3D_GetInstance();
extern "C" void LinkSession_GetInstance();
struct PointerField32c_ffc0;
void* GameState_GetShip(PointerField32c_ffc0*);
struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
struct S02046b1c;
void* GetField0x0List02046b1c(S02046b1c*);
struct GameResources;
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_020a75ec(void* p);
void DispatchWithZeroExtras_02193428(void*, void*);
extern "C" void func_020a7ce0(void* p);
extern "C" int func_020a7d74(void* p, int* out1, int* out2);
int FieldTaskQueue_IsEmpty(void**);
extern "C" int func_ov017_021a93f0(void* res, int a, int b);

// USA: func_020a654c
extern "C" ARM void func_020a654c(struct Res020a654c* self) {
    void* gs = GameState::GetInstance();
    unsigned short* p;
    void* nodeList = self->nodeList;
    p = (unsigned short*)Zone3D_GetInstance();
    LinkSession_GetInstance();
    void* obj = GameState_GetShip((PointerField32c_ffc0*)gs);
    ((GameState*)gs)->GetLeader();
    int id = FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)nodeList);
    void* lst = GetField0x0List02046b1c((S02046b1c*)nodeList);
    if (obj == 0) {
        return;
    }
    if (var4 == 10 && ((struct Struct_020a654c_2*)var5)->unknown_3_ != 0) {
        return;
    }
    if (var4 == 3) {
        if (IsBrightnessTransitionActive((GameResources*)arg0) == 0) {
            return;
        }
    }
    func_020a75ec(var3);
    if (TestFlags00((GameResources*)arg0, 0x2020) == 0) {
        func_ov017_02193428(var3, (void*)1);
    }
    if (*var1 == 0x2710) {
        func_020a7ce0(var3);
    }
    if (TestFlags00((GameResources*)arg0, 0x2020) != 0) {
        return;
    }
    struct Struct_020a654c_3 var6;
    var6.unknown_4_ = 0;
    var6.unknown_0_ = 0;
    if (func_020a7d74(var3, &var6.unknown_4_, &var6.unknown_0_) == 0) {
        return;
    }
    if (var6.unknown_0_ != 0 && var6.unknown_0_ == 1) {
        var6.unknown_4_ = 0x76c;
    }
    if (var6.unknown_4_ == 0) {
        return;
    }
    if (FieldTaskQueue_IsEmpty((void**)self->nodeList) == 0) {
        return;
    }
    func_ov017_021a93f0(arg0, var6.unknown_4_, 0);
}
