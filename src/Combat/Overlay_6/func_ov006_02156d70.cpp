#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_02156d70_1908 = 0x6f0 };
#else
enum { Enum_ov006_02156d70_1908 = 0x774 };
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
    char unk_0[Enum_ov006_02156d70_1908];
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

struct Struct_02078398_2;
struct Struct_020dbfa4;

struct Struct_ov006_02156d70 {
    int x;
    int y;
    int z;
};

struct Struct_ov006_02156d70_2 {
    char name_[0x11];
    unsigned char unknown_11_;
    short unk_12;
    char unk_14[0x2c - 0x14];
    Struct_ov006_02156d70 position_;
    char unknown_38_[0x44 - 0x38];
    Struct_ov006_02156d70 scale_;
};

extern "C" void func_020dbdc0(Struct_020dbd9c* effect);
extern "C" void func_02078484(Struct_02078398_2* params);
extern "C" void func_020dbfa4(Struct_020dbfa4* effect, int params);

extern char data_ov006_02160089[];
extern char data_ov006_02160092[];

// USA: func_ov006_02156d70
extern "C" ARM void func_ov006_02156d70(Struct_ov006_02154614* self) {
    func_020dbdc0(&self->unknown_12a0_);
    if (self->unknown_12a0_.unk_14 == 0 && self->unknown_12bc_ != 0) {
        Struct_ov006_02156d70_2 params;
        func_02078484((Struct_02078398_2*)&params);
        params.unknown_11_ &= ~4;
        params.unk_12 = 0;
        if (self->unknown_12bc_ == 1 || self->unknown_12bc_ == 2) {
            strcpy(params.name_, data_ov006_02160089);
            self->unknown_12bc_ = 2;
        } else {
            strcpy(params.name_, data_ov006_02160092);
            self->unknown_12bc_ = 0;
        }
        params.scale_.x = 0x10a;
        params.scale_.y = 0x10a;
        params.scale_.z = 0x10a;
        params.position_.x = -0x41;
        params.position_.y = -0xaac;
        params.position_.z = 0x4526;
        func_020dbfa4((Struct_020dbfa4*)&self->unknown_12a0_, (int)&params);
    }
}
