#include <globaldefs.h>

#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_020dbd9c {
    char unknown_0_[0x10];
    int unknown_10_;
    unsigned char unknown_14_;
};

struct Struct_ov006_02154614_2 {
    char unknown_0_[0x774];
    unsigned short unknown_774_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unknown_0_[0x7c];
};

struct Struct_ov006_021537d0 {
    short unknown_0_;
};

struct Struct_ov006_021555b0 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char unknown_0_[3][0x80];
#endif
    SafeAllocator* unknown_180_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* unknown_1a0_;
    void* unknown_1a4_;
    unsigned char* unknown_1a8_;
    void* unknown_1ac_;
    void* unknown_1b0_;
    Struct_ov006_021537d0* unknown_1b4_;
    Struct_ov006_021537d0* unknown_1b8_;
    int unknown_1bc_;
    Struct_ov006_021555b0* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* unknown_1c8_;
    void* unknown_1cc_;
    void* unknown_1d0_;
    void* unknown_1d4_;
    void* unknown_1d8_;
    void* unknown_1dc_;
    void* unknown_1e0_;
    char unknown_1e4_[0x54];
    Object3D unknown_238_;
    Object3D unknown_2e4_;
    Object3D unknown_390_;
    Object3D unknown_43c_;
    Object3D unknown_4e8_;
    char unknown_594_[0x38];
    char unknown_5cc_[0x2c8];
    Struct_ov006_02156e54 unknown_894_[4];
    SafeAllocator unknown_a84_[4];
    int unknown_ad4_;
    int unknown_ad8_;
    unsigned char unknown_adc_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short unknown_ae2_;
    Struct_ov006_02154614_2 unknown_ae4_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char unknown_1288_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short unknown_12b8_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

void SetForwardAndStore0205ebc0(void* sound, int a, int b);
void DispatchIfField0xc4NonNeg_0205ebfc(void* sound, int a, int b);
void ForwardField0xc0_0205ebec(void* sound);

extern char data_02108760[];
extern char data_ov006_02160080[];
extern char data_ov006_02160087[];
extern char data_ov006_02160089[];
extern char data_ov006_0216008b[];
extern char data_ov006_02160092[];
extern char data_ov006_02160094[];
extern char data_ov006_02160096[];
extern char data_ov006_0216009e[];
extern char data_ov006_021600a0[];
extern char data_ov006_021600a9[];

// USA: func_ov006_02155068
extern "C" ARM void func_ov006_02155068(AlchemyPot* self) {
    unsigned int* resources = (unsigned int*)(void*)GameState::GetInstance()->GetResources();
    unsigned short flags = self->flags_;
    if (flags & 0x2000) {
        SetFlags04((GameResources*)resources, 0x2000);
        self->steam_.MaybeSetRegularAnimation(data_ov006_02160080, 9);
        self->steam_.EnableFlag(0x1000);
        return;
    }
    if (var1 & 0x80) {
        if (arg0->unknown_ae1_ == 0) {
            func_0205ebc0(data_02108760, 0x7a, 0x7a);
            func_0205ebfc(data_02108760, 0, 0);
            arg0->unknown_2e4_.MaybeSetRegularAnimation(data_ov006_02160080, 1);
            arg0->unknown_43c_.MaybeSetRegularAnimation(data_ov006_02160087, 1);
            arg0->unknown_4e8_.MaybeSetRegularAnimation(data_ov006_02160080, 9);
            arg0->unknown_4e8_.DisableFlag(0x1000);
        } else if (arg0->unknown_ae1_ >= 1 && arg0->unknown_2e4_.HasAnimationStopped()) {
            arg0->unknown_ae1_ = 0;
            arg0->unknown_ae2_ &= ~0x80;
            arg0->unknown_43c_.MaybeSetRegularAnimation(data_ov006_02160089, 1);
            arg0->unknown_2e4_.MaybeSetRegularAnimation(data_ov006_0216008b, 0);
            arg0->unknown_4e8_.StopCurrentAnimation();
            return;
        }
        arg0->unknown_ae1_++;
        return;
    }
    if (var1 & 0x100) {
        if (!arg0->unknown_2e4_.HasAnimationReachedEnd())
            return;
        if (arg0->unknown_ae1_ == 0) {
            arg0->unknown_43c_.MaybeSetRegularAnimation(data_ov006_02160092, 0);
        } else if (arg0->unknown_ae1_ == 1) {
            arg0->unknown_43c_.MaybeSetRegularAnimation(data_ov006_02160094, 1);
        } else if (arg0->unknown_ae1_ == 2) {
            arg0->unknown_ae1_ = 0;
            arg0->unknown_2e4_.StopCurrentAnimation();
            arg0->unknown_2e4_.MaybeSetRegularAnimation(data_ov006_02160096, 1);
            arg0->unknown_43c_.MaybeSetRegularAnimation(data_ov006_0216009e, 0);
            arg0->unknown_4e8_.MaybeSetRegularAnimation(data_ov006_02160096, 1);
            arg0->unknown_ae2_ &= ~0x100;
            return;
        }
        arg0->unknown_ae1_++;
        return;
    }
    if (var1 & 0x200) {
        arg0->unknown_ae2_ = var1 | 0x800;
        if (!arg0->unknown_2e4_.HasAnimationStopped()) {
            arg0->unknown_ae1_++;
            return;
        }
        ClearFlags04((GameResources*)var0, 0x2000);
        func_0205ebec(data_02108760);
        arg0->unknown_ae1_ = 0;
        arg0->unknown_2e4_.MaybeSetRegularAnimation(data_ov006_021600a0, 1);
        arg0->unknown_43c_.StopCurrentAnimation();
        arg0->unknown_ae2_ &= ~0x200;
        return;
    }
    if (var1 & 0x400) {
        if (arg0->unknown_2e4_.HasAnimationStopped()) {
            arg0->unknown_ae1_ = 0;
            arg0->unknown_2e4_.MaybeSetRegularAnimation(data_ov006_021600a9, 0);
            arg0->unknown_43c_.StopCurrentAnimation();
            arg0->unknown_ae2_ &= ~0x400;
            return;
        }
        arg0->unknown_2e4_.MaybeSetRegularAnimation(data_ov006_021600a0, 1);
        return;
    }
    arg0->unknown_ae1_ = 0;
    arg0->unknown_2e4_.MaybeSetRegularAnimation(data_ov006_021600a9, 0);
    arg0->unknown_43c_.StopCurrentAnimation();
}
