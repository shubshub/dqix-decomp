#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov006_02154e58 func_ov006_021565b0
#endif
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_020dbd9c {
    char unknown_0_[0x10];
    int unknown_10_;
    unsigned char unknown_14_;
};

struct Struct_ov006_02154614_2 {
    char unknown_0_[LOW_REGION(0x6f0, 0x774)];
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

#include "NitroSDK/Graphics.h"

struct Struct_0210a010_3 {
    char unknown_0_[0xa0];
    int unknown_a0_;
};
extern Struct_0210a010_3 data_0210a010;

void InitCombatController020a2010(void* camera);
void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
extern "C" void func_0202e5d8(void* camera, int x, int y, int z);
extern "C" void Camera_Update(void* camera);
void FollowCamera_DisableFollow(void* camera);
void InitCombatEntry021542f4(void* camera);

// USA: func_ov006_02154e58
extern "C" ARM void func_ov006_02154e58(Struct_ov006_02154614* arg0) {
    if (!(arg0->unknown_ae2_ & 0x1000))
        return;
    if ((arg0->unknown_ae2_ & (0x40 | 8)) &&
        ((arg0->unknown_ae2_ & 8) || (arg0->unknown_ae4_.unknown_774_ & 4))) {
        if (arg0->unknown_ae4_.unknown_77d_ != 2)
            return;
        if (!arg0->unknown_ae4_.unknown_79b_1_)
            return;
    }
    if (arg0->unknown_ae4_.unknown_77d_ == 2 && arg0->unknown_ae4_.unknown_79b_1_ && (arg0->unknown_ae4_.unknown_774_ & 4)) {
        data_0210a010.unknown_a0_ = 0x46501313;
        void* var0 = arg0->unknown_5cc_;
        BG0CNT = BG0CNT & ~3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3) | 2;
        if (camera != 0) {
            InitCombatController020a2010(camera);
            Camera_SetTarget((struct Camera*)self->camera_, 0, -0x1e8f, 0);
            func_0202e5d8(self->camera_, 0, 0x2bae, 0x9199);
            Camera_Update(self->camera_);
            FollowCamera_DisableFollow(self->camera_);
        }
        arg0->unknown_12bd_ = 0;
    } else {
        func_ov006_021542f4(arg0->unknown_5cc_);
    }
    arg0->unknown_238_.Draw(true);
    arg0->unknown_2e4_.Draw(true);
    arg0->unknown_390_.Draw(true);
    arg0->unknown_43c_.Draw(true);
}
