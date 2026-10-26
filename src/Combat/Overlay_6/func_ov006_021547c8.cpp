#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
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
    char unk_0[R(0x6f0,0x774)];
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

extern "C" void func_ov023_021dc354(Struct_ov006_02154614_2* window);
extern "C" void func_ov006_02156e54(Struct_ov006_02154614* self);
extern "C" void GameState_SetCamera(GameState* gameState, int camera);
extern "C" void func_020dbebc(void* effect);
extern "C" void func_ov006_02154614(Struct_ov006_02154614* self);

// USA: func_ov006_021547c8
extern "C" ARM void func_ov006_021547c8(Struct_ov006_02154614* self) {
    func_ov023_021dc354(&self->window_);
    func_ov006_02156e54(self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0) {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->unknown_ad8_ >= 0) {
        loader->RemoveTask(self->unknown_ad8_);
        self->unknown_ad8_ = -1;
    }
    if (self->unknown_18c_.GetSignedAllocator() != 0)
        self->unknown_18c_.Destroy();
    SafeAllocator* allocators[7] = {0};
    allocators[0] = self->unknown_184_;
    allocators[1] = self->unknown_188_;
    allocators[2] = self->unknown_184_;
    allocators[3] = self->unknown_188_;
    allocators[4] = self->unknown_1280_;
    allocators[5] = self->unknown_1284_;
    for (unsigned char i = 0; allocators[i] != 0; i++) {
        if (allocators[i]->GetSignedAllocator() != 0)
            allocators[i]->Destroy();
    }
    for (unsigned char j = 0; j < 6; j++) {
        if (self->allocators_[j].GetSignedAllocator() != 0)
            self->allocators_[j].Destroy();
    }
    for (unsigned char k = 0; k < 4; k++) {
        if (self->unknown_a84_[k].GetSignedAllocator() != 0)
            self->unknown_a84_[k].Destroy();
    }
    if (self->previousCamera_ != 0) {
        GameState* gameState = GameState::GetInstance();
        GameState_SetCamera(gameState, (int)self->previousCamera_);
        self->previousCamera_ = 0;
    }
    if (!(self->flags_ & 8)) {
        self->unknown_238_.Destroy();
        self->pot_.Destroy();
        self->unknown_390_.Destroy();
        self->effect_.Destroy();
        self->steam_.Destroy();
    }
    func_020dbebc(&self->unknown_12a0_);
    func_ov006_02154614(self);
}
