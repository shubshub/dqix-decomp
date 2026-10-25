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
extern "C" void func_0202ae18();
struct Struct_0200ffc0;
extern "C" void* func_0200ffc0(Struct_0200ffc0*);
struct Struct_02015438;
extern "C" int func_02046b24(Struct_02015438**);
struct Struct_02046b1c;
extern "C" void* func_02046b1c(Struct_02046b1c*);
struct GameResources;
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_020a75ec(void* arg0);
extern "C" void func_ov017_02193428(void*, void*);
extern "C" void func_020a7ce0(void* arg0);
extern "C" int func_020a7d74(void* arg0, int* arg1, int* arg2);
extern "C" int func_02046b08(void**);
extern "C" int func_ov017_021a93f0(void* arg0, int arg1, int arg2);

// USA: func_020a654c
extern "C" ARM void func_020a654c(struct Res020a654c* self) {
    void* gs = GameState::GetInstance();
    unsigned short* p;
    void* nodeList = self->nodeList;
    p = (unsigned short*)Zone3D_GetInstance();
    func_0202ae18();
    void* var3 = func_0200ffc0((Struct_0200ffc0*)var0);
    ((GameState*)var0)->GetUnknownGameObject();
    int var4 = func_02046b24((Struct_02015438**)var2);
    void* var5 = func_02046b1c((Struct_02046b1c*)var2);
    if (var3 == 0) {
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
    if (func_02046b08((void**)arg0->unknown_36fc_) == 0) {
        return;
    }
    func_ov017_021a93f0(arg0, var6.unknown_4_, 0);
}
