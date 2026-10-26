#include <globaldefs.h>

#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_020dbd9c {
    char unk_0[0x10];
    int state_;
    unsigned char unk_14;
};

struct Struct_ov006_02154614_2 {
    char unk_0[0x774];
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

extern "C" void SePlayer_LoadExtraArchiveB(void* sound, int a, int b);
extern "C" void SePlayer_PlayExtra(void* sound, int a, int b);
extern "C" void SePlayer_UnloadExtraArchiveB(void* sound);

extern char g_sePlayer[];
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
extern "C" ARM void func_ov006_02155068(Struct_ov006_02154614* self) {
    unsigned int* resources = (unsigned int*)(void*)GameState::GetInstance()->GetResources();
    unsigned short flags = self->flags_;
    if (flags & 0x2000) {
        SetFlags04((GameResources*)resources, 0x2000);
        self->steam_.SetAnimationByName(data_ov006_02160080, 9);
        self->steam_.EnableFlag(0x1000);
        return;
    }
    if (flags & 0x80) {
        if (self->unknown_ae1_ == 0) {
            SePlayer_LoadExtraArchiveB(g_sePlayer, 0x7a, 0x7a);
            SePlayer_PlayExtra(g_sePlayer, 0, 0);
            self->pot_.SetAnimationByName(data_ov006_02160080, 1);
            self->effect_.SetAnimationByName(data_ov006_02160087, 1);
            self->steam_.SetAnimationByName(data_ov006_02160080, 9);
            self->steam_.DisableFlag(0x1000);
        } else if (self->unknown_ae1_ >= 1 && self->pot_.HasAnimationStopped()) {
            self->unknown_ae1_ = 0;
            self->flags_ &= ~0x80;
            self->effect_.SetAnimationByName(data_ov006_02160089, 1);
            self->pot_.SetAnimationByName(data_ov006_0216008b, 0);
            self->steam_.StopCurrentAnimation();
            return;
        }
        self->unknown_ae1_++;
        return;
    }
    if (flags & 0x100) {
        if (!self->pot_.HasAnimationReachedEnd())
            return;
        if (self->unknown_ae1_ == 0) {
            self->effect_.SetAnimationByName(data_ov006_02160092, 0);
        } else if (self->unknown_ae1_ == 1) {
            self->effect_.SetAnimationByName(data_ov006_02160094, 1);
        } else if (self->unknown_ae1_ == 2) {
            self->unknown_ae1_ = 0;
            self->pot_.StopCurrentAnimation();
            self->pot_.SetAnimationByName(data_ov006_02160096, 1);
            self->effect_.SetAnimationByName(data_ov006_0216009e, 0);
            self->steam_.SetAnimationByName(data_ov006_02160096, 1);
            self->flags_ &= ~0x100;
            return;
        }
        self->unknown_ae1_++;
        return;
    }
    if (flags & 0x200) {
        self->flags_ = flags | 0x800;
        if (!self->pot_.HasAnimationStopped()) {
            self->unknown_ae1_++;
            return;
        }
        ClearFlags04((GameResources*)resources, 0x2000);
        SePlayer_UnloadExtraArchiveB(g_sePlayer);
        self->unknown_ae1_ = 0;
        self->pot_.SetAnimationByName(data_ov006_021600a0, 1);
        self->effect_.StopCurrentAnimation();
        self->flags_ &= ~0x200;
        return;
    }
    if (flags & 0x400) {
        if (self->pot_.HasAnimationStopped()) {
            self->unknown_ae1_ = 0;
            self->pot_.SetAnimationByName(data_ov006_021600a9, 0);
            self->effect_.StopCurrentAnimation();
            self->flags_ &= ~0x400;
            return;
        }
        self->pot_.SetAnimationByName(data_ov006_021600a0, 1);
        return;
    }
    self->unknown_ae1_ = 0;
    self->pot_.SetAnimationByName(data_ov006_021600a9, 0);
    self->effect_.StopCurrentAnimation();
}
