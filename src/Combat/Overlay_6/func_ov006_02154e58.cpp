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
    char unk_0[0x10];
    int state_;
    unsigned char unk_14;
};

struct Struct_ov006_02154614_2 {
    char unk_0[LOW_REGION(0x6f0, 0x774)];
    unsigned short flags_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unk_0[0x7c];
};

struct Struct_ov006_021537d0 {
    short id_;
};

struct Struct_ov006_021555b0 {
    short id_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char names_[3][0x80];
#endif
    SafeAllocator* allocators_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* previousCamera_;
    void* canvasBuffer_;
    unsigned char* unknown_1a8_;
    void* itemNames_;
    void* texts_;
    Struct_ov006_021537d0* unknown_1b4_;
    Struct_ov006_021537d0* nextRecipe_;
    int unknown_1bc_;
    Struct_ov006_021555b0* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* layout_;
    void* backgrounds_;
    void* canvases_;
    void* menu_;
    void* item_;
    void* nextItem_;
    void* sprites_;
    char renderer_[0x54];
    Object3D unknown_238_;
    Object3D pot_;
    Object3D unknown_390_;
    Object3D effect_;
    Object3D steam_;
    char unknown_594_[0x38];
    char camera_[0x2c8];
    Struct_ov006_02156e54 ingredients_[4];
    SafeAllocator unknown_a84_[4];
    int task_;
    int unknown_ad8_;
    unsigned char state_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short flags_;
    Struct_ov006_02154614_2 window_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char partNames_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short itemId_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

#include "NitroSDK/Graphics.h"

struct Struct_0210a010_3 {
    char unk_0[0xa0];
    int unknown_a0_;
};
extern Struct_0210a010_3 data_0210a010;

extern "C" void func_020a2010(void* camera);
extern "C" void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
extern "C" void Camera_SetOrbit(void* camera, int x, int y, int z);
extern "C" void Camera_Update(void* camera);
extern "C" void FollowCamera_DisableFollow(void* camera);
extern "C" void func_ov006_021542f4(void* camera);

// USA: func_ov006_02154e58
extern "C" ARM void func_ov006_02154e58(Struct_ov006_02154614* self) {
    if (!(self->flags_ & 0x1000))
        return;
    if ((self->flags_ & (0x40 | 8)) &&
        ((self->flags_ & 8) || (self->window_.flags_ & 4))) {
        if (self->window_.unknown_77d_ != 2)
            return;
        if (!self->window_.unknown_79b_1_)
            return;
    }
    if (self->window_.unknown_77d_ == 2 && self->window_.unknown_79b_1_ && (self->window_.flags_ & 4)) {
        data_0210a010.unknown_a0_ = 0x46501313;
        void* camera = self->camera_;
        BG0CNT = BG0CNT & ~3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3) | 2;
        if (camera != 0) {
            func_020a2010(camera);
            Camera_SetTarget((struct Camera*)self->camera_, 0, -0x1e8f, 0);
            Camera_SetOrbit(self->camera_, 0, 0x2bae, 0x9199);
            Camera_Update(self->camera_);
            FollowCamera_DisableFollow(self->camera_);
        }
        self->unknown_12bd_ = 0;
    } else {
        func_ov006_021542f4(self->camera_);
    }
    self->unknown_238_.Draw(true);
    self->pot_.Draw(true);
    self->unknown_390_.Draw(true);
    self->effect_.Draw(true);
}
